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

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);
            
            const static std::string sPrepareForBattleDisplay;
            const static int sPrepareForBattleKey;
            const static std::string sPrepareForBattle;
            
            const static std::string sQuitDisplay;
            const static int sQuitKey;
            const static std::string sQuit;
    };
}

#endif