#ifndef _PREPARE_STATE_H
#define _PREPARE_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"

using namespace elma;

namespace bots {

    class PrepareState : public InteractableState
    {
        public:

            PrepareState();

            void entry(const Event& e);
            void during();
            void exit(const Event& e);

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);
            
            const static std::string sBattleBeginDisplay;
            const static int sBattleBeginKey;
            const static std::string sBattleBegin;

            const static std::string sRestartDisplay;
            const static int sRestartKey;
            const static std::string sRestart;
        private:
    };
}

#endif