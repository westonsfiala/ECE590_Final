#ifndef _FRAME_ITEMS_H
#define _FRAME_ITEMS_H

#include "battlebot_item.h"

namespace bots {

    class BattleBot;

    //! Items that fill the frame slot of a battle bot.
    //! Frame items tend to modify base stats most, constitution, dexterity, and strength.
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

    //! Frame item that disregards survivablity for increased damage.
    class GlassCannonFrame : public FrameItem
    {
        public:
            GlassCannonFrame() : 
            FrameItem("Glass Cannon Frame", "Focuses on raw damage output over survivability")
            {};

            int32_t constitution_modifier() { return -3; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return -1; }
            int32_t num_damage_dice_modifier() { return 1; }
            int32_t damage_die_modifier() { return 2; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 1; }
            int32_t damage_modifier() { return 1; }
    };

    //! Frame item that increases dexterity, but reduces strength.
    class FlowingFrame : public FrameItem
    {
        public:
            FlowingFrame() : 
            FrameItem("Flowing Frame", "Focuses on dexterity over strength")
            {};

            int32_t constitution_modifier() { return -1; }
            int32_t strength_modifier() { return -2; }
            int32_t dexterity_modifier() { return 3; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    //! Frame item that slightly increases constitution, dexterity, and strength.
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

    //! Frame item that increases strength and constitution, but reduces dexterity.
    class BullishFrame : public FrameItem
    {
        public:
            BullishFrame() : 
            FrameItem("Bullish Frame", "Focuses on strength over dexterity")
            {};

            int32_t constitution_modifier() { return 2; }
            int32_t strength_modifier() { return 3; }
            int32_t dexterity_modifier() { return -1; }
            int32_t AC_modifier() { return 0; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };

    //! Frame item that increases constitution and AC.
    class DurableFrame : public FrameItem
    {
        public:
            DurableFrame() : 
            FrameItem("Durable Frame", "Focuses on survivability over damage")
            {};

            int32_t constitution_modifier() { return 4; }
            int32_t strength_modifier() { return 0; }
            int32_t dexterity_modifier() { return 0; }
            int32_t AC_modifier() { return 1; }
            int32_t num_damage_dice_modifier() { return 0; }
            int32_t damage_die_modifier() { return 0; }
            int32_t num_attacks_modifier() { return 0; }
            int32_t attack_modifier() { return 0; }
            int32_t damage_modifier() { return 0; }
    };
}

#endif