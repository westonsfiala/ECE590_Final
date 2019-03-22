#ifndef _KEY_CAPTURE_H
#define _KEY_CAPTURE_H

#include "elma/elma.h"

using namespace elma;

namespace bots {

    class BattleRunner;

    //! Class that queries for keyboard inputs and sends them to the battle runner.
    class KeyCapture : public Process {

        public:

            //! Constructor
            //! \param runner BattleRunner to send keys to.
            KeyCapture(BattleRunner& runner);

            //! Does not do anything when initialized.
            void init() {}

            //! Does not do anything when started.
            void start() {}

            //! Queries into the keyboard to see if any keys are pressed.
            //! If a key is found, sends it to the battle runner.
            void update();

            //! Does not do anything when stopped.
            void stop() {}

        private:

            BattleRunner& mRunner;
    };

}

#endif