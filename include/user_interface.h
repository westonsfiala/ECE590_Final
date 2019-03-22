#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include "battle_runner.h"

using namespace elma;

namespace bots {

    //! Generates a user interface that is displayed to the screen.
    
    //! UI has three main sections: Title, Actions, and Display.
    //! Title is displayed in Cyan.
    //! Actions are displayed in Yellow. Every action that the user can take, one per line.
    //! Display is displayed in white.
    class UserInterface : public Process {

        public:

        //! Constructor
        //! Creates the user interface to the provided runner.
        //! \param runner BattleRunner that this user inerface is getting its content from.
        UserInterface(BattleRunner& runner);

        //! Inititializes the UI.
        void init() {}
        
        //! Starts the UI.
        void start() {}
        
        //! Updates what is displayed on the screen with every update.
        void update();

        //! Stops the UI.
        void stop() {}

        //! Static variable that turns all following text red.
        const static char sBeginRed;
        //! Static variable that turns all following text black.
        const static char sEndRed;
        
        //! Static variable that turns all following text blue.
        const static char sBeginBlue;
        //! Static variable that turns all following text black.
        const static char sEndBlue;

        //! Static variable that turns all following text green.
        const static char sBeginGreen;
        //! Static variable that turns all following text black.
        const static char sEndGreen;

        //! Static variable that turns all following text magenta.
        const static char sBeginMagenta;
        //! Static variable that turns all following text black.
        const static char sEndMagenta;

        private:

        //! Prints the given text to the given row.
        //! Prints on a character by character basis to allow for inline color changes.
        //! \param row Row to print to.
        //! \param text Text to print.
        void print_line(uint32_t row, const std::string& text);

        BattleRunner& mRunner;

    };

}

#endif