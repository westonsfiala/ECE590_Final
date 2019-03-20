#include "battle_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string BattleState::sBattleEnd = "BattleEnd";
const Action BattleState::sBattleEndAction = Action("Abort Battle", 'a', sBattleEnd);
const Action BattleState::sGoToResultsAction = Action("Procede to Results", 'p', sBattleEnd);

BattleState::BattleState() : InteractableState("Battle State") 
{
}

void BattleState::entry(const Event& e)
{
    set_actions();
    battle_runner().log("Entering " + name());
    mBots = battle_runner().get_valid_bots();
    for(auto bot : mBots)
    {
        bot->start_battle();
    }
}

void BattleState::during()
{
    if(num_living_bots() > 1)
    {
        auto triggerBot = battle_runner().num_updates() % mBots.size();
        mBots[triggerBot]->trigger();
    }
    set_actions();
}      

void BattleState::exit(const Event& e)
{
    for(auto& bot : mBots)
    {
        bot->end_battle();
    }
    mBots.clear();
}

std::string BattleState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> BattleState::get_display()
{
    std::vector<std::string> battleDisplay;

    for(auto bot : mBots)
    {
        battleDisplay.push_back(bot->display());
    }
    
    battleDisplay.push_back("");
    for(const auto& battleLog : battle_runner().get_recent_log(mBots.size() * 2))
    {
        battleDisplay.push_back(battleLog);
    }

    return battleDisplay;
}

void BattleState::act_on_key(int keyPress)
{
    process_key(keyPress);
}

uint32_t BattleState::num_living_bots()
{
    auto living = 0;
    for(auto bot : mBots)
    {
        if(!bot->is_dead())
        {
            living++;
        }
    }
    return living;
}

void BattleState::set_actions()
{
    mActions.clear();
    if(num_living_bots() < 2)
    {
        mActions.push_back(sGoToResultsAction);
    }
    else
    {
        mActions.push_back(sBattleEndAction);
    }
}