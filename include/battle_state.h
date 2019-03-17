#ifndef _BATTLE_STATE_H
#define _BATTLE_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"

using namespace elma;

namespace bots {

    class BattleState : public InteractableState
    {
        public:

            BattleState();

            void entry(const Event& e);
            void during();   
            void exit(const Event& e);

            std::vector<std::string> get_display();
            void act_on_key(int keyPress);

            const static std::string sBattleEndDisplay;
            const static int sBattleEndKey;
            const static std::string sBattleEnd;

        private:
    };
}

#endif