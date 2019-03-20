#ifndef _INTERACTABLE_STATE_H
#define _INTERACTABLE_STATE_H

#include "elma/elma.h"
#include "action.h"
#include <vector>

using namespace elma;

namespace bots {
    
    class BattleRunner;

    class InteractableState : public State
    {
        public:

            InteractableState(std::string name);

            std::vector<std::string> get_action_strings();

            virtual std::string title() = 0;
            virtual std::vector<std::string> get_display() = 0;
            virtual void act_on_key(int keyPress) = 0;

        protected:

            std::vector<Action> mActions;

            void process_key(int keyPress);

            BattleRunner& battle_runner();
    };
}

#endif