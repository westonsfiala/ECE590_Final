#include "results_state.h"

using namespace bots;

const std::string ResultsState::sRestartDisplay = "Return to Start";
const int ResultsState::sRestartKey = 'r';
const std::string ResultsState::sRestart = "Restart";

ResultsState::ResultsState() : InteractableState("Results State") 
{
    Action returnToStart(sRestartDisplay, sRestartKey, sRestart);
    mActions.push_back(returnToStart);
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