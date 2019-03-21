#include "battlebot.h"

#include "battle_runner.h"
#include "user_interface.h"

using namespace bots;

BattleBot::BattleBot(string botName, BattleRunner& runner) : mName(botName), mRunner(runner) 
{
    reset();
}

void BattleBot::reset()
{
    mConstitution = 0;
    mStrength = 0;
    mDexterity = 0;
    mMovement = 6;

    mHealth = 20;
    mDamage = 6;
    
    mAttacks = 0;
    mHits = 0;
    mDamageDealt = 0;
    mAttacksBlocked = 0;
    mKills = 0;
}

std::string BattleBot::name() 
{ 
    return mName; 
}

std::string BattleBot::display()
{
    std::string botDisplay = name() + ": ";
    if(mHealth == 0)
    {
        botDisplay += "[DEAD]";
    }
    else
    {
        botDisplay += "Health = [" + std::to_string(mHealth) + "], ";
        botDisplay += "Attack = <1d20+" + std::to_string(attack_modifier()) + ">, ";
        botDisplay += "Damage = <" + std::to_string(num_damage_die()) + "d" + std::to_string(damage_die()) + "+" + std::to_string(damage_modifier()) + ">, ";
        botDisplay += "AC = (" + std::to_string(AC()) + ")";
        // botDisplay += ", Movement = " + std::to_string(movement());
    }

    return botDisplay;
}

std::string BattleBot::get_battle_stats()
{
    std::string botStats = name() + ": ";

    botStats += "blocked (" + std::to_string(mAttacksBlocked) + ") attacks, ";
    botStats += "performed <" + std::to_string(mAttacks) + "> attacks ";
    botStats += "hitting <" + std::to_string(mHits) + "> times ";
    botStats += "dealing [" + std::to_string(mDamageDealt) + "] damage and killing [" + std::to_string(mKills) + "] bots.";

    return botStats;
}

void BattleBot::trigger()
{
    move();
    attack();
}

void BattleBot::react(BattleBot* attacker, json attackData)
{
    if(attacker == this)
    {
        mAttacks++;
        return;
    }

    if(attacker == nullptr)
    {
        return;
    }

    if(mHealth == 0)
    {
        return;
    }
    
    std::string attackLog = attackData["attacker"].get<std::string>() + " attacks " + name() + " with a <" + std::to_string(attackData["attack"].get<uint32_t>()) + ">.";

    // Check to see if the attack beat our AC
    if(attackData["attack"].get<uint32_t>() < AC())
    {
        mAttacksBlocked++;
        attackLog += " " + name() + " (blocks).";
        mRunner.log(attackLog);
    }
    else
    {
        auto damage = attackData["damage"].get<uint32_t>();

        attackLog += " " + name() + " takes [" + std::to_string(damage) + "] damage.";
        mRunner.log(attackLog);

        attacker->mHits++;
        attacker->mDamageDealt += damage;

        // They hurt us
        if(mHealth <= damage)
        {
            // We died
            mHealth = 0;
            mRunner.log(name() + " [dies].");

            attacker->mKills++;
        }
        else
        {
            mHealth -= damage;
            
        }
    }
}

bool BattleBot::is_dead()
{
    return mHealth == 0;
}

void BattleBot::start_battle() 
{

}

void BattleBot::end_battle() 
{

}

uint32_t BattleBot::AC() 
{ 
    return 10 + mDexterity; 
}

uint32_t BattleBot::movement()
{
    return mMovement;
}

int32_t BattleBot::attack_modifier()
{
    return mStrength + 2;
}

uint32_t BattleBot::num_damage_die()
{
    return 1;
}

uint32_t BattleBot::damage_die()
{
    return mDamage;
}

int32_t BattleBot::damage_modifier()
{
    return mStrength;
}

void BattleBot::move()
{
    // TODO when map is created.
}

void BattleBot::attack()
{
    json attackData;

    attackData["attacker"] = name();
    attackData["attack"] = mRunner.roll(1, 20, attack_modifier());
    attackData["damage"] = mRunner.roll(num_damage_die(), damage_die(), damage_modifier());

    mRunner.react_bots(this, attackData);
}