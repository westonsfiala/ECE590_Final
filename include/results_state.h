#ifndef _RESULTS_STATE_H
#define _RESULTS_STATE_H

#include <memory>

#include "elma/elma.h"
#include "interactable_state.h"
#include "battlebot.h"

using namespace elma;

namespace bots {

    //! State that the displays the results of a completed battle. 
    class ResultsState : public InteractableState
    {
        public:

            //! Constructor
            //! Creates the results state and prepares it to accept user actions.
            ResultsState();

            //! On entry, determines if the battle resulted in a winner or not.
            //! Display changes based on if ther was a winner.
            void entry(const Event& e);

            //! Does nothing during execution.
            void during() {}

            //! Does nothing on exit.
            void exit(const Event& e) {}

            //! Getter
            //! \return Title line displayed by the state.
            std::string title();

            //! Getter
            //! \return Displays the winner, if applicable, and battle stats of all bots.
            std::vector<std::string> get_display();

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int keyPress);

            //! String that is emitted to go to start state.
            const static std::string sRestart;
            //! Action for going to start state.
            const static Action sRestartAction;

        private:

            //! Determines if a single bot survived, making it the winner.
            //! \param bots BattleBots to check for a winner.
            //! \return If there is a winner.
            bool has_winner(const std::vector<BattleBot*>& bots);

            //! Returns the winner of the given bots.
            //! \param bots BattleBots to get the winner from.
            //! \return BattleBot that won. If no winner, returns nullptr.
            BattleBot* winner(const std::vector<BattleBot*>& bots);

            std::vector<std::string> mDisplay;
    };
}

#endif