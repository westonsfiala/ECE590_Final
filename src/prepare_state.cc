#include "prepare_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string PrepareState::sBattleBegin = "BattleBegin";
const Action PrepareState::sBattleBeginAction = Action("Start Battle", 'b', sBattleBegin);

const std::string PrepareState::sRestart = "Restart";
const Action PrepareState::sRestartAction = Action("Return to Start", 'r', sRestart);

const std::string PrepareState::sCreateBot = "Create Bot";
const std::string PrepareState::sDestroyBot = "Destroy Bot";

const static int BOT1_KEY = '1';
const static std::string BOT1_KEY_STR = "1";
const Action PrepareState::sCreateBot1Action = Action(sCreateBot + BOT1_KEY_STR, BOT1_KEY, "");
const Action PrepareState::sDestroyBot1Action = Action(sCreateBot + BOT1_KEY_STR, BOT1_KEY, "");

const static int BOT2_KEY = '2';
const static std::string BOT2_KEY_STR = "2";
const Action PrepareState::sCreateBot2Action = Action(sDestroyBot + BOT2_KEY_STR, BOT2_KEY, "");
const Action PrepareState::sDestroyBot2Action = Action(sDestroyBot + BOT2_KEY_STR, BOT2_KEY, "");


PrepareState::PrepareState() : InteractableState("Prepare State") 
{
    
}

void PrepareState::entry(const Event& e)
{
    set_actions();
}

void PrepareState::during()
{

}      

void PrepareState::exit(const Event& e)
{

}

std::string PrepareState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> PrepareState::get_display()
{


    return {};
}

void PrepareState::act_on_key(int keyPress)
{
    // Create/Destroy bot1
    if(keyPress == BOT1_KEY)
    {
        if(battle_runner().get_bot(1) == nullptr)
        {
            battle_runner().create_bot(1);
        }
        else
        {
            battle_runner().destroy_bot(1);
        }
        set_actions();
        return;
    }

    // Create/Destroy bot2
    if(keyPress == BOT2_KEY)
    {
        if(battle_runner().get_bot(2) == nullptr)
        {
            battle_runner().create_bot(2);
        }
        else
        {
            battle_runner().destroy_bot(2);
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

    bool hasBot1 = battle_runner().get_bot(1) != nullptr;
    bool hasBot2 = battle_runner().get_bot(2) != nullptr;

    if(hasBot1 && hasBot2)
    {
        mActions.push_back(sBattleBeginAction);
    }

    if(hasBot1)
    {
        mActions.push_back(sDestroyBot1Action);
    }
    else
    {
        mActions.push_back(sCreateBot1Action);
    }
    
    if(hasBot2)
    {
        mActions.push_back(sDestroyBot2Action);
    }
    else
    {
        mActions.push_back(sCreateBot2Action);
    }
}