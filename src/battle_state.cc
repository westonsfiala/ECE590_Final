#include "battle_state.h"

using namespace bots;

const std::string BattleState::sBattleEnd = "BattleEnd";

BattleState::BattleState() : InteractableState("Battle State") 
{
}

void BattleState::entry(const Event& e)
{

}

void BattleState::during()
{
    

}      

void BattleState::exit(const Event& e)
{

}

std::vector<std::string> BattleState::get_display()
{
    return {"1", "2", "3"};
}

void BattleState::act_on_key(int keyPress)
{
    process_key(keyPress);
}