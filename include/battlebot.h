#ifndef _BATTLEBOT_H
#define _BATTLEBOT_H

#include "elma/elma.h"

using namespace elma;

namespace bots {

    class BattleRunner;
    class BuildBotState;

    class BattleBot
    {
        friend class BuildBotState;
        public:

            BattleBot(string name, BattleRunner& runner);

            void reset();
            std::string name();
            std::string display();
            std::string get_battle_stats();

            void trigger();
            void react(BattleBot* attacker, json attackData);

            bool is_dead();

            uint32_t movement();
            uint32_t AC();
            int32_t attack_modifier();
            uint32_t num_damage_die();
            uint32_t damage_die();
            int32_t damage_modifier();

            std::vector<int32_t> get_config();

        protected:

            std::string mName;

            // Raw stats
            int32_t mConstitution;
            int32_t mStrength;
            int32_t mDexterity;
            uint32_t mMovement;
            int32_t mAttackBonus;
            int32_t mDamageBonus;

            // Calculated stats
            uint32_t mNumDamageDice;
            uint32_t mDamageDie;
            uint32_t mHealth;
            uint32_t mAC;

            // Log variables
            uint32_t mAttacks;
            uint32_t mHits;
            uint32_t mDamageDealt;
            uint32_t mAttacksBlocked;
            uint32_t mKills;

            std::vector<int32_t> mConfig;

            BattleRunner& mRunner;

            void move();
            void attack();
    };
}

#endif