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
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
    Manager m;

    BattleRunner runner;
    bots::KeyCapture keys(runner);
    UserInterface ui(runner);

    // Schedule all of the tasks.
    m.schedule(runner, 10ms)
     .schedule(keys, 10ms)
     .schedule(ui, 10ms)
     .init()
     .run(10s);

    endwin(); 
}