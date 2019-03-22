#ifndef _FRAME_ITEMS_H
#define _FRAME_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    class FrameItem : public BattleBotItem
    {
        public:
            FrameItem() : 
            BattleBotItem("Empty Frame", "No Frame selected")
            {};

            FrameItem(std::string name, std::string description) : 
            BattleBotItem(name, description)
            {};
    };

    class GlassCannonFrame : public FrameItem
    {
        public:
            GlassCannonFrame() : 
            FrameItem("Glass Cannon Frame", "Focuses on raw damage output over survivability")
            {};

            int32_t constitution_modifier() { return -2; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return -2; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 3; }
            int32_t damage_modifier() { return 3; }
    };

    class FlowingFrame : public FrameItem
    {
        public:
            FlowingFrame() : 
            FrameItem("Flowing Frame", "Focuses on dexterity over strength")
            {};

            int32_t constitution_modifier() { return 0; }
            int32_t strength_modifier() { return -1; }
            int32_t dexterity_modifier() { return 3; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class StandardFrame : public FrameItem
    {
        public:
            StandardFrame() : 
            FrameItem("Standard Frame", "Focuses on reliability over specialization")
            {};

            int32_t constitution_modifier() { return 1; }
            int32_t strength_modifier() { return 1; }
            int32_t dexterity_modifier() { return 1; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class BullishFrame : public FrameItem
    {
        public:
            BullishFrame() : 
            FrameItem("Bullish Frame", "Focuses on strength over dexterity")
            {};

            int32_t constitution_modifier() { return 1; }
            int32_t strength_modifier() { return 1; }
            int32_t dexterity_modifier() { return 1; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    class DurableFrame : public FrameItem
    {
        public:
            DurableFrame() : 
            FrameItem("Durable Frame", "Focuses on survivability over damage")
            {};

            int32_t constitution_modifier() { return 5; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 1; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return -1; }
            int32_t damage_modifier() { return -1; }
    };
}

#endif