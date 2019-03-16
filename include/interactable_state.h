#ifndef _INTERACTABLE_STATE_H
#define _INTERACTABLE_STATE_H

#include "elma/elma.h"
#include <vector>

using namespace elma;

namespace bots {

    class InteractableState : public State
    {
        public:

            InteractableState(std::string name) : State(name) {}

            virtual std::string get_actions() = 0;
            virtual std::vector<std::string> get_display() = 0;
    };
}

#endif