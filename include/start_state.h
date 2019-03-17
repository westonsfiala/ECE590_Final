#ifndef _START_STATE_H
#define _START_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"
#include "action.h"

using namespace elma;

namespace bots {

    class StartState : public InteractableState
    {
        public:

            StartState();

            void entry(const Event& e);
            void during();       
            void exit(const Event& e);

            std::string get_actions();
            std::vector<std::string> get_display();
            void act_on_key(int key);
            
            const static int sPrepareKey;
            const static std::string sPrepareForBattle;

        private:

            std::vector<Action> mAction;
    };
}

#endif