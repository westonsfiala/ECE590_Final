#ifndef _SPECIALTY_ITEMS_H
#define _SPECIALTY_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class SavageBlowsSpecialty : public BattleBotItem
    {
        public:
            SavageBlowsSpecialty() : 
            BattleBotItem("Savage Blows", "When an attack connects deals extra damage ")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 2; }
    };

    class SureStrikeSpecialty : public BattleBotItem
    {
        public:
            SureStrikeSpecialty() : 
            BattleBotItem("Sure Strike", "Attacks are more likely to hit")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 1; }
            int32_t damage_modifier() { return 0; }
    };

    class GuardedStanceSpecialty : public BattleBotItem
    {
        public:
            GuardedStanceSpecialty() : 
            BattleBotItem("Guarded Stance", "Always on guard raising your defensive capabilities")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 1; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class MultiAttackSpecialty : public BattleBotItem
    {
        public:
            MultiAttackSpecialty() : 
            BattleBotItem("Multi Attack", "Trades off accuracy for attacking more often")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 1; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return -3; }
            int32_t damage_modifier() { return 0; }
    };

    class LargeBuildSpecialty : public BattleBotItem
    {
        public:
            LargeBuildSpecialty() : 
            BattleBotItem("Large Build", "Gains health by being large")
            {};

            int32_t constitution_modifier() { return 2; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };
}

#endif