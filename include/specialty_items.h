#ifndef _SPECIALTY_ITEMS_H
#define _SPECIALTY_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class SpecialtyItem : public BattleBotItem
    {
        public:
            SpecialtyItem() : 
            BattleBotItem("Empty Specialty", "No Specialty selected")
            {};

            SpecialtyItem(std::string name, std::string description) : 
            BattleBotItem(name, description)
            {};
    };

    class SavageBlowsSpecialty : public SpecialtyItem
    {
        public:
            SavageBlowsSpecialty() : 
            SpecialtyItem("Savage Blows", "When an attack connects deals extra damage ")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 2; }
    };

    class SureStrikeSpecialty : public SpecialtyItem
    {
        public:
            SureStrikeSpecialty() : 
            SpecialtyItem("Sure Strike", "Attacks are more likely to hit")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 1; }
            int32_t damage_modifier() { return 0; }
    };

    class GuardedStanceSpecialty : public SpecialtyItem
    {
        public:
            GuardedStanceSpecialty() : 
            SpecialtyItem("Guarded Stance", "Always on guard raising your defensive capabilities")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 1; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class MultiAttackSpecialty : public SpecialtyItem
    {
        public:
            MultiAttackSpecialty() : 
            SpecialtyItem("Multi Attack", "Trades off accuracy for attacking more often")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 1; }
            int32_t attack_modifier() { return -3; }
            int32_t damage_modifier() { return 0; }
    };

    class LargeBuildSpecialty : public SpecialtyItem
    {
        public:
            LargeBuildSpecialty() : 
            SpecialtyItem("Large Build", "Gains health by being large")
            {};

            int32_t constitution_modifier() { return 2; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };
}

#endif