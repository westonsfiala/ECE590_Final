#ifndef _WEAPON_ITEMS_H
#define _WEAPON_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    //! Items that fill the weapon slot of a battle bot.
    
    //! Weapon items tend to modify attack and damage stats most.
    class WeaponItem : public BattleBotItem
    {
        public:
            WeaponItem() : 
            BattleBotItem("Empty Weapon", "No Weapon selected")
            {};

            WeaponItem(std::string name, std::string description) : 
            BattleBotItem(name, description)
            {};
    };

    //! Weapon that relies upon multiple small attacks to deal damage. Uses Dexterity.
    class TwinDaggersWeapon : public WeaponItem
    {
        public:
            TwinDaggersWeapon() : 
            WeaponItem("Twin Daggers", "Relies on dexterity to slash and stab opponents rapidly")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 4; }
            int32_t num_attacks_modifier() { return 1; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    //! Weapon that relies upon high accuracy attacks to consistently damage. Uses Dexterity.
    class RapierWeapon : public WeaponItem
    {
        public:
            RapierWeapon() : 
            WeaponItem("Rapier", "Relies on dexterity to pierce past defences easier at the cost of damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 8; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    //! Weapon that deals small damage, but gives a bonus to AC. Uses higher of Dexterity and Strength.
    class SwordAndShieldWeapon : public WeaponItem
    {
        public:
            SwordAndShieldWeapon() : 
            WeaponItem("Sword and Shield", "Relies on either strength or dexterity to cut opponents while warding off blows with the shield")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 2; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 6; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    //! Weapon that deals consistent high damage and hits often. Uses Strength.
    class WarhammerWeapon : public WeaponItem
    {
        public:
            WarhammerWeapon() : 
            WeaponItem("Warhammer", "Relies upon strength to crush opponents")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 1; }
            int32_t damage_die_modifier() { return 6; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    //! Weapon that deals variable high damage with a bonus to damage. Uses Strength.
    class GreataxeWeapon : public WeaponItem
    {
        public:
            GreataxeWeapon() : 
            WeaponItem("Greataxe", "Relies upon strength to deal savage blows but misses more often")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 12; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };
}

#endif