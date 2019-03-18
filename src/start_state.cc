#include "start_state.h"
#include "battle_runner.h"

using namespace bots;

const std::string StartState::sPrepareForBattle = "PrepareForBattle";
const Action StartState::sPrepareForBattleAction = Action("Prepare For Battle", 'p', sPrepareForBattle);

const int StartState::sQuitKey = 'q';
const std::string StartState::sQuit = "Quit";
const Action StartState::sQuitAction = Action(sQuit, sQuitKey, sQuit);

const std::string StartState::sDestroyAllBots = "DestroyAllBots";

StartState::StartState() : InteractableState("Start State") 
{
    mActions.push_back(sQuitAction);
    mActions.push_back(sPrepareForBattleAction);
}

void StartState::entry(const Event& e)
{
    battle_runner().clear_log();
    battle_runner().destroy_all_bots();
}

void StartState::during()
{
}      

void StartState::exit(const Event& e)
{

}

std::string StartState::title()
{
    auto title = std::string("Welcome to the ") + name();
    return title;
}

std::vector<std::string> StartState::get_display()
{
    std::vector<std::string> display;

    display.push_back("Welcome to the battle bot simulator.");
    display.push_back("");
    display.push_back("In this game you will build a battle bot and face off against opponents.");
    display.push_back("The game consists of 3 phases: preperation, battle, and results.");
    display.push_back("");
    display.push_back("To advance the the preperation phase, press one of the action keys above.");
    display.push_back("");
    display.push_back("Hope you enjoy it!");
    return display;
}

void StartState::act_on_key(int keyPress)
{

    if(keyPress == sQuitKey)
    {
        state_machine().halt();
        return;
    }

    process_key(keyPress);
}