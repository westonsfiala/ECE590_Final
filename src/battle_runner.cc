#include "battle_runner.h"

using namespace bots;

const std::string BattleRunner::sPrepareForBattle = "PrepareForBattle";
const std::string BattleRunner::sRestart = "Restart";
const std::string BattleRunner::sBattleBegin = "BattleBegin";
const std::string BattleRunner::sBattleEnd = "BattleEnd";

BattleRunner::BattleRunner() : StateMachine("runner")
{
    set_initial(mStartState);
    add_transition(sPrepareForBattle, mStartState, mPrepareState);
    add_transition(sRestart, mPrepareState, mStartState);
    add_transition(sBattleBegin, mPrepareState, mBattleState);
    add_transition(sBattleEnd, mBattleState, mResultsState);
    add_transition(sRestart, mResultsState, mStartState);
}

std::string BattleRunner::get_state_name()
{
    return current().name();
}

std::string BattleRunner::get_actions()
{
    return "";
    //return current().get_actions();
}