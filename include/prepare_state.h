#ifndef _PREPARE_STATE_H
#define _PREPARE_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

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
            
            const static std::string sBattleBegin;
            const static Action sBattleBeginAction;

            const static std::string sRestart;
            const static Action sRestartAction;

            const static std::string sCreateBot;
            const static std::string sDestroyBot;
            
            const static Action sCreateBot1Action;
            const static Action sCreateBot2Action;
            const static Action sDestroyBot1Action;
            const static Action sDestroyBot2Action;

        private:

            void set_actions();
    };
}

#endif