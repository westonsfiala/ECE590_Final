#ifndef _ARMOR_ITEMS_H
#define _ARMOR_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class UnarmoredArmor : public BattleBotItem
    {
        public:
            UnarmoredArmor() : 
            BattleBotItem("Unarmored", "Relies on dexterity to avoid damage while allowing for more accurate attacks")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 2; }
            int32_t dexterity_modifier() { return 2; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class LeatherArmor : public BattleBotItem
    {
        public:
            LeatherArmor() : 
            BattleBotItem("Leather Armor", "Relies on dexterity and slight protection to avoid damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class ChainArmor : public BattleBotItem
    {
        public:
            ChainArmor() : 
            BattleBotItem("Chain Armor", "Relies on metal chains for protection with a small bonus from dexterity")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class PlateArmor : public BattleBotItem
    {
        public:
            PlateArmor() : 
            BattleBotItem("Plate Armor", "Relies upon heavy metal plates for protection maving attacks harder to perform")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 6; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return -1; }
            int32_t damage_modifier() { return 0; }
    };

    class SpikedArmor : public BattleBotItem
    {
        public:
            SpikedArmor() : 
            BattleBotItem("Spiked Armor", "Relies upon small spiked plates to provide moderate defence while increasing damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 4; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 2; }
    };
}

#endif