#include "battle_runner.h"

using namespace bots;

const uint32_t BattleRunner::sMaxBots = 2;
const uint32_t BattleRunner::sMinBots = 2;

BattleRunner::BattleRunner() : StateMachine("runner")
{
    mBots.resize(sMaxBots);

    // Set all the transitions
    set_initial(mStartState);
    add_transition(StartState::sPrepareForBattle, mStartState, mPrepareState);
    add_transition(PrepareState::sRestart, mPrepareState, mStartState);
    add_transition(PrepareState::sBattleBegin, mPrepareState, mBattleState);
    add_transition(BattleState::sBattleEnd, mBattleState, mResultsState);
    add_transition(ResultsState::sRestart, mResultsState, mStartState);
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

std::string BattleRunner::get_action_string()
{
    return current_interactable().get_action_string();
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

int32_t BattleRunner::roll(uint32_t dice, int32_t modifier)
{
    std::uniform_int_distribution<uint32_t> dist(1, dice);
    return dist(mRd) + modifier;
}

void BattleRunner::log(const std::string& text)
{
    mLog.push_back(text);
}

void BattleRunner::clear_log()
{
    mLog.clear();
}

BattleBot* BattleRunner::get_bot(uint32_t botId) 
{
    if(botId > mBots.size())
    {
        return mBots.at(botId);
    }

    return nullptr; 
}

uint32_t BattleRunner::get_num_bots()
{
    int validBots = 0;
    for(const auto& bot : mBots)
    {
        if(bot != nullptr)
        {
            ++validBots;
        }
    }
    return validBots;
}

void BattleRunner::create_bot(uint32_t botId)
{
    if(botId >= 0 && botId < mBots.size())
    {
        destroy_bot(botId);
        mBots[botId] = new BattleBot("Bot" + std::to_string(botId), *this);
    }
}

void BattleRunner::destroy_bot(uint32_t botId)
{
    if(botId >= 0 && botId < mBots.size())
    {
        auto bot = mBots[botId];
        if(bot != nullptr)
        {
            delete bot;
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
