#include "battle_runner.h"

using namespace bots;

const std::string BattleRunner::sLogEvent = "Log";
const std::string BattleRunner::sLogClearEvent = "LogClear";

BattleRunner::BattleRunner() : StateMachine("runner")
{
    // Set all the transitions
    set_initial(mStartState);
    add_transition(StartState::sPrepareForBattle, mStartState, mPrepareState);
    add_transition(PrepareState::sRestart, mPrepareState, mStartState);
    add_transition(PrepareState::sBattleBegin, mPrepareState, mBattleState);
    add_transition(BattleState::sBattleEnd, mBattleState, mResultsState);
    add_transition(ResultsState::sRestart, mResultsState, mStartState);
}

void BattleRunner::setup(Manager& man)
{
    // Initialize the log
    watch(sLogEvent, [&](Event& e)
    {
        mLog.push_back(e.value().get<std::string>());
    });

    watch(sLogClearEvent, [&](Event& e)
    {
        mLog.clear();
    });

    // Initialize the bots.
    mBot1 = std::make_shared<BattleBot>("bot1", *this);
    mBot2 = std::make_shared<BattleBot>("bot2", *this);

    man.schedule(*mBot1, period());
    man.schedule(*mBot2, period());
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

