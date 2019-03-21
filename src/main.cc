#include <iostream>
#include <chrono>
#include <vector>

#include <ncurses.h>

#include "elma/elma.h"
#include "battle_runner.h"
#include "user_interface.h"
#include "key_capture.h"

using namespace elma;
using namespace bots;

int main() 
{
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
    
    Manager m;

    BattleRunner runner;
    KeyCapture keys(runner);
    UserInterface ui(runner);

    // Schedule all of the tasks.
    m.schedule(ui, 10ms)
     .schedule(keys, 10ms)
     .schedule(runner, 1s)
     .init()
     .run();

    endwin(); 
};