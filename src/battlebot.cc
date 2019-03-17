#include "battlebot.h"

#include "battle_runner.h"

using namespace bots;

const std::string BattleBot::sMove = "Move";
const std::string BattleBot::sAttack = "Attack";
const std::string BattleBot::sDeath = "Death";


BattleBot::BattleBot(string name, BattleRunner& runner) : Process(name), mRunner(runner) 
{
}

void BattleBot::init()
{
    mConstitution = 0;
    mStrength = 0;
    mDexterity = 0;
    mMovement = 3;

    mHealth = 20;
    mDamage = 6;

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

        // Check to see if the attack beat our AC
        if(attackData["attack"].get<uint32_t>() < AC())
        {
            std::string blockLog = name() + " blocks with an AC of (" + std::to_string(AC()) + ")";
            emit(Event(BattleRunner::sLogEvent, blockLog));
            return;
        }

        std::string damageTaken = name() + " took " + attackData["damage"].get<std::string>() + ".";

        emit(Event(BattleRunner::sLogEvent, damageTaken));

        auto damage = attackData["damage"].get<uint32_t>();

        // They hurt us
        if(mHealth < damage)
        {
            // We died
            mHealth = 0;

            std::string deathLog = name() + " died.";
            emit(Event(BattleRunner::sLogEvent, deathLog));

            json deathData;
            deathData["killer"] = attackData["attacker"].get<std::string>();
            deathData["self"] = name();

            emit(Event(sDeath, deathData));
        }
        else
        {
            mHealth -= damage;
        }
    });
}

void BattleBot::start()
{

}

void BattleBot::update()
{
    move();
    attack();
}

void BattleBot::stop()
{

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

    std::string attackLog = attackData["attacker"].get<std::string>() + " attacks with a (" + attackData["attack"].get<std::string>() + ")";

    emit(Event(BattleRunner::sLogEvent, attackLog));
    emit(Event(sAttack, attackData));
}