#include "battle_runner.h"

using namespace bots;

const uint32_t BattleRunner::sMaxBots = 2;
const uint32_t BattleRunner::sMinBots = 2;

BattleRunner::BattleRunner() : StateMachine("runner"), mFileLog("log.txt", mFileLog.trunc | mFileLog.out)
{
    mBots.resize(sMaxBots);

    // Set all the transitions
    set_initial(mStartState);
    add_transition(StartState::sPrepareForBattle, mStartState, mPrepareState);
    add_transition(PrepareState::sRestart, mPrepareState, mStartState);
    add_transition(PrepareState::sCreateBot, mPrepareState, mBuildBotState);
    add_transition(PrepareState::sBattleBegin, mPrepareState, mBattleState);
    add_transition(BuildBotState::sReturnToPrepare, mBuildBotState, mPrepareState);
    add_transition(BattleState::sBattleEnd, mBattleState, mResultsState);
    add_transition(ResultsState::sRestart, mResultsState, mStartState);

    if (!mFileLog.is_open()) {
        log("failed to open log");
    } else {
        log("opened log");
    }
}

BattleRunner::~BattleRunner()
{
    destroy_all_bots();
}

InteractableState& BattleRunner::current_interactable()
{
    return static_cast<InteractableState&>(current());
}

std::string BattleRunner::get_state_title()
{
    return current_interactable().title();
}

std::vector<std::string> BattleRunner::get_action_strings()
{
    return current_interactable().get_action_strings();
}

std::vector<std::string> BattleRunner::get_display()
{
    return current_interactable().get_display();
}

std::vector<std::string> BattleRunner::get_recent_log(uint32_t logs)
{
    std::vector<std::string> retLog;

    for(auto iter = mLog.crbegin(); iter != mLog.crend() && retLog.size() != logs; ++iter)
    {
        retLog.push_back(*iter);
    }

    return retLog;
}

const std::vector<std::string>& BattleRunner::get_full_log()
{
    return mLog;
}

int32_t BattleRunner::roll(uint32_t numDice, uint32_t dice, int32_t modifier)
{
    std::uniform_int_distribution<uint32_t> dist(1, dice);
    auto result = 0;
    for(auto i = 0; i < numDice; ++i)
    {
        result += dist(mRd);
    }
    return result + modifier;
}

void BattleRunner::log(const std::string& text)
{
    mLog.push_back(text);
    if(mFileLog.is_open())
    {
        mFileLog << text << std::endl;
    }
}

void BattleRunner::victory_log(BattleBot* bot)
{
    if(bot != nullptr)
    {
        std::string filename = "victor.log";
        std::fstream s(filename, std::fstream::out | std::fstream::app);
        if (s.is_open()) {
            auto botConfig = bot->get_config();
            if(botConfig.size() == 4)
            {
                s << std::to_string(botConfig[0]) << ", " 
                  << std::to_string(botConfig[1]) << ", " 
                  << std::to_string(botConfig[2]) << ", " 
                  << std::to_string(botConfig[3]) << std::endl;
            }
        }
    }
}

void BattleRunner::clear_log()
{
    mLog.clear();
}

BattleBot* BattleRunner::get_bot(uint32_t botId) 
{
    if(botId < mBots.size())
    {
        return mBots.at(botId);
    }

    return nullptr; 
}

uint32_t BattleRunner::get_num_bots()
{
    return get_valid_bots().size();
}

std::vector<BattleBot*> BattleRunner::get_valid_bots()
{
    std::vector<BattleBot*> validBots;
    for(const auto& bot : mBots)
    {
        if(bot != nullptr)
        {
            validBots.push_back(bot);
        }
    }
    return validBots;
}

void BattleRunner::create_bot(uint32_t botId, BattleBot* newBot)
{
    if(newBot == nullptr)
    {
        return;
    }

    if(botId >= 0 && botId < mBots.size())
    {
        destroy_bot(botId);
        mBots[botId] = newBot;
        log("Created Bot: " + mBots[botId]->name());
    }
    else 
    {
        delete newBot;
    }
}

void BattleRunner::destroy_bot(uint32_t botId)
{
    if(botId >= 0 && botId < mBots.size())
    {
        if(mBots[botId] != nullptr)
        {
            log("Destroying Bot: " + mBots[botId]->name());
            delete mBots[botId];
            mBots[botId] = nullptr;
        }
    }
}

void BattleRunner::destroy_all_bots()
{
    for(auto i = 0; i < mBots.size(); ++i)
    {
        destroy_bot(i);
    }
}

void BattleRunner::react_bots(BattleBot* attacker, json attackData)
{
    for(auto& bot : get_valid_bots())
    {
        bot->react(attacker, attackData);
    }
}
