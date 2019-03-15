#ifndef _BATTLEBOT_H
#define _BATTLEBOT_H

#include "elma.h"

class BattleBot : public elma::Process
{
    public:

        BattleBot(string name) : Process(name) {}
        void init();
        void start();
        void update();
        void stop();

    private:

        int32_t mConstitution;
        int32_t mStrength;
        int32_t mDexterity;
        int32_t mLevel;
        int32_t mMovement;
};

#endif