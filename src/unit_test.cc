#include <stdio.h>
#include "gtest/gtest.h"

#include "elma/elma.h"
#include "battle_runner.h"
#include "user_interface.h"
#include "key_capture.h"

using namespace elma;
using namespace bots;

class AllComboTester : public Process
{
    public:
        RunnerTester(BattleRunner& runner) : mRunner(runner)
        {
            mKeys = {};
            mKeyPos = 0;
            mFirstRun = true;
            mCount = 0;
            // Loop through all of the combinations 20 times to get a statistically signigicant result.
            mMaxcount = (5*5*5*5)*(5*5*5*5)*20;
        }

        void init() {}
        void start() {}
        void update() 
        {
            if(mKeyPos >= mKeys.size() || mFirstRun)
            {
                mFirstRun = false;
                mKeyPos = 0;
                auto tempCount = mCount;
                auto button = 0;

                mKeys.clear();

                mKeys.push_back('p') // Go to prepare
                mKeys.push_back('1') // Create bot 1
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select frame
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select armor
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select weapon
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select specialty
                mKeys.push_back('y'); // Accept build
                mKeys.push_back('2') // Create bot 2
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select frame
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select armor
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select weapon
                button = tempCount % 5;
                tempCount /= 5;
                mKeys.push_back('1' + button); // Select specialty
                mKeys.push_back('y'); // Accept build
                mKeys.push_back('b'); // Start the battle
                mKeys.push_back('p'); // Procede to results
                mKeys.push_back('r'); // Return to Start

                mCount++; // increment the count
            }

            if(mCount > mMaxcount)
            {
                halt();
            }

            if(mKeyPos < mKeys.size())
            {
                auto key = mKeys[mKeyPos];
                // If we are in the battle state and preparing for results, wait.
                if(key == 'p' // Procede for results
                && mRunner.get_action_keys().size() == 1 // In the battle state.
                && mRunner.get_action_keys()[0] == 'a') // ^
                {
                    // Do nothing till above is false;
                }
                else
                {
                    mRunner.act_on_key(key);
                    mKeyPos++;
                }
            }
        }
        void stop() {}

        BattleRunner& mRunner;
        std::vector<int32_t> mKeys;
        uint32_t mKeyPos;
        bool mFirstRun;
        uint64_t mCount;
        uint64_t mMaxCount;
};

class RunnerTester : public Process
{
    public:
        RunnerTester(BattleRunner& runner, std::vector<int32_t> keys, uint32_t loops) : mRunner(runner)
        {
            mKeys = keys;
            mKeyPos = 0;
            mCurrentLoops = 0;
            mLoops = loops;
        }

        void init() {}
        void start() {}
        void update() 
        {
            if(mKeyPos >= mKeys.size())
            {
                mKeyPos = 0;
                mCurrentLoops++;
            }

            if(mCurrentLoops >= mLoops)
            {
                halt();
            }

            if(mKeyPos < mKeys.size())
            {
                auto key = mKeys[mKeyPos];
                // If we are in the battle state and preparing for results, wait.
                if(key == 'p' // Procede for results
                && mRunner.get_action_keys().size() == 1 // In the battle state.
                && mRunner.get_action_keys()[0] == 'a') // ^
                {
                }
                else
                {
                    mRunner.act_on_key(key);
                    mKeyPos++;
                }
            }
        }
        void stop() {}

        BattleRunner& mRunner;
        std::vector<int32_t> mKeys;
        uint32_t mKeyPos;
        uint32_t mCurrentLoops;
        uint32_t mLoops;
};

class RandomKeyPresser : public Process
{
    public:
        RandomKeyPresser(BattleRunner& runner, bool onlyAllowed, uint32_t iterations) : mRunner(runner)
        {
            mOnlyAllowed = onlyAllowed;
            mCurrentIterations = 0;
            mIterations = iterations;
        }

        void init() {}
        void start() {}
        void update() 
        {
            if(mCurrentIterations > mIterations)
            {
                halt();
            }

            auto key = 0;
            if(mOnlyAllowed)
            {
                auto allowed = mRunner.get_action_keys();
                auto slot = mRunner.roll(1,allowed.size(), -1);
                key = allowed[slot];
            }
            else
            {
                key = mRunner.roll(1,256, -1);
            }

            // Don't act on the quit key.
            // If doing allowed only mode, don't act on the abort battle key.
            if(key != 'q' && (!mOnlyAllowed || key != 'a'))
            {
                mRunner.act_on_key(key);
                mCurrentIterations++;
            }
        }
        void stop() {}

        BattleRunner& mRunner;
        bool mOnlyAllowed;
        uint32_t mCurrentIterations;
        uint32_t mIterations;
};

TEST(runner, quit_immediately)
{
    Manager m;
    BattleRunner runner;
    RunnerTester rTester(runner, {'q'}, false);
    runner.disable_log();

    // Schedule all of the tasks.
    m.schedule(rTester, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}

TEST(runner, run_one_battle)
{
    Manager m;
    BattleRunner runner;
    runner.disable_log();

    RunnerTester rTester(runner, 
    {
        'p', // Go to Prepare
        '1', // Create bot1
        'x', // Random build
        '2', // Create bot2
        'x', // Random build
        'b', // Start the battle
        'p', // Procede to results
        'r', // Return to start
        'q' // Quit
    }, 
    1);

    // Schedule all of the tasks.
    m.schedule(rTester, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}

TEST(runner, run_30000_battles)
{
    Manager m;
    BattleRunner runner;
    runner.disable_log();

    RunnerTester rTester(runner, 
    {
        'p', // Go to Prepare
        '1', // Create bot1
        'x', // Random build
        '2', // Create bot2
        'x', // Random build
        'b', // Start the battle
        'p', // Procede to results
        'r' // Return to start
    }, 
    30000);

    // Schedule all of the tasks.
    m.schedule(rTester, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}

TEST(runner, pressRandomAllowed)
{
    Manager m;
    BattleRunner runner;
    RandomKeyPresser rPresser(runner, true, 100000);
    runner.disable_log();

    // Schedule all of the tasks.
    m.schedule(rPresser, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}

TEST(runner, pressRandom)
{
    Manager m;
    BattleRunner runner;
    RandomKeyPresser rPresser(runner, false, 1000000);
    runner.disable_log();

    // Schedule all of the tasks.
    m.schedule(rPresser, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}

TEST(runner, allComboTester)
{
    Manager m;
    BattleRunner runner;
    AllComboTester comboTester(runner);
    runner.disable_log();

    // Schedule all of the tasks.
    m.schedule(rPresser, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}