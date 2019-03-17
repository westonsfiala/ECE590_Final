#include "start_state.h"

using namespace bots;

const int StartState::sPrepareKey = 'p';
const std::string StartState::sPrepareForBattle = "PrepareForBattle";

StartState::StartState() : InteractableState("Start State") 
{
    Action prepareForBattle("Prepare For Battle", sPrepareKey, sPrepareForBattle);
    mActions.push_back(prepareForBattle);
}

void StartState::entry(const Event& e)
{

}

void StartState::during()
{
}      

void StartState::exit(const Event& e)
{

}

std::vector<std::string> StartState::get_display()
{
    return {"1", "2", "3"};
}

void StartState::act_on_key(int keyPress)
{
    process_key(keyPress);
}