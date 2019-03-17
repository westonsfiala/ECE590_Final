#include "interactable_state.h"

using namespace bots;

InteractableState::InteractableState(std::string name) : State(name), mActions({})
{
    
}

std::string InteractableState::get_action_string()
{
    std::string actionString = "";

    for(const auto& action : mActions)
    {
        char trig[2] = {static_cast<char>(action.trigger()), 0};
        std::string trigStr = trig;
        actionString += trigStr + ": " + action.name() + ", ";
    }

    if(!actionString.empty())
    {
        actionString.pop_back();
        actionString.pop_back();
    }

    return actionString;
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