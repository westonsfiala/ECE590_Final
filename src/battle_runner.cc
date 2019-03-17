#include "battle_runner.h"

using namespace bots;

BattleRunner::BattleRunner() : StateMachine("runner")
{
    set_initial(mStartState);
    add_transition(StartState::sPrepareForBattle, mStartState, mPrepareState);
    add_transition(PrepareState::sRestart, mPrepareState, mStartState);
    add_transition(PrepareState::sBattleBegin, mPrepareState, mBattleState);
    add_transition(BattleState::sBattleEnd, mBattleState, mResultsState);
    add_transition(ResultsState::sRestart, mResultsState, mStartState);
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
    return current_interactable().get_action_string();
}

std::vector<std::string> BattleRunner::get_display()
{
    return current_interactable().get_display();
}

