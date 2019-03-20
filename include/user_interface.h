#ifndef _USER_INTERFACE_H
#define _USER_INTERFACE_H

#include "battle_runner.h"

using namespace elma;

namespace bots {

    class UserInterface : public Process {

        public:

        UserInterface(BattleRunner& runner);

        void init() {}
        void start() {}
        void update();
        void stop() {}

        const static char sBeginRed;
        const static char sEndRed;
        
        const static char sBeginBlue;
        const static char sEndBlue;

        const static char sBeginGreen;
        const static char sEndGreen;

        const static char sBeginMagenta;
        const static char sEndMagenta;

        private:

        void print_line(uint32_t row, const std::string& text);

        BattleRunner& mRunner;

    };

}

#endif