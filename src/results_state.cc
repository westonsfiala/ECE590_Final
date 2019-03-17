#include "results_state.h"

using namespace bots;

const std::string ResultsState::sRestart = "Restart";

ResultsState::ResultsState() : InteractableState("Results State") 
{
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

std::vector<std::string> ResultsState::get_display()
{
    return {"1", "2", "3"};
}

void ResultsState::act_on_key(int keyPress)
{
    process_key(keyPress);
}