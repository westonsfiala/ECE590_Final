#include "weapon_items.h"
#include "battlebot.h"

using namespace bots;

int32_t TwinDaggersWeapon::attack_modifier()
{
    auto mod = 2;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->dexterity();
    }
    return mod; 
}

int32_t TwinDaggersWeapon::damage_modifier()
{ 
    auto mod = 0;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->dexterity();
    }
    return mod; 
}

int32_t RapierWeapon::attack_modifier()
{
    auto mod = 3;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->dexterity();
    }
    return mod; 
}

int32_t RapierWeapon::damage_modifier()
{ 
    auto mod = 1;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->dexterity();
    }
    return mod; 
}

int32_t SwordAndShieldWeapon::attack_modifier()
{
    auto mod = 2;
    if(mAttachedBot != nullptr)
    {
        mod += std::max<int32_t>(mAttachedBot->strength(), mAttachedBot->dexterity());
    }
    return mod; 
}

int32_t SwordAndShieldWeapon::damage_modifier()
{ 
    auto mod = 0;
    if(mAttachedBot != nullptr)
    {
        mod += std::max<int32_t>(mAttachedBot->strength(), mAttachedBot->dexterity());
    }
    return mod; 
}

int32_t WarhammerWeapon::attack_modifier()
{
    auto mod = 3;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->strength();
    }
    return mod; 
}

int32_t WarhammerWeapon::damage_modifier()
{ 
    auto mod = 2;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->strength();
    }
    return mod; 
}

int32_t GreataxeWeapon::attack_modifier()
{
    auto mod = 0;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->strength();
    }
    return mod; 
}

int32_t GreataxeWeapon::damage_modifier()
{ 
    auto mod = 1;
    if(mAttachedBot != nullptr)
    {
        mod += mAttachedBot->strength();
    }
    return mod; 
}
