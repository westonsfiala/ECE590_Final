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

            std::string get_state_name();
            std::string get_actions();

            const static std::string sPrepareForBattle;
            const static std::string sRestart;
            const static std::string sBattleBegin;
            const static std::string sBattleEnd;

        private:
            StartState mStartState;
            PrepareState mPrepareState;
            BattleState mBattleState;
            ResultsState mResultsState;
    };
}

#endif