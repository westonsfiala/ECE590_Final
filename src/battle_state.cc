#include "battle_state.h"

using namespace bots;

const std::string BattleState::sBattleEnd = "BattleEnd";
const Action BattleState::sBattleEndAction = Action("Abort Battle", 'a', sBattleEnd);

BattleState::BattleState() : InteractableState("Battle State") 
{
    mActions.push_back(sBattleEndAction);
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