#ifndef _BATTLE_RUNNER_H
#define _BATTLE_RUNNER_H

#include <memory>
#include <random>
#include <deque>

#include "elma/elma.h"

#include "battlebot.h"

#include "start_state.h"
#include "prepare_state.h"
#include "battle_state.h"
#include "results_state.h"

using namespace elma;

namespace bots
{
    class BattleRunner : public StateMachine
    {
        public:
            BattleRunner();
            ~BattleRunner() = default;

            void setup(Manager& man);

            InteractableState& current_interactable();

            std::string get_state_title();
            std::string get_action_string();
            std::vector<std::string> get_display();

            std::vector<std::string> get_recent_log(uint32_t logs);
            const std::vector<std::string>& get_full_log();

            int32_t roll(uint32_t dice, int32_t modifier);

            inline std::shared_ptr<BattleBot> get_bot1() { return mBot1; }
            inline std::shared_ptr<BattleBot> get_bot2() { return mBot2; }

            const static std::string sLogEvent;
            const static std::string sLogClearEvent;

        private:
            StartState mStartState;
            PrepareState mPrepareState;
            BattleState mBattleState;
            ResultsState mResultsState;

            std::shared_ptr<BattleBot> mBot1;
            std::shared_ptr<BattleBot> mBot2;

            std::random_device mRd;

            std::vector<std::string> mLog;

    };
}

#endif