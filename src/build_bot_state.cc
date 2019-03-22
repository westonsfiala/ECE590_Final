#include "build_bot_state.h"

#include "battle_runner.h"

using namespace bots;

const std::string BuildBotState::sReturnToPrepare = "ReturnToPrepare";
const Action BuildBotState::sReturnToPrepareAction = Action("Return to prepare", 'r', sReturnToPrepare);

const uint32_t BuildBotState::sRandomBotKey = 'x';
const Action BuildBotState::sRandomBotAction = Action("Random Bot!", sRandomBotKey, sReturnToPrepare);

const uint32_t BuildBotState::sAcceptBuildKey = 'y';
const Action BuildBotState::sAcceptBuildAction = Action("Accept build", sAcceptBuildKey, sReturnToPrepare);

const uint32_t BuildBotState::sDenyBuildKey = 'n';
const Action BuildBotState::sDenyBuildAction = Action("Reject build", sDenyBuildKey, "");

const uint32_t BuildBotState::sLastBuildStepKey = 'b';
const Action BuildBotState::sLastBuildStepAction = Action("Back to last build step", sLastBuildStepKey, "");

const static uint32_t ASCII_1 = 49;

BuildBotState::BuildBotState() : InteractableState("Build a Bot State"), mTempBot("BuildingBot", battle_runner())
{
}

void BuildBotState::entry(const Event& e)
{
    battle_runner().log("Entering " + name());
    // Grab the bot value from the event.
    mBotId = e.value().get<uint32_t>();
    reset_configuration();
    build_actions();
    set_actions();
}
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
        titleStr = "Select the specialty of your bot.";
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

    auto loadout = mTempBot.get_detailed_loadout();

    for(auto item : loadout)
    {
        display.push_back(item);
    }

    return display;
}

void BuildBotState::act_on_key(int keyPress)
{
    auto numKey = keyPress - ASCII_1;

    if(mCurrentSeleciton == FRAME)
    {
        if(numKey >= 0 && numKey < mTempBot.get_num_frames())
        {
            mTempBot.set_frame(numKey);
            mCurrentSeleciton = ARMOR;
        }
    }
    else if(mCurrentSeleciton == ARMOR)
    {
        if(numKey >= 0 && numKey < mTempBot.get_num_armors())
        {
            mTempBot.set_armor(numKey);
            mCurrentSeleciton = WEAPON;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mTempBot.set_frame(-1);
            mCurrentSeleciton = FRAME;
        }
    }
    else if(mCurrentSeleciton == WEAPON)
    {
        if(numKey >= 0 && numKey < mTempBot.get_num_weapons())
        {
            mTempBot.set_weapon(numKey);
            mCurrentSeleciton = SPECIALTY;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mTempBot.set_armor(-1);
            mCurrentSeleciton = ARMOR;
        }
    }
    else if(mCurrentSeleciton == SPECIALTY)
    {
        if(numKey >= 0 && numKey < mTempBot.get_num_specialties())
        {
            mTempBot.set_specialty(numKey);
            mCurrentSeleciton = DONE;
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mTempBot.set_weapon(-1);
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
        }
        else if(keyPress == sLastBuildStepKey)
        {
            mTempBot.set_specialty(-1);
            mCurrentSeleciton = SPECIALTY;
        }
    }

    if(keyPress == sRandomBotKey && mCurrentSeleciton != DONE)
    {
        mTempBot.set_frame(battle_runner().roll(1, mTempBot.get_num_frames(), -1));
        mTempBot.set_armor(battle_runner().roll(1, mTempBot.get_num_armors(), -1));
        mTempBot.set_weapon(battle_runner().roll(1, mTempBot.get_num_weapons(), -1));
        mTempBot.set_specialty(battle_runner().roll(1, mTempBot.get_num_specialties(), -1));
        build_bot_from_configuration();
    }

    set_actions();
    process_key(keyPress);
}

void BuildBotState::set_actions()
{
    mActions.clear();

    if(mCurrentSeleciton == FRAME)
    {
        mActions.push_back(sReturnToPrepareAction);
        mActions.push_back(sRandomBotAction);
        for(auto action : mFrameActions)
        {
            mActions.push_back(action);
        }
    }
    else if(mCurrentSeleciton == ARMOR)
    {
        mActions.push_back(sReturnToPrepareAction);
        mActions.push_back(sRandomBotAction);
        mActions.push_back(sLastBuildStepAction);
        for(auto action : mArmorActions)
        {
            mActions.push_back(action);
        }
    }
    else if(mCurrentSeleciton == WEAPON)
    {
        mActions.push_back(sReturnToPrepareAction);
        mActions.push_back(sRandomBotAction);
        mActions.push_back(sLastBuildStepAction);
        for(auto action : mWeaponActions)
        {
            mActions.push_back(action);
        }
    }
    else if(mCurrentSeleciton == SPECIALTY)
    {
        mActions.push_back(sReturnToPrepareAction);
        mActions.push_back(sRandomBotAction);
        mActions.push_back(sLastBuildStepAction);
        for(auto action : mSpecialtyActions)
        {
            mActions.push_back(action);
        }
    }
    else if(mCurrentSeleciton == DONE)
    {
        mActions.push_back(sLastBuildStepAction);
        mActions.push_back(sAcceptBuildAction);
        mActions.push_back(sDenyBuildAction);
    }
}

void BuildBotState::build_actions()
{
    mFrameActions = mTempBot.get_frame_actions(ASCII_1);
    mArmorActions = mTempBot.get_armor_actions(ASCII_1);
    mWeaponActions = mTempBot.get_weapon_actions(ASCII_1);
    mSpecialtyActions = mTempBot.get_specialty_actions(ASCII_1);
}

void BuildBotState::reset_configuration()
{
    mCurrentSeleciton = FRAME;
    mTempBot.reset();
}

void BuildBotState::build_bot_from_configuration()
{
    auto botname = "Bot" + std::to_string(mBotId + 1);
    auto newBot = new BattleBot(botname, battle_runner());

    newBot->match_configuration(mTempBot);

    battle_runner().create_bot(mBotId, newBot);
}