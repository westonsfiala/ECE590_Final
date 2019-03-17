#include "battle_runner.h"

using namespace bots;

const std::string BattleRunner::sRestart = "Restart";
const std::string BattleRunner::sBattleBegin = "BattleBegin";
const std::string BattleRunner::sBattleEnd = "BattleEnd";

BattleRunner::BattleRunner() : StateMachine("runner")
{
    set_initial(mStartState);
    add_transition(StartState::sPrepareForBattle, mStartState, mPrepareState);
    add_transition(sRestart, mPrepareState, mStartState);
    add_transition(sBattleBegin, mPrepareState, mBattleState);
    add_transition(sBattleEnd, mBattleState, mResultsState);
    add_transition(sRestart, mResultsState, mStartState);
}

InteractableState& BattleRunner::current_interactable()
{
    return static_cast<InteractableState&>(current());
}

std::string BattleRunner::get_state_name()
{
    return current_interactable().name();
}

std::string BattleRunner::get_actions()
{
    return current_interactable().get_actions();
}

std::vector<std::string> BattleRunner::get_display()
{
    return current_interactable().get_display();
}

