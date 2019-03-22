#ifndef _INTERACTABLE_STATE_H
#define _INTERACTABLE_STATE_H

#include "elma/elma.h"
#include "action.h"
#include <vector>

using namespace elma;

namespace bots {
    
    class BattleRunner;

    //! State class with the extention of adding titles, displays, and ability to act on keys.
    class InteractableState : public State
    {
        public:

            //! Constructor
            //! \param name Name of the state.
            InteractableState(std::string name);

            //! Getter
            //! \return All of the action keys and their descriptive names.
            std::vector<std::string> get_action_strings();

            //! Getter
            //! \return All of the action key values.
            std::vector<int32_t> get_action_keys();

            //! Getter
            //! \return Title line displayed by the state.
            virtual std::string title() = 0;

            //! Getter
            //! \return A welcome message describing what the game is.
            virtual std::vector<std::string> get_display() = 0;
            
            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            virtual void act_on_key(int keyPress) = 0;

        protected:

            std::vector<Action> mActions;

            //! Goes through all of the registered actions to see if it should trigger any of them.
            //! \param keyPress Value to possibly trigger actions.
            void process_key(int keyPress);

            //! Getter
            //! \return BattleRunner that this state is a part of.
            BattleRunner& battle_runner();
    };
}

#endif