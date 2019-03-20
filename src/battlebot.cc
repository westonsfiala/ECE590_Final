#include "battlebot.h"

#include "battle_runner.h"

using namespace bots;

const std::string BattleBot::sMove = "Move";
const std::string BattleBot::sAttack = "Attack";
const std::string BattleBot::sDeath = "Death";


BattleBot::BattleBot(string botName, BattleRunner& runner) : mName(botName), mRunner(runner) 
{

}

std::string BattleBot::name() 
{ 
    return mName; 
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

    // Don't care about attacking ourselves
    if(attackData["attacker"].get<std::string>() == name())
    {
        return;
    }
    
    std::string attackLog = attackData["attacker"].get<std::string>() + " attacks with a (" + std::to_string(attackData["attack"].get<uint32_t>()) + ") to hit.";

    // Check to see if the attack beat our AC
    if(attackData["attack"].get<uint32_t>() < AC())
    {
        attackLog += " " + name() + " blocks.";
        mRunner.log(attackLog);
    }
    else
    {
        auto damage = attackData["damage"].get<uint32_t>();

        attackLog += " " + name() + " took (" + std::to_string(damage) + ") damage";

        // They hurt us
        if(mHealth <= damage)
        {
            // We died
            mHealth = 0;
            attackLog += " and died";

            json deathData;
            deathData["killer"] = attackData["attacker"].get<std::string>();
            deathData["self"] = name();

            mRunner.log(attackLog);
            emit(Event(BattleState::sBattleEnd, deathData));
        }
        else
        {
            mHealth -= damage;
            
            attackLog += " reducing health to [" + std::to_string(mHealth) + "]";
            
            mRunner.log(attackLog);
        }
    }
}

bool BattleBot::is_dead()
{
    return mHealth == 0;
}

void BattleBot::start_battle() 
{
    mConstitution = 0;
    mStrength = 0;
    mDexterity = 0;
    mMovement = 3;

    mHealth = 20;
    mDamage = 6;
}

void BattleBot::end_battle() 
{

}

uint32_t BattleBot::AC() 
{ 
    return 10 + mDexterity; 
}

void BattleBot::move()
{
    // TODO when map is created.
}

void BattleBot::attack()
{
    json attackData;

    attackData["attacker"] = name();
    attackData["attack"] = mRunner.roll(20,mStrength);
    attackData["damage"] = mRunner.roll(mDamage,mStrength);

    mRunner.react_bots(this, attackData);
}

void BattleBot::emit(const Event& event)
{ 
    mRunner.emit(event);
};