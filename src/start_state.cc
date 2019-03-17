#include "start_state.h"

using namespace bots;

const std::string StartState::sPrepareForBattleDisplay = "Prepare For Battle";
const int StartState::sPrepareForBattleKey = 'p';
const std::string StartState::sPrepareForBattle = "PrepareForBattle";

StartState::StartState() : InteractableState("Start State") 
{
    Action prepareForBattle(sPrepareForBattleDisplay, sPrepareForBattleKey, sPrepareForBattle);
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
    return {};
}

void StartState::act_on_key(int keyPress)
{
    process_key(keyPress);
}