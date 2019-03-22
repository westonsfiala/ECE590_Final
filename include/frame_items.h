#ifndef _FRAME_ITEMS_H
#define _FRAME_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class GlassCannonFrame : public BattleBotItem
    {
        public:
            GlassCannonFrame() : 
            BattleBotItem("Glass Cannon Frame", "Focuses on raw damage output over survivability")
            {};

            int32_t constitution_modifier() { return -2; }
            int32_t strength_modifier() { return 2; }
            int32_t dexterity_modifier() { return 2; }
            int32_t AC_modifier() { return -2; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 1; }
            int32_t damage_modifier() { return 1; }
    };

    class FlowingFrame : public BattleBotItem
    {
        public:
            FlowingFrame() : 
            BattleBotItem("Flowing Frame", "Focuses on dexterity over strength")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return -1; }
            int32_t dexterity_modifier() { return 3; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class StandardFrame : public BattleBotItem
    {
        public:
            StandardFrame() : 
            BattleBotItem("Standard Frame", "Focuses on reliability over specialization")
            {};

            int32_t constitution_modifier() { return 1; }
            int32_t strength_modifier() { return 1; }
            int32_t dexterity_modifier() { return 1; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class BullishFrame : public BattleBotItem
    {
        public:
            BullishFrame() : 
            BattleBotItem("Bullish Frame", "Focuses on strength over dexterity")
            {};

            int32_t constitution_modifier() { return 1; }
            int32_t strength_modifier() { return 1; }
            int32_t dexterity_modifier() { return 1; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class DurableFrame : public BattleBotItem
    {
        public:
            DurableFrame() : 
            BattleBotItem("Durable Frame", "Focuses on survivability over damage")
            {};

            int32_t constitution_modifier() { return 5; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 1; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t attack_modifier() { return -1; }
            int32_t damage_modifier() { return -1; }
    };
}

#endif