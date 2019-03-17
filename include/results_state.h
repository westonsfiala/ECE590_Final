#ifndef _RESULTS_STATE_H
#define _RESULTS_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    class ResultsState : public InteractableState
    {
        public:

            ResultsState();

            void entry(const Event& e);
            void during();       
            void exit(const Event& e);

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);

            void set_bots(std::shared_ptr<BattleBot> bot1, std::shared_ptr<BattleBot> bot2);

            const static std::string sRestart;
            const static Action sRestartAction;

        private:

            std::shared_ptr<BattleBot> mBot1;
            std::shared_ptr<BattleBot> mBot2;
    };
}

#endif