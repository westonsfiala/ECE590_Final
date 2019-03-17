#include "results_state.h"

using namespace bots;

const std::string ResultsState::sRestart = "Restart";
const Action ResultsState::sRestartAction = Action("Return to Start", 'r', sRestart);

ResultsState::ResultsState() : InteractableState("Results State") 
{
    mActions.push_back(sRestartAction);
}

void ResultsState::entry(const Event& e)
{

}

void ResultsState::during()
{
    

}      

void ResultsState::exit(const Event& e)
{

}

std::string ResultsState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> ResultsState::get_display()
{
    return {};
}

void ResultsState::act_on_key(int keyPress)
{
    process_key(keyPress);
}

void ResultsState::set_bots(std::shared_ptr<BattleBot> bot1, std::shared_ptr<BattleBot> bot2) 
{
    mBot1 = bot1;
    mBot2 = bot2;
}