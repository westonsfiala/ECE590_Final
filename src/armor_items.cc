#include "armor_items.h"
#include "battlebot.h"

using namespace bots;

int32_t UnarmoredArmor::AC_modifier()
{
    auto rawBonus = 10;
    if(mAttachedBot != nullptr)
    {
        rawBonus += mAttachedBot->dexterity();
    }
    
    return rawBonus;
}

int32_t LeatherArmor::AC_modifier()
{
    auto rawBonus = 12;
    if(mAttachedBot != nullptr)
    {
        rawBonus += mAttachedBot->dexterity();
    }
    
    return rawBonus;
}

int32_t ChainArmor::AC_modifier()
{
    auto rawBonus = 14;
    if(mAttachedBot != nullptr)
    {
        rawBonus += std::max<int32_t>(mAttachedBot->dexterity(),1);
    }
    
    return rawBonus;
}

int32_t SpikedArmor::AC_modifier()
{
    auto rawBonus = 13;
    if(mAttachedBot != nullptr)
    {
        rawBonus += std::max<int32_t>(mAttachedBot->dexterity(),1);
    }
    
    return rawBonus;
}