#ifndef _BATTLE_RUNNER_H
#define _BATTLE_RUNNER_H

#include <random>
#include <array>
#include <fstream>

#include "elma/elma.h"

#include "battlebot.h"

#include "start_state.h"
#include "prepare_state.h"
#include "battle_state.h"
#include "results_state.h"
#include "build_bot_state.h"

using namespace elma;

namespace bots
{
    //! Class that controls the entire battle simulation.
    
    //! Is built of different states that talk to the battle runner to work.
    class BattleRunner : public StateMachine
    {
        public:

            //! Constructor
            //! Creates all states and sets up log files.
            BattleRunner();

            //! Destructor
            //! Destroys all bots that are still existing.
            ~BattleRunner();

            //! Getter
            //! Gets the state that the battle runner is currently in.
            InteractableState& current_interactable();

            //! Getter
            //! \return Title of the current state.
            std::string get_state_title();

            //! Getter
            //! \return All action strings of the current state.
            std::vector<std::string> get_action_strings();
            
            //! Getter
            //! \return All action keys of the current state.
            std::vector<int32_t> get_action_keys();

            //! Getter
            //! \return Display lines of the current state.
            std::vector<std::string> get_display();

            //! Gets the most recent logs from the master log in reverse order.
            //! \param logs The number of logs to get
            //! \return The most recent logs in reverse order. Will never return more logs than what exists.
            std::vector<std::string> get_recent_log(uint32_t logs);

            //! Gets all logs from the.
            //! \return All logs for this battle runner.
            const std::vector<std::string>& get_full_log();

            //! Acts on the given key. 
            //! If key matches an action, performs that action.
            //! \param Integer representation of a character key press.
            void act_on_key(int32_t key); 

            //! generates a random number based on the given values.
            //! \param numDice How many random numbers to add together.
            //! \param dice Max number that can be rolled minimum is 1.
            //! \param modifier Number to add to the result of the random rolls.
            //! \return random number generated with the following roll {\p numDice}d{\p dice} + {\p modifier}. i.e 1d6 + 1
            int32_t roll(uint32_t numDice, uint32_t dice, int32_t modifier);

            //! Logs the given text.
            //! \param text String to log.
            void log(const std::string& text);

            //! Log the victor of the battle. Used for balance & stat purposes.
            //! \param bot Victor of the battle. If null, no entry is written.
            void victory_log(BattleBot* bot);

            //! Clears away the log.
            void clear_log();

            //! Disables the log.
            void disable_log();

            //! Enables the log. Default.
            void enable_log();

            //! Gets the bot with the given ID.
            //! \param botId ID of the bot that will be gotten.
            //! \return Bot that has the given ID. If no bot has this ID, returns nullptr.
            BattleBot* get_bot(uint32_t botId);

            //! Getter
            //! \return Number of bots that are tracked.
            uint32_t get_num_bots();

            //! Getter
            //! \return All of the bots that are tracked and valid.
            std::vector<BattleBot*> get_valid_bots();

            //! Starts tracking the given bot with the given ID. If a bot already exists with that ID, destroys it first.
            //! \param botId ID to give the created bot.
            //! \param newBot Bot that has been allocated and will now be tracked.
            void create_bot(uint32_t botId, BattleBot* newBot);

            //! Destroys the bot with the given ID.
            //! \param botId ID of the bot to destroy.
            void destroy_bot(uint32_t botId);

            //! Destroys all bots that are tracked.
            void destroy_all_bots();

            //! Calls into all bots with the given values.
            //! \param attacker Bot that generated the attackData.
            //! \param attackData Data that will be passed to the bots to see how they react.
            void react_bots(BattleBot* attacker, json attackData);

            //! The maximum number of allowed bots.
            const static uint32_t sMaxBots;
            //! The minimum number of bots for a battle.
            const static uint32_t sMinBots;

        private:
            StartState mStartState;
            PrepareState mPrepareState;
            BattleState mBattleState;
            ResultsState mResultsState;
            BuildBotState mBuildBotState;

            std::vector<BattleBot*> mBots;

            std::random_device mRd;

            std::vector<std::string> mLog;
            std::fstream mFileLog;
            std::fstream mVictorFileLog;
            bool mLoggingEnabled;
    };
}

#endif