#ifndef _BATTLE_STATE_H
#define _BATTLE_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    class BattleState : public InteractableState
    {
        public:

            BattleState();

            void entry(const Event& e);
            void during();   
            void exit(const Event& e);

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);

            const static std::string sBattleEnd;
            const static Action sBattleEndAction;

        private:
    };
}

#endif