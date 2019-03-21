#include <stdio.h>
#include "gtest/gtest.h"

#include <ncurses.h>

#include "elma/elma.h"
#include "battle_runner.h"
#include "user_interface.h"
#include "key_capture.h"

using namespace elma;
using namespace bots;

TEST(runner, one_run)
{
    Manager m;

    BattleRunner runner;

    // Schedule all of the tasks.
    m.schedule(runner, 10ms)
     .init()
     .run(1s);

    endwin(); 
}