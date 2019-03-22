#ifndef _START_STATE_H
#define _START_STATE_H

#include "elma/elma.h"
#include "interactable_state.h"
#include "action.h"

using namespace elma;

namespace bots {

    //! State that the Battle Runner starts in. 
    //! Displays a welcome message telling the user what the battle bot simulator is.
    class StartState : public InteractableState
    {
        public:

            //! Constructor
            //! Creates the start state and prepares it to accept user actions.
            StartState();

            //! On entry, destroys all created bots and returns to a fresh state.
            void entry(const Event& e);

            //! Does nothing during execution.
            void during() {}

            //! Does nothing on exit.
            void exit(const Event& e) {}

            //! Getter
            //! \return Title line displayed by the state.
            std::string title();

            //! Getter
            //! \return A welcome message describing what the game is.
            std::vector<std::string> get_display();

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int keyPress);
            
            //! String that is emitted to go to prepare state.
            const static std::string sPrepareForBattle;
            //! Action for going to prepare state.
            const static Action sPrepareForBattleAction;
            
            //! Key representation for 
            const static int sQuitKey;
            //! String that is emitted to quit program.
            const static std::string sQuit;
            //! Action for quitting the program.
            const static Action sQuitAction;
    };
}

#endif