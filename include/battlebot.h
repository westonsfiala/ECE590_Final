#ifndef _BATTLEBOT_H
#define _BATTLEBOT_H

#include "elma/elma.h"

using namespace elma;

namespace bots {

    class BattleRunner;

    class BattleBot : public Process
    {
        public:

            BattleBot(string name, BattleRunner& runner);
            void init();
            void start();
            void update();
            void stop();

            void trigger();

            void start_battle();
            inline void end_battle() {;};

            inline uint32_t AC() const { return 10 + mDexterity; }
            
            const static std::string sMove;
            const static std::string sAttack;
            const static std::string sDeath;

        private:

            int32_t mConstitution;
            int32_t mStrength;
            int32_t mDexterity;
            uint32_t mMovement;

            uint32_t mDamage;
            uint32_t mHealth;
            uint32_t mAC;

            void move();
            void attack();

            BattleRunner& mRunner;
    };
}

#endif