#ifndef _BATTLE_RUNNER_H
#define _BATTLE_RUNNER_H

#include <random>
#include <array>

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
            ~BattleRunner();

            InteractableState& current_interactable();

            std::string get_state_title();
            std::string get_action_string();
            std::vector<std::string> get_display();

            std::vector<std::string> get_recent_log(uint32_t logs);
            const std::vector<std::string>& get_full_log();

            int32_t roll(uint32_t dice, int32_t modifier);

            void log(const std::string& text);
            void clear_log();
            BattleBot* get_bot(uint32_t botId);
            uint32_t get_num_bots();
            void create_bot(uint32_t botId);
            void destroy_bot(uint32_t botId);
            void destroy_all_bots();

            const static uint32_t sMaxBots;
            const static uint32_t sMinBots;

        private:
            StartState mStartState;
            PrepareState mPrepareState;
            BattleState mBattleState;
            ResultsState mResultsState;

            std::vector<BattleBot*> mBots;

            std::random_device mRd;

            std::vector<std::string> mLog;

    };
}

#endif