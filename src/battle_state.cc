#include "battle_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string BattleState::sBattleEnd = "BattleEnd";
const Action BattleState::sBattleEndAction = Action("Abort Battle", 'a', sBattleEnd);

BattleState::BattleState() : InteractableState("Battle State") 
{
    mActions.push_back(sBattleEndAction);
}

void BattleState::entry(const Event& e)
{
    battle_runner().log("Entering " + name());
    mBots = battle_runner().get_valid_bots();
    for(auto& bot : mBots)
    {
        bot->start_battle();
    }
}

void BattleState::during()
{
    auto triggerBot = battle_runner().num_updates() % mBots.size();
    mBots[triggerBot]->trigger();
}      

void BattleState::exit(const Event& e)
{
    for(auto& bot : mBots)
    {
        bot->end_battle();
    }
}

std::string BattleState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> BattleState::get_display()
{
    return battle_runner().get_recent_log(10);
}

void BattleState::act_on_key(int keyPress)
{
    process_key(keyPress);
}