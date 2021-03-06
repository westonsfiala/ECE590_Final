#include "prepare_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string PrepareState::sBattleBegin = "BattleBegin";
const Action PrepareState::sBattleBeginAction = Action("Start Battle", 'b', sBattleBegin);

const std::string PrepareState::sRestart = "Restart";
const Action PrepareState::sRestartAction = Action("Return to Start", 'r', sRestart);

const std::string PrepareState::sCreateBot = "Create Bot";
const std::string PrepareState::sDestroyBot = "Destroy Bot";

const static int ASCII_1 = 49;


PrepareState::PrepareState() : InteractableState("Prepare State") 
{
}

void PrepareState::entry(const Event& e)
{
    battle_runner().log("Entering " + name());
    set_actions();
}

std::string PrepareState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> PrepareState::get_display()
{
    std::vector<std::string> display;

    display.push_back("Prepare bots by selection the actions above.");
    display.push_back("All created bots will be displayed below.");
    display.push_back("");
    auto bots = battle_runner().get_valid_bots();
    for(auto bot : bots)
    {
        display.push_back(bot->name() + ": " + bot->get_simple_loadout());
    }
    return display;
}

void PrepareState::act_on_key(int keyPress)
{
    auto botKey = keyPress - ASCII_1;

    if(botKey >= 0 && botKey <= BattleRunner::sMaxBots)
    {
        if(battle_runner().get_bot(botKey) == nullptr)
        {
            emit(Event(sCreateBot, botKey));
            return;
        }
        else
        {
            battle_runner().destroy_bot(botKey);
        }
        set_actions();
        return;
    }

    process_key(keyPress);
}

void PrepareState::set_actions()
{
    mActions.clear();

    mActions.push_back(sRestartAction);

    if(battle_runner().get_num_bots() >= BattleRunner::sMinBots)
    {
        mActions.push_back(sBattleBeginAction);
    }

    for(auto i = 0; i < BattleRunner::sMaxBots; ++i)
    {
        auto bot = battle_runner().get_bot(i);
        // Bots are 1 indexed, and we want to show the actual number that is typed instead of some nullesque character.
        auto actionKey = i+ASCII_1;
        if(bot == nullptr)
        {
            Action createAction(sCreateBot, actionKey, "");
            mActions.push_back(createAction);
        }
        else
        {
            Action createAction(sDestroyBot, actionKey, "");
            mActions.push_back(createAction);
        }
    }
}