#include <stdio.h>
#include "gtest/gtest.h"

#include "elma/elma.h"
#include "battle_runner.h"
#include "user_interface.h"
#include "key_capture.h"

using namespace elma;
using namespace bots;

class RunnerTester : public Process
{
    public:
        RunnerTester(BattleRunner& runner, std::vector<int32_t> keys, bool loop) : mRunner(runner)
        {
            mKeys = keys;
            mKeyPos = 0;
            mLoop = loop;
        }

        void init() {}
        void start() {}
        void update() 
        {
            if(mKeyPos >= mKeys.size())
            {
                if(mLoop)
                {
                    mKeyPos = 0;
                }
                else
                {
                    halt();
                }
            }
            
            if(mKeyPos < mKeys.size())
            {
                mRunner.act_on_key(mKeys[mKeyPos]);
                mKeyPos++;
            }
        }
        void stop() {}

        BattleRunner& mRunner;
        std::vector<int32_t> mKeys;
        uint32_t mKeyPos;
        bool mLoop;
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
    RandomKeyPresser rPresser(runner, false, 100000);

    // Schedule all of the tasks.
    m.schedule(rPresser, 10ms)
     .schedule(runner, 10ms)
     .init()
     .use_simulated_time();

    EXPECT_NO_THROW(m.run());
}