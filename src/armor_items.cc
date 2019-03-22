#include "armor_items.h"
#include "battlebot.h"

using namespace bots;

int32_t UnarmoredArmor::AC_modifier()
{
    auto rawBonus = 0;
    if(mAttachedBot != nullptr)
    {
        rawBonus += mAttachedBot->dexterity();
    }

    return 0;
}

int32_t LeatherArmor::AC_modifier()
{
    auto rawBonus = 2;
    if(mAttachedBot != nullptr)
    {
        rawBonus += mAttachedBot->dexterity();
    }
    
    return rawBonus;
}

int32_t ChainArmor::AC_modifier()
{
    auto rawBonus = 4;
    if(mAttachedBot != nullptr)
    {
        rawBonus += std::min<int32_t>(mAttachedBot->dexterity(),2);
    }
    
    return rawBonus;
}