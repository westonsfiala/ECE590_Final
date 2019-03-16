#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include "battle_runner.h"

using namespace std::chrono;
using namespace elma;

namespace bots {

    class UserInterface : public Process {

        public:

        UserInterface(BattleRunner& runner);

        void init() {}
        void start() {}
        void update();
        void stop() {}

        private:
        BattleRunner& mRunner;

    };

}

#endif