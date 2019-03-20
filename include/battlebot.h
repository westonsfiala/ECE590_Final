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
            std::string display();

            void trigger();
            void react(BattleBot* attacker, json attackData);

            bool is_dead();

            void start_battle();
            void end_battle();

            virtual uint32_t movement();
            virtual uint32_t AC();
            virtual int32_t attack_modifier();
            virtual uint32_t num_damage_die();
            virtual uint32_t damage_die();
            virtual int32_t damage_modifier();
            
            const static std::string sMove;
            const static std::string sAttack;
            const static std::string sDeath;

        protected:

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