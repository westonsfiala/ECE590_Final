#include "build_bot_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string BuildBotState::sReturnToPrepare = "ReturnToPrepare";
const Action BuildBotState::sReturnToPrepareAction = Action("Return to prepare", 'r', sReturnToPrepare);

const uint32_t BuildBotState::sRandomBotKey = 'x';
const Action BuildBotState::sRandomBotAction = Action("Random Bot!", sRandomBotKey, sReturnToPrepare);

const uint32_t BuildBotState::sAcceptBuildKey = 'y';
const Action BuildBotState::sAcceptBuildAction = Action("Accept build?", sAcceptBuildKey, sReturnToPrepare);

const uint32_t BuildBotState::sDenyBuildKey = 'n';
const Action BuildBotState::sDenyBuildAction = Action("Reject build?", sDenyBuildKey, "");

const uint32_t BuildBotState::sLastBuildStepKey = 'b';
const Action BuildBotState::sLastBuildStepAction = Action("Back to last build step", sLastBuildStepKey, "");

const static uint32_t ASCII_0 = 48;

// Config slot numbers
const static uint32_t FRAME_SLOT = 0;
const static uint32_t ARMOR_SLOT = 1;
const static uint32_t WEAPON_SLOT = 2;
const static uint32_t SPECIALTY_SLOT = 3;

// Actions for the frame designs
const static uint32_t ULTRA_LIGHT_FRAME_KEY = '1';
const static Action ULTRA_LIGHT_FRAME = Action("Ultra Light Weight Frame", ULTRA_LIGHT_FRAME_KEY, "");
const static uint32_t LIGHT_FRAME_KEY = '2';
const static Action LIGHT_FRAME = Action("Light Weight Frame", LIGHT_FRAME_KEY, "");
const static uint32_t MEDIUM_FRAME_KEY = '3';
const static Action MEDIUM_FRAME = Action("Medium Weight Frame", MEDIUM_FRAME_KEY, "");
const static uint32_t HEAVY_FRAME_KEY = '4';
const static Action HEAVY_FRAME = Action("Heavy Weight Frame", HEAVY_FRAME_KEY, "");
const static uint32_t ULTRA_HEAVY_FRAME_KEY = '5';
const static Action ULTRA_HEAVY_FRAME = Action("Ultra Heavy Weight Frame", ULTRA_HEAVY_FRAME_KEY, "");

// Actions for the Armor design
const static uint32_t LIGHT_ARMOR_KEY = '1';
const static Action LIGHT_ARMOR = Action("Light Armor", LIGHT_ARMOR_KEY, "");
const static uint32_t MEDIUM_ARMOR_KEY = '2';
const static Action MEDIUM_ARMOR = Action("Medium Armor", MEDIUM_ARMOR_KEY, "");
const static uint32_t HEAVY_ARMOR_KEY = '3';
const static Action HEAVY_ARMOR = Action("Heavy Armor", HEAVY_ARMOR_KEY, "");

// Actions for the weapon design
const static uint32_t DAGGER_KEY = '1';
const static Action DAGGER = Action("Dagger", DAGGER_KEY, "");
const static uint32_t MACE_KEY = '2';
const static Action MACE = Action("Mace", MACE_KEY, "");
const static uint32_t LONGSWORD_KEY = '3';
const static Action LONGSWORD = Action("Longsword", LONGSWORD_KEY, "");
const static uint32_t AXE_KEY = '4';
const static Action AXE = Action("Axe", AXE_KEY, "");
const static uint32_t GREATSWORD_KEY = '5';
const static Action GREATSWORD = Action("Greatsword", GREATSWORD_KEY, "");

// Actions for the specialty design
const static uint32_t HARDENED_ARMOR_KEY = '1';
const static Action HARDENED_ARMOR = Action("Hardened Armor", HARDENED_ARMOR_KEY, "");
const static uint32_t GUIDED_STRIKE_KEY = '2';
const static Action GUIDED_STRIKE = Action("Guided Strike", GUIDED_STRIKE_KEY, "");
const static uint32_t BRUTAL_BLOWS_KEY = '3';
const static Action BRUTAL_BLOWS = Action("Brutal Blows", BRUTAL_BLOWS_KEY, "");

BuildBotState::BuildBotState() : InteractableState("Build a Bot State"), mTempBot("BuildingBot", battle_runner())
{
}

void BuildBotState::entry(const Event& e)
{
    battle_runner().log("Entering " + name());
    // Grab the bot value from the event.
    mBotId = e.value().get<uint32_t>();
    reset_configuration();
    set_actions();
}

void BuildBotState::during()
{

}      

void BuildBotState::exit(const Event& e)
{

}

std::string BuildBotState::title()
{
    std::string titleStr;
    if(mCurrentSeleciton == FRAME)
    {
        titleStr = "Select the frame of your bot.";
    }
    else if(mCurrentSeleciton == ARMOR)
    {
        titleStr = "Select the armor of your bot.";
    }
    else if(mCurrentSeleciton == WEAPON)
    {
        titleStr = "Select the weapon of your bot.";
    }
    else if(mCurrentSeleciton == SPECIALTY)
    {
        titleStr = "Select the specialty that your bot has.";
    }
    else if(mCurrentSeleciton == DONE)
    {
        titleStr = "Will this bot work?";
    }
    return titleStr;
}

std::vector<std::string> BuildBotState::get_display()
{
    std::vector<std::string> display;

    display.push_back(mTempBot.display());
    
    display.push_back("Frame config = " + std::to_string(mConfiguration[FRAME_SLOT]));
    display.push_back("Armor config = " + std::to_string(mConfiguration[ARMOR_SLOT]));
    display.push_back("Weapon config = " + std::to_string(mConfiguration[WEAPON_SLOT]));
    display.push_back("Specialty config = " + std::to_string(mConfiguration[SPECIALTY_SLOT]));

    return display;
}

void BuildBotState::act_on_key(int keyPress)
{
    auto numKey = keyPress - ASCII_0;

    if(mCurrentSeleciton == FRAME)
    {
        if(keyPress >= ULTRA_LIGHT_FRAME_KEY && keyPress <= ULTRA_HEAVY_FRAME_KEY)
        {
            mConfiguration[FRAME_SLOT] = numKey;
            mCurrentSeleciton = ARMOR;
        }
    }
    else if(mCurrentSeleciton == ARMOR)
    {
        if(keyPress >= LIGHT_ARMOR_KEY && keyPress <= HEAVY_ARMOR_KEY)
        {
            mConfiguration[ARMOR_SLOT] = numKey;
            mCurrentSeleciton = WEAPON;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mConfiguration[FRAME_SLOT] = -1;
            mCurrentSeleciton = FRAME;
        }
    }
    else if(mCurrentSeleciton == WEAPON)
    {
        if(keyPress >= DAGGER_KEY && keyPress <= GREATSWORD_KEY)
        {
            mConfiguration[WEAPON_SLOT] = numKey;
            mCurrentSeleciton = SPECIALTY;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mConfiguration[ARMOR_SLOT] = -1;
            mCurrentSeleciton = ARMOR;
        }
    }
    else if(mCurrentSeleciton == SPECIALTY)
    {
        if(keyPress >= HARDENED_ARMOR_KEY && keyPress <= BRUTAL_BLOWS_KEY)
        {
            mConfiguration[SPECIALTY_SLOT] = numKey;
            mCurrentSeleciton = DONE;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mConfiguration[WEAPON_SLOT] = -1;
            mCurrentSeleciton = WEAPON;
        }
    }
    else if(mCurrentSeleciton == DONE)
    {
        if(keyPress == sDenyBuildKey)
        {
            reset_configuration();
        }
        else if(keyPress == sAcceptBuildKey)
        {
            build_bot_from_configuration();
            // Don't return here so that we can emit the signal down below.
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mConfiguration[SPECIALTY_SLOT] = -1;
            mCurrentSeleciton = SPECIALTY;
        }
    }

    if(keyPress == sRandomBotKey)
    {
        mConfiguration[FRAME_SLOT] = battle_runner().roll(1,ULTRA_HEAVY_FRAME_KEY - ASCII_0, 0);
        mConfiguration[ARMOR_SLOT] = battle_runner().roll(1,HEAVY_ARMOR_KEY - ASCII_0, 0);
        mConfiguration[WEAPON_SLOT] = battle_runner().roll(1,GREATSWORD_KEY - ASCII_0, 0);
        mConfiguration[SPECIALTY_SLOT] = battle_runner().roll(1,BRUTAL_BLOWS_KEY - ASCII_0, 0);
        build_bot_from_configuration();
    }

    set_actions();
    apply_bot_config(&mTempBot);

    process_key(keyPress);
}

void BuildBotState::set_actions()
{
    mActions.clear();

    mActions.push_back(sReturnToPrepareAction);
    mActions.push_back(sRandomBotAction);

    if(mCurrentSeleciton == FRAME)
    {
        mActions.push_back(ULTRA_LIGHT_FRAME);
        mActions.push_back(LIGHT_FRAME);
        mActions.push_back(MEDIUM_FRAME);
        mActions.push_back(HEAVY_FRAME);
        mActions.push_back(ULTRA_HEAVY_FRAME);
    }
    else if(mCurrentSeleciton == ARMOR)
    {
        mActions.push_back(sLastBuildStepAction);
        mActions.push_back(LIGHT_ARMOR);
        mActions.push_back(MEDIUM_ARMOR);
        mActions.push_back(HEAVY_ARMOR);
    }
    else if(mCurrentSeleciton == WEAPON)
    {
        mActions.push_back(sLastBuildStepAction);
        mActions.push_back(DAGGER);
        mActions.push_back(MACE);
        mActions.push_back(LONGSWORD);
        mActions.push_back(AXE);
        mActions.push_back(GREATSWORD);
    }
    else if(mCurrentSeleciton == SPECIALTY)
    {
        mActions.push_back(sLastBuildStepAction);
        mActions.push_back(HARDENED_ARMOR);
        mActions.push_back(GUIDED_STRIKE);
        mActions.push_back(BRUTAL_BLOWS);
    }
    else if(mCurrentSeleciton == DONE)
    {
        mActions.push_back(sLastBuildStepAction);
        mActions.push_back(sAcceptBuildAction);
        mActions.push_back(sDenyBuildAction);
    }
}

void BuildBotState::apply_bot_config(BattleBot* bot)
{
    if(bot != nullptr)
    {
        bot->reset();
        bot->mConfig = mConfiguration;
        apply_bot_frame(bot);
        apply_bot_armor(bot);
        apply_bot_weapon(bot);
        apply_bot_specialty(bot);
    }
}

void BuildBotState::apply_bot_frame(BattleBot* bot)
{
    auto config = mConfiguration[FRAME_SLOT];
    if(config == ULTRA_LIGHT_FRAME_KEY - ASCII_0)
    {
        bot->mDexterity += 4;
        bot->mStrength += 0;
        bot->mConstitution += -2;
    }
    else if(config == LIGHT_FRAME_KEY - ASCII_0)
    {
        bot->mDexterity += 3;
        bot->mStrength += 1;
        bot->mConstitution += -1;
    }
    else if(config == MEDIUM_FRAME_KEY - ASCII_0)
    {
        bot->mDexterity += 2;
        bot->mStrength += 2;
        bot->mConstitution += 0;
    }
    else if(config == HEAVY_FRAME_KEY - ASCII_0)
    {
        bot->mDexterity += 1;
        bot->mStrength += 3;
        bot->mConstitution += 1;
    }
    else if(config == ULTRA_HEAVY_FRAME_KEY - ASCII_0)
    {
        bot->mDexterity += 0;
        bot->mStrength += 4;
        bot->mConstitution += 2;
    }

    bot->mHealth += bot->mConstitution * 5;
}

void BuildBotState::apply_bot_armor(BattleBot* bot)
{
    auto config = mConfiguration[ARMOR_SLOT];
    if(config == LIGHT_ARMOR_KEY - ASCII_0)
    {
        bot->mAC = 12 + bot->mDexterity;
        bot->mAttackBonus += 1;
    }
    else if(config == MEDIUM_ARMOR_KEY - ASCII_0)
    {
        bot->mAC = 14 + std::min<int32_t>(bot->mDexterity, 2);
    }
    else if(config == HEAVY_ARMOR_KEY - ASCII_0)
    {
        bot->mAC = 16;
        bot->mAttackBonus += -1;
    }
}

void BuildBotState::apply_bot_weapon(BattleBot* bot)
{
    auto config = mConfiguration[WEAPON_SLOT];
    if(config == DAGGER_KEY - ASCII_0)
    {
        bot->mAttackBonus += bot->mDexterity;
        bot->mDamageBonus += bot->mDexterity;
        bot->mNumDamageDice = 1;
        bot->mDamageDie = 4;
    }
    else if(config == MACE_KEY - ASCII_0)
    {
        bot->mAttackBonus += bot->mStrength;
        bot->mDamageBonus += bot->mStrength;
        bot->mNumDamageDice = 2;
        bot->mDamageDie = 4;
    }
    else if(config == LONGSWORD_KEY - ASCII_0)
    {
        bot->mAttackBonus += std::max<int32_t>(bot->mDexterity, bot->mStrength);
        bot->mDamageBonus += std::max<int32_t>(bot->mDexterity, bot->mStrength);
        bot->mNumDamageDice = 1;
        bot->mDamageDie = 8;
    }
    else if(config == AXE_KEY - ASCII_0)
    {
        bot->mAttackBonus += bot->mStrength;
        bot->mDamageBonus += bot->mStrength;
        bot->mNumDamageDice = 1;
        bot->mDamageDie = 12;
    }
    else if(config == GREATSWORD_KEY - ASCII_0)
    {
        bot->mAttackBonus += bot->mStrength;
        bot->mDamageBonus += bot->mStrength;
        bot->mNumDamageDice = 2;
        bot->mDamageDie = 6;
    }
}

void BuildBotState::apply_bot_specialty(BattleBot* bot)
{
    auto config = mConfiguration[SPECIALTY_SLOT];
    if(config == HARDENED_ARMOR_KEY - ASCII_0)
    {
        bot->mAC += 1;
    }
    else if(config == GUIDED_STRIKE_KEY - ASCII_0)
    {
        bot->mAttackBonus += 1;
    }
    else if(config == BRUTAL_BLOWS_KEY - ASCII_0)
    {
        bot->mDamageBonus += 1;
    }
}

void BuildBotState::reset_configuration()
{
    mCurrentSeleciton = FRAME;
    mConfiguration = {-1, -1, -1, -1};
    mTempBot.reset();
}

void BuildBotState::build_bot_from_configuration()
{
    auto botname = "Bot" + std::to_string(mBotId + 1);
    auto newBot = new BattleBot(botname, battle_runner());

    apply_bot_config(newBot);

    battle_runner().create_bot(mBotId, newBot);
}