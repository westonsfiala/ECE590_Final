#include "prepare_state.h"

using namespace bots;

const std::string PrepareState::sBattleBegin = "BattleBegin";
const Action PrepareState::sBattleBeginAction = Action("Start Battle", 'b', sBattleBegin);

const std::string PrepareState::sRestart = "Restart";
const Action PrepareState::sRestartAction = Action("Return to Start", 'r', sRestart);

PrepareState::PrepareState() : InteractableState("Prepare State") 
{
    mActions.push_back(sBattleBeginAction);
    mActions.push_back(sRestartAction);
}

void PrepareState::entry(const Event& e)
{

}

void PrepareState::during()
{
    

}      

void PrepareState::exit(const Event& e)
{

}

std::string PrepareState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> PrepareState::get_display()
{
    return {};
}

void PrepareState::act_on_key(int keyPress)
{
    process_key(keyPress);
}