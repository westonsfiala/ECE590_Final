#include "start_state.h"

using namespace bots;

const int StartState::sPrepareKey = 'p';
const std::string StartState::sPrepareForBattle = "PrepareForBattle";

StartState::StartState() : InteractableState("Start State") 
{
    
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

std::string StartState::get_actions()
{
    return "p: Go to Prepare";
}

std::vector<std::string> StartState::get_display()
{
    return {"1", "2", "3"};
}

void StartState::act_on_key(int key)
{
    if(key == sPrepareKey)
    {
        emit(Event(sPrepareForBattle));
    }
}