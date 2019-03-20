#include "results_state.h"
#include "battle_runner.h"

using namespace bots;

const std::string ResultsState::sRestart = "Restart";
const Action ResultsState::sRestartAction = Action("Return to Start", 'r', sRestart);

ResultsState::ResultsState() : InteractableState("Results State") 
{
    mActions.push_back(sRestartAction);

}

void ResultsState::entry(const Event& e)
{
    battle_runner().log("Entering " + name());
    
    mDisplay.clear();

    auto bots = battle_runner().get_valid_bots();

    auto victor = winner(bots);

    mDisplay.push_back("{" + victor->name() + " is the victor! Congrats! }");
    mDisplay.push_back("");

    for(auto bot : bots)
    {
        mDisplay.push_back(bot->get_battle_stats());
    }
}

void ResultsState::during()
{

}      

void ResultsState::exit(const Event& e)
{

}

std::string ResultsState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> ResultsState::get_display()
{
    return mDisplay;
}

void ResultsState::act_on_key(int keyPress)
{
    process_key(keyPress);
}


BattleBot* ResultsState::winner(std::vector<BattleBot*> bots)
{
    for(auto bot : bots)
    {
        if(bot != nullptr && !bot->is_dead())
        {
            return bot;
        }
    }
    return nullptr;
}