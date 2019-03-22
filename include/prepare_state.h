#ifndef _PREPARE_STATE_H
#define _PREPARE_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    //! State that the user prepares bots for battle in.
    class PrepareState : public InteractableState
    {
        public:

            //! Constructor
            //! Creates the results state and prepares it to accept user actions.
            PrepareState();

            //! On entry, determines if the battle can be started.
            void entry(const Event& e);

            //! Does nothing during execution.
            void during() {}

            //! Does nothing on exit.
            void exit(const Event& e) {}

            //! Getter
            //! \return Title line displayed by the state.
            std::string title();

            //! Getter
            //! \return Displays the loadout of all the created bots.
            std::vector<std::string> get_display();

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int keyPress);
            
            //! String that is emitted to start the battle.
            const static std::string sBattleBegin;
            //! Action for starting the battle.
            const static Action sBattleBeginAction;

            //! String that is emitted to return to start.
            const static std::string sRestart;
            //! Action for returning to start.
            const static Action sRestartAction;

            //! String that is emitted to create a bot.
            const static std::string sCreateBot;
            //! String that is emitted to destroy a bot.
            const static std::string sDestroyBot;

        private:

            //! Sets the action that the user can take.
            //! Create bots if none are there, and delete created bots.
            //! When the minimum required bots are created, can start battle.
            void set_actions();
    };
}

#endif