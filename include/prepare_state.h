#ifndef _PREPARE_STATE_H
#define _PREPARE_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"

using namespace elma;

namespace bots {

    class PrepareState : public InteractableState
    {
        public:

            PrepareState() : InteractableState("Prepare State") {}

            void entry(const Event& e) {};
            void during() {};       
            void exit(const Event& e) {};

            std::string get_actions() {return "";};
            std::vector<std::string> get_display() {return {};};

        private:
    };
}

#endif