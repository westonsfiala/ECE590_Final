#include "battlebot.h"

#include "battle_runner.h"

using namespace bots;

const std::string BattleBot::sMove = "Move";
const std::string BattleBot::sAttack = "Attack";
const std::string BattleBot::sDeath = "Death";


BattleBot::BattleBot(string name, BattleRunner& runner) : Process(name), mRunner(runner) 
{
    end_battle();
}

void BattleBot::init()
{
    watch(sAttack, [&](Event& e)
    {

        if(mHealth == 0)
        {
            return;
        }

        auto attackData = e.value();

        // Don't care about attacking ourselves
        if(attackData["attacker"].get<std::string>() == name())
        {
            return;
        }
        
        std::string attackLog = attackData["attacker"].get<std::string>() + " attacks with a (" + std::to_string(attackData["attack"].get<uint32_t>()) + ") to hit";

        // Check to see if the attack beat our AC
        if(attackData["attack"].get<uint32_t>() < AC())
        {
            attackLog += ", but " + name() + " blocks.";
            emit(Event(BattleRunner::sLogEvent, attackLog));
        }
        else
        {
            auto damage = attackData["damage"].get<uint32_t>();

            attackLog += ", and " + name() + " took (" + std::to_string(damage) + ") damage";


            // They hurt us
            if(mHealth < damage)
            {
                // We died
                mHealth = 0;
                attackLog += " and died";

                json deathData;
                deathData["killer"] = attackData["attacker"].get<std::string>();
                deathData["self"] = name();

                
                emit(Event(BattleRunner::sLogEvent, attackLog));
                emit(Event(BattleState::sBattleEnd, deathData));
            }
            else
            {
                mHealth -= damage;
                
                attackLog += " reducing health to [" + std::to_string(mHealth) + "]";
                
                emit(Event(BattleRunner::sLogEvent, attackLog));
            }
        }
    });
}

void BattleBot::start()
{

}

void BattleBot::update()
{
}

void BattleBot::stop()
{

}

void BattleBot::trigger()
{
    move();
    attack();
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

    emit(Event(sAttack, attackData));
}