#ifndef _WEAPON_ITEMS_H
#define _WEAPON_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class TwinDaggersWeapon : public BattleBotItem
    {
        public:
            TwinDaggersWeapon() : 
            BattleBotItem("Twin Daggers", "Relies on dexterity to slash and stab opponents rapidly")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 1; }
            int32_t damage_die_modifier() { return 4; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    class RapierWeapon : public BattleBotItem
    {
        public:
            RapierWeapon() : 
            BattleBotItem("Rapier", "Relies on dexterity to pierce past defences easier at the cost of damage")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 8; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    class SwordAndShieldWeapon : public BattleBotItem
    {
        public:
            SwordAndShieldWeapon() : 
            BattleBotItem("Sword and Shield", "Relies on either strength or dexterity to cut opponents while warding off blows with the shield")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 2; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 6; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    class WarhammerWeapon : public BattleBotItem
    {
        public:
            WarhammerWeapon() : 
            BattleBotItem("Warhammer", "Relies upon strength to crush opponents while leaving openings in defence")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return -1; }
            int32_t num_damage_dice_modifier() { return 1; }
            int32_t damage_die_modifier() { return 6; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };

    class GreataxeWeapon : public BattleBotItem
    {
        public:
            GreataxeWeapon() : 
            BattleBotItem("Greataxe", "Relies upon strength to deal savage blows but misses more often")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 12; }
            int32_t attack_modifier();
            int32_t damage_modifier();
    };
}

#endif