#ifndef _RESULTS_STATE_H
#define _RESULTS_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"

using namespace elma;

namespace bots {

    class ResultsState : public InteractableState
    {
        public:

            ResultsState() : InteractableState("Results State") {}

            void entry(const Event& e) {};
            void during() {};       
            void exit(const Event& e) {};

            std::string get_actions() {return "";};
            std::vector<std::string> get_display() {return {};};

        private:
    };
}

#endif