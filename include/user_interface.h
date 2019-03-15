#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include "battle_runner.h"

namespace bots {

    using namespace std::chrono;
    using namespace elma;

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