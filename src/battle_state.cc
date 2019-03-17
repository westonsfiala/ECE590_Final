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
    battle_runner().schedule(mBot1,battle_runner().period());
    battle_runner().schedule(mBot2,battle_runner().period());
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

void BattleState::set_bots(std::shared_ptr<BattleBot> bot1, std::shared_ptr<BattleBot> bot2) 
{
    mBot1 = bot1;
    mBot2 = bot2;
}