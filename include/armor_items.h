#ifndef _ARMOR_ITEMS_H
#define _ARMOR_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    //! Items that fill the armor slot of a battle bot.
    //! Armor items tend to modify AC most.
    class ArmorItem : public BattleBotItem
    {
        public:
            ArmorItem() : 
            BattleBotItem("Empty Armor", "No Armor selected")
            {};

            ArmorItem(std::string name, std::string description) : 
            BattleBotItem(name, description)
            {};
    };

    //! Armor that sacrifices AC gain in favor of more damage.
    class UnarmoredArmor : public ArmorItem
    {
        public:
            UnarmoredArmor() : 
            ArmorItem("Unarmored", "Relies on dexterity to avoid damage while allowing for more accurate attacks")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 2; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 3; }
            int32_t damage_modifier() { return 0; }
    };

    //! Armor that gives a small AC gain while making attacking slighty better.
    class LeatherArmor : public ArmorItem
    {
        public:
            LeatherArmor() : 
            ArmorItem("Leather Armor", "Relies on dexterity and slight protection to avoid damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 2; };
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 1; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 1; }
            int32_t damage_modifier() { return 0; }
    };

    //! Armor that gives good raw AC, but only gains a small amount from dexterity.
    class ChainArmor : public ArmorItem
    {
        public:
            ChainArmor() : 
            ArmorItem("Chain Armor", "Relies on metal chains for protection with a small bonus from dexterity")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    //! Armor that gives great raw AC, but gains none from dexterity. Makes attacking slightly harder.
    class PlateArmor : public ArmorItem
    {
        public:
            PlateArmor() : 
            ArmorItem("Plate Armor", "Relies upon heavy metal plates for protection maving attacks harder to perform")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return -2; }
            int32_t damage_modifier() { return -1; }
    };

    //! Armor that gives SK raw AC, but only gains a small amount from dexterity. Gives a small damage bonus.
    class SpikedArmor : public ArmorItem
    {
        public:
            SpikedArmor() : 
            ArmorItem("Spiked Armor", "Relies upon small spiked plates to provide moderate defence while increasing damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier();
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 1; }
    };
}

#endif