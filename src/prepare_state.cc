#include "prepare_state.h"

using namespace bots;

const std::string PrepareState::sBattleBegin = "BattleBegin";
const std::string PrepareState::sRestart = "Restart";

PrepareState::PrepareState() : InteractableState("Prepare State") 
{
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

std::vector<std::string> PrepareState::get_display()
{
    return {"1", "2", "3"};
}

void PrepareState::act_on_key(int keyPress)
{
    process_key(keyPress);
}