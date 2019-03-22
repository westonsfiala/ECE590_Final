#include "battlebot_item.h"
#include "battlebot.h"

using namespace bots;

std::string BattleBotItem::stat_display()
{
    std::string changes;

    auto mod = 0;
    
    mod = constitution_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Constitution " + plus + std::to_string(mod) + " ";
    }

    mod = strength_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Strength " + plus + std::to_string(mod) + " ";
    }

    mod = dexterity_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Dexterity " + plus + std::to_string(mod) + " ";
    }

    mod = AC_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Armor Class(AC) " + plus + std::to_string(mod) + " ";
    }

    mod = num_damage_dice_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Damage Dice " + plus + std::to_string(mod) + " ";
    }

    mod = damage_die_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Damage Die " + plus + std::to_string(mod) + " ";
    }

    mod = attack_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Attack Modifier " + plus + std::to_string(mod) + " ";
    }

    mod = damage_modifier();
    if(mod != 0)
    {
        std::string plus = (mod > 0) ? "+" : "";

        changes += "Damage Modifier " + plus + std::to_string(mod) + " ";
    }


    return changes;
}