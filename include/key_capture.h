#ifndef _KEY_CAPTURE_H
#define _KEY_CAPTURE_H

#include "elma/elma.h"

using namespace elma;

namespace bots {

    class BattleRunner;

    class KeyCapture : public Process {

        public:

            KeyCapture(BattleRunner& runner);
            ~KeyCapture();

            void init() {}
            void start() {}
            void update();
            void stop() {}

            const static std::string sKeyPressEvent;
            const static std::string sKeyPressKey;

        private:

            BattleRunner& mRunner;
    };

}

#endif