#ifndef _BATTLE_STATE_H
#define _BATTLE_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    //! State that runs the battle between all created battle bots.
    class BattleState : public InteractableState
    {
        public:

            //! Constructor
            BattleState();

            //! On entry gets all valid bots from the battle runner and prepares them for battle.
            void entry(const Event& e);

            //! During execution, loop through bots and have one attack per execution.
            void during();   

            //! On exit, clear away all tracked bots.
            void exit(const Event& e);

            //! Getter
            //! \return Title line displayed by the state.
            std::string title();

            //! Getter
            //! \return Displays the current battle stats of all bots followed bt a log of the battle.
            std::vector<std::string> get_display();

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int keyPress);

            //! String that is emitted to end the battle.
            const static std::string sBattleEnd;
            //! Action to abort the battle.
            const static Action sBattleEndAction;
            //! Action to procede to results after battle conclusion.
            const static Action sGoToResultsAction;

        private:

            //! Getter
            //! \return Number of bots still alive.
            uint32_t num_living_bots();

            //! Sets the actions that the use can take.
            //! Either abort the battle while it is going,
            //! or procede to the results stage when the battle has finished.
            void set_actions();

            std::vector<BattleBot*> mBots;
    };
}

#endif