#ifndef _BATTLE_RUNNER_H
#define _BATTLE_RUNNER_H

#include "elma/elma.h"
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

            InteractableState& current_interactable();

            std::string get_state_title();
            std::string get_action_string();
            std::vector<std::string> get_display();

        private:
            StartState mStartState;
            PrepareState mPrepareState;
            BattleState mBattleState;
            ResultsState mResultsState;
    };
}

#endif