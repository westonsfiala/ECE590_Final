#include "battle_state.h"

using namespace bots;

const std::string BattleState::sBattleEndDisplay = "Abort Battle";
const int BattleState::sBattleEndKey = 'a';
const std::string BattleState::sBattleEnd = "BattleEnd";

BattleState::BattleState() : InteractableState("Battle State") 
{
    Action abortBattle(sBattleEndDisplay, sBattleEndKey, sBattleEnd);
    mActions.push_back(abortBattle);
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

std::string BattleState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> BattleState::get_display()
{
    return {};
}

void BattleState::act_on_key(int keyPress)
{
    process_key(keyPress);
}