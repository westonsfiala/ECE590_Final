#ifndef _RESULTS_STATE_H
#define _RESULTS_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"

using namespace elma;

namespace bots {

    class ResultsState : public InteractableState
    {
        public:

            ResultsState();

            void entry(const Event& e);
            void during();       
            void exit(const Event& e);

            std::vector<std::string> get_display();
            void act_on_key(int keyPress);

            const static std::string sRestart;

        private:
    };
}

#endif