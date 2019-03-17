#include "prepare_state.h"

using namespace bots;

const std::string PrepareState::sBattleBeginDisplay = "Start Battle";
const int PrepareState::sBattleBeginKey = 'b';
const std::string PrepareState::sBattleBegin = "BattleBegin";

const std::string PrepareState::sRestartDisplay = "Return to Start";
const int PrepareState::sRestartKey = 'r';
const std::string PrepareState::sRestart = "Restart";

PrepareState::PrepareState() : InteractableState("Prepare State") 
{
    Action startBattle(sBattleBeginDisplay, sBattleBeginKey, sBattleBegin);
    mActions.push_back(startBattle);

    Action returnToStart(sRestartDisplay, sRestartKey, sRestart);
    mActions.push_back(returnToStart);
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