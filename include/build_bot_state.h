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
            ~BuildBotState();

            void entry(const Event& e);
            void during();
            void exit(const Event& e);

            std::string title();
            std::vector<std::string> get_display();
            void act_on_key(int keyPress);
            
            const static std::string sReturnToPrepare;
            const static Action sReturnToPrepareAction;
            
            const static uint32_t sRandomBotKey;
            const static Action sRandomBotAction;
            
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

            BattleBot mTempBot;

            void build_actions();

            std::vector<Action> mFrameActions;
            std::vector<Action> mArmorActions;
            std::vector<Action> mWeaponActions;
            std::vector<Action> mSpecialtyActions;

            void reset_configuration();
            void build_bot_from_configuration();
            void set_actions();
    };
}

#endif