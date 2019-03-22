#include "battlebot.h"

#include "battle_runner.h"
#include "user_interface.h"

using namespace bots;

BattleBot::BattleBot(string botName, BattleRunner& runner) : mName(botName), mRunner(runner) 
{
    mFrames.clear();
    mFrames.push_back(new GlassCannonFrame());
    mFrames.push_back(new FlowingFrame());
    mFrames.push_back(new StandardFrame());
    mFrames.push_back(new BullishFrame());
    mFrames.push_back(new DurableFrame());

    mArmors.clear();
    mArmors.push_back(new UnarmoredArmor());
    mArmors.push_back(new LeatherArmor());
    mArmors.push_back(new ChainArmor());
    mArmors.push_back(new PlateArmor());
    mArmors.push_back(new SpikedArmor());

    mWeapons.clear();
    mWeapons.push_back(new TwinDaggersWeapon());
    mWeapons.push_back(new RapierWeapon());
    mWeapons.push_back(new SwordAndShieldWeapon());
    mWeapons.push_back(new WarhammerWeapon());
    mWeapons.push_back(new GreataxeWeapon());

    mSpecialties.clear();
    mSpecialties.push_back(new SavageBlowsSpecialty());
    mSpecialties.push_back(new SureStrikeSpecialty());
    mSpecialties.push_back(new GuardedStanceSpecialty());
    mSpecialties.push_back(new MultiAttackSpecialty());
    mSpecialties.push_back(new LargeBuildSpecialty());
    
    mFrame = nullptr;
    mArmor = nullptr;
    mWeapon = nullptr;
    mSpecialty = nullptr;

    mConfig = {-1, -1, -1, -1};

    init_items();

    reset();
}

BattleBot::~BattleBot()
{
    destroy_items();
}

void BattleBot::reset()
{
    fill_empty_items();
    calculate_health();
    
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
        std::string attackPlus = (attack_modifier() >= 0) ? "+" : "";
        std::string damagePlus = (damage_modifier() >= 0) ? "+" : "";

        botDisplay += "Health = [" + std::to_string(mHealth) + "], ";
        botDisplay += "Attack = {" + std::to_string(num_attacks()) + "x 1d20" + attackPlus + std::to_string(attack_modifier()) + "}, ";
        botDisplay += "Damage = <" + std::to_string(num_damage_die()) + "d" + std::to_string(damage_die()) + damagePlus + std::to_string(damage_modifier()) + ">, ";
        botDisplay += "AC = (" + std::to_string(AC()) + ")";
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

std::string BattleBot::get_simple_loadout()
{
    std::string loadout = "";

    loadout += mFrame->name() + ", ";
    loadout += mArmor->name() + ", ";
    loadout += mWeapon->name() + ", ";
    loadout += mSpecialty->name();

    return loadout;
}

std::vector<std::string> BattleBot::get_detailed_loadout()
{
    std::vector<std::string> loadout;

    loadout.push_back(mFrame->name() + ": " + mFrame->stat_display());
    loadout.push_back(mArmor->name() + ": " + mArmor->stat_display());
    loadout.push_back(mWeapon->name() + ": " + mWeapon->stat_display());
    loadout.push_back(mSpecialty->name() + ": " + mSpecialty->stat_display());

    return loadout;
}

void BattleBot::trigger()
{
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
    
    std::string attackLog = attackData["attacker"].get<std::string>() + " attacks " + name() + " with a <" + std::to_string(attackData["attack"].get<int32_t>()) + ">.";

    // Check to see if the attack beat our AC
    if(attackData["attack"].get<int32_t>() < AC())
    {
        mAttacksBlocked++;
        attackLog += " " + name() + " (blocks).";
        mRunner.log(attackLog);
    }
    else
    {
        auto damage = std::max<int32_t>(attackData["damage"].get<int32_t>(),0);

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
            
int32_t BattleBot::constitution()
{
    auto value = 0;
    value += mFrame->constitution_modifier();
    value += mArmor->constitution_modifier();
    value += mWeapon->constitution_modifier();
    value += mSpecialty->constitution_modifier();
    return value;
}

int32_t BattleBot::strength()
{
    auto value = 0;
    value += mFrame->strength_modifier();
    value += mArmor->strength_modifier();
    value += mWeapon->strength_modifier();
    value += mSpecialty->strength_modifier();
    return value;
}

int32_t BattleBot::dexterity()
{
    auto value = 0;
    value += mFrame->dexterity_modifier();
    value += mArmor->dexterity_modifier();
    value += mWeapon->dexterity_modifier();
    value += mSpecialty->dexterity_modifier();
    return value;
}

int32_t BattleBot::AC()
{
    auto value = 10;
    value += mFrame->AC_modifier();
    value += mArmor->AC_modifier();
    value += mWeapon->AC_modifier();
    value += mSpecialty->AC_modifier();
    return value;
}

int32_t BattleBot::num_damage_die()
{
    auto value = 0;
    value += mFrame->num_damage_dice_modifier();
    value += mArmor->num_damage_dice_modifier();
    value += mWeapon->num_damage_dice_modifier();
    value += mSpecialty->num_damage_dice_modifier();
    return std::max<int32_t>(value, 1);
}

int32_t BattleBot::damage_die()
{
    auto value = 0;
    value += mFrame->damage_die_modifier();
    value += mArmor->damage_die_modifier();
    value += mWeapon->damage_die_modifier();
    value += mSpecialty->damage_die_modifier();
    return std::max<int32_t>(value, 1);
}

int32_t BattleBot::num_attacks()
{
    auto value = 1;
    value += mFrame->num_attacks_modifier();
    value += mArmor->num_attacks_modifier();
    value += mWeapon->num_attacks_modifier();
    value += mSpecialty->num_attacks_modifier();
    return std::max<int32_t>(value, 1);
}

int32_t BattleBot::attack_modifier()
{
    auto value = 0;
    value += mFrame->attack_modifier();
    value += mArmor->attack_modifier();
    value += mWeapon->attack_modifier();
    value += mSpecialty->attack_modifier();
    return value;
}

int32_t BattleBot::damage_modifier()
{
    auto value = 0;
    value += mFrame->damage_modifier();
    value += mArmor->damage_modifier();
    value += mWeapon->damage_modifier();
    value += mSpecialty->damage_modifier();
    return value;
}

void BattleBot::set_frame(int32_t id)
{
    if(id < 0 || id >= mFrames.size())
    {
        mFrame = &mEmptyFrame;
        mConfig[0] = -1;
    }
    else
    {
        mFrame = mFrames[id];
        mConfig[0] = id;
    }
    calculate_health();
}

void BattleBot::set_armor(int32_t id)
{
    if(id < 0 || id >= mArmors.size())
    {
        mArmor = &mEmptyArmor;
        mConfig[1] = -1;
    }
    else
    {
        mArmor = mArmors[id];
        mConfig[1] = id;
    }
    calculate_health();
}

void BattleBot::set_weapon(int32_t id)
{
    if(id < 0 || id >= mWeapons.size())
    {
        mWeapon = &mEmptyWeapon;
        mConfig[2] = -1;
    }
    else
    {
        mWeapon = mWeapons[id];
        mConfig[2] = id;
    }
    calculate_health();
}

void BattleBot::set_specialty(int32_t id)
{
    if(id < 0 || id >= mSpecialties.size())
    {
        mSpecialty = &mEmptySpecialty;
        mConfig[3] = -1;
    }
    else
    {
        mSpecialty = mSpecialties[id];
        mConfig[3] = id;
    }
    calculate_health();
}

std::vector<Action> BattleBot::get_frame_actions(int32_t key_base)
{
    std::vector<Action> actions;
    auto iter = 0;
    for(auto item : mFrames)
    {
        auto newAction = Action(item->name(), key_base + iter, item->description());
        actions.push_back(newAction);
        iter++;
    }
    return actions;
}

std::vector<Action> BattleBot::get_armor_actions(int32_t key_base)
{
    std::vector<Action> actions;
    auto iter = 0;
    for(auto item : mArmors)
    {
        auto newAction = Action(item->name(), key_base + iter, item->description());
        actions.push_back(newAction);
        iter++;
    }
    return actions;
}

std::vector<Action> BattleBot::get_weapon_actions(int32_t key_base)
{
    std::vector<Action> actions;
    auto iter = 0;
    for(auto item : mWeapons)
    {
        auto newAction = Action(item->name(), key_base + iter, item->description());
        actions.push_back(newAction);
        iter++;
    }
    return actions;
}

std::vector<Action> BattleBot::get_specialty_actions(int32_t key_base)
{
    std::vector<Action> actions;
    auto iter = 0;
    for(auto item : mSpecialties)
    {
        auto newAction = Action(item->name(), key_base + iter, item->description());
        actions.push_back(newAction);
        iter++;
    }
    return actions;
}

void BattleBot::match_configuration(BattleBot& other)
{
    set_frame(other.mConfig[0]);
    set_armor(other.mConfig[1]);
    set_weapon(other.mConfig[2]);
    set_specialty(other.mConfig[3]);
}

void BattleBot::attack()
{
    json attackData;

    for(auto i = 0; i < num_attacks(); ++i)
    {
        attackData["attacker"] = name();
        attackData["attack"] = mRunner.roll(1, 20, attack_modifier());
        attackData["damage"] = mRunner.roll(num_damage_die(), damage_die(), damage_modifier());

        mRunner.react_bots(this, attackData);
    }
}

void BattleBot::calculate_health()
{
    // Unless they are all initialized, don't touch them.
    if(mFrame != nullptr && mArmor != nullptr && mWeapon != nullptr && mSpecialty != nullptr)
    {
        mHealth = 50 + constitution() * 5;
    }
}

void BattleBot::destroy_items()
{
    destroy_frame();
    destroy_armor();
    destroy_weapon();
    destroy_specialty();
}

void BattleBot::destroy_frame()
{
    for(auto itemptr : mFrames)
    {
        delete itemptr;
    }
}

void BattleBot::destroy_armor()
{
    for(auto itemptr : mArmors)
    {
        delete itemptr;
    }
}

void BattleBot::destroy_weapon()
{
    for(auto itemptr : mWeapons)
    {
        delete itemptr;
    }
}

void BattleBot::destroy_specialty()
{
    for(auto itemptr : mSpecialties)
    {
        delete itemptr;
    }
}


void BattleBot::fill_empty_items()
{
    set_frame(-1);
    set_armor(-1);
    set_weapon(-1);
    set_specialty(-1);
}

void BattleBot::init_items()
{
    init_frame_items();
    init_armor_items();
    init_weapon_items();
    init_specialty_items();
}

void BattleBot::init_frame_items()
{
    for(auto item : mFrames)
    {
        item->set_battlebot(this);
    }
    set_frame(-1);
}

void BattleBot::init_armor_items()
{
    for(auto item : mArmors)
    {
        item->set_battlebot(this);
    }
    set_armor(-1);
}

void BattleBot::init_weapon_items()
{
    for(auto item : mWeapons)
    {
        item->set_battlebot(this);
    }
    set_weapon(-1);
}

void BattleBot::init_specialty_items()
{
    for(auto item : mSpecialties)
    {
        item->set_battlebot(this);
    }
    set_specialty(-1);
}
