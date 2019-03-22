#ifndef _BUILD_BOT_STATE_H
#define _BUILD_BOT_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    //! State for getting a battlebot equiped for battle
    class BuildBotState : public InteractableState
    {
        public:

            //! Constructor
            //! Creates the build a bot state.
            BuildBotState();

            //! On entry sets all the actions and waits for user input.
            void entry(const Event& e);

            //! Does nothing during execution.
            void during() {}

            //! Does nothing on exit.
            void exit(const Event& e) {}

            //! Getter
            //! \return Title line displayed by the state.
            std::string title();

            //! Getter
            //! \return Displays the current stats of the bot and its full loadout.
            std::vector<std::string> get_display();
            

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int keyPress);
            
            //! String that is emitted to go to prepare state.
            const static std::string sReturnToPrepare;
            //! Action for going to prepare state.
            const static Action sReturnToPrepareAction;
            
            //! Int that is used to build a random bot.
            const static uint32_t sRandomBotKey;
            //! Action for building a random bot.
            const static Action sRandomBotAction;
            
            //! Int that is used to accept bot build.
            const static uint32_t sAcceptBuildKey;
            //! Action for accepting bot build.
            const static Action sAcceptBuildAction;

            //! Int that is used to deny bot build.
            const static uint32_t sDenyBuildKey;
            //! Action for denying bot build.
            const static Action sDenyBuildAction;
            
            //! Int that is used to return to the last item selection.
            const static uint32_t sLastBuildStepKey;
            //! Action for returning to the last item selection.
            const static Action sLastBuildStepAction;

        private:

            //! Enum for tracking what state the build is in.
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

            //! Builds all of the actions that can be taken by getting them from a battlebot.
            void build_actions();

            std::vector<Action> mFrameActions;
            std::vector<Action> mArmorActions;
            std::vector<Action> mWeaponActions;
            std::vector<Action> mSpecialtyActions;

            //! Resets the configuration of the bot to no tiems equiped.
            void reset_configuration();

            //! Takes the current loadout of the bot and saves it to the battle runner.
            void build_bot_from_configuration();

            //! Sets the allowed actions based on the current state of the bot build.
            void set_actions();
    };
}

#endif