#ifndef _BUILD_BOT_STATE_H
#define _BUILD_BOT_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    class BuildBotState : public InteractableState
    {
        public:
            BuildBotState();

            void entry(const Event& e);
            void during();
            void exit(const Event& e);

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);
            
            const static std::string sReturnToPrepare;
            const static Action sReturnToPrepareAction;
            
            const static uint32_t sAcceptBuildKey;
            const static Action sAcceptBuildAction;

            const static uint32_t sDenyBuildKey;
            const static Action sDenyBuildAction;
            
            const static uint32_t sLastBuildStepKey;
            const static Action sLastBuildStepAction;

        private:

            enum partsSelection
            {
                FRAME,
                ARMOR,
                WEAPON,
                SPECIALTY,
                DONE
            };

            partsSelection mCurrentSeleciton;
            uint32_t mBotId;
            std::vector<int32_t> mConfiguration;
            BattleBot mTempBot;

            void apply_bot_config(BattleBot* bot);
            void apply_bot_frame(BattleBot* bot);
            void apply_bot_armor(BattleBot* bot);
            void apply_bot_weapon(BattleBot* bot);
            void apply_bot_specialty(BattleBot* bot);

            void reset_configuration();
            void build_bot_from_configuration();
            void set_actions();
    };
}

#endif