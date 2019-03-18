#ifndef _BATTLEBOT_H
#define _BATTLEBOT_H

#include "elma/elma.h"

using namespace elma;

namespace bots {

    class BattleRunner;

    class BattleBot
    {
        public:

            BattleBot(string name, BattleRunner& runner);

            std::string name();

            void trigger();

            void start_battle();
            void end_battle();

            uint32_t AC();
            
            const static std::string sMove;
            const static std::string sAttack;
            const static std::string sDeath;

        protected:

            void watch(string event_name, std::function<void(Event&)> handler);
            void emit(const Event& event);

            std::string mName;

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