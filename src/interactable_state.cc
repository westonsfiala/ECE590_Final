#include "interactable_state.h"

#include "battle_runner.h"

using namespace bots;

InteractableState::InteractableState(std::string name) : State(name), mActions({})
{
    
}

std::vector<std::string> InteractableState::get_action_strings()
{
    std::vector<std::string> actionStrings;

    for(const auto& action : mActions)
    {
        char trig[2] = {static_cast<char>(action.trigger()), 0};
        std::string trigStr = trig;
        trigStr += ": " + action.name();
        actionStrings.push_back(trigStr);
    }

    return actionStrings;
}

void InteractableState::process_key(int key)
{
    for(const auto& action : mActions)
    {
        if(action.trigger() == key)
        {
            emit(Event(action.emit()));
        }
    }
}

BattleRunner& InteractableState::battle_runner() 
{ 
    return static_cast<BattleRunner&>(state_machine()); 
}