#include "armor_items.h"
#include "battlebot.h"

using namespace bots;

int32_t ChainArmor::AC_modifier()
{
    auto rawBonus = 5;
    if(mAttachedBot != nullptr)
    {
        auto maxBonus = 2;
        if(mAttachedBot->dexterity() > maxBonus)
        {
            rawBonus -= mAttachedBot->dexterity() - maxBonus;
        }
    }
    
    return rawBonus;
}

int32_t PlateArmor::AC_modifier()
{
    auto rawBonus = 8;
    if(mAttachedBot != nullptr)
    {
        rawBonus -= mAttachedBot->dexterity();
    }
    
    return rawBonus;
}

int32_t SpikedArmor::AC_modifier()
{
    auto rawBonus = 3;
    if(mAttachedBot != nullptr)
    {
        auto maxBonus = 2;
        if(mAttachedBot->dexterity() > maxBonus)
        {
            rawBonus -= mAttachedBot->dexterity() - maxBonus;
        }
    }
    
    return rawBonus;
}