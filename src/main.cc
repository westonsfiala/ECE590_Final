#include <iostream>
#include <chrono>
#include <vector>

#include <ncurses.h>

#include "elma/elma.h"
#include "user_interface.h"
#include "key_capture.h"

using namespace elma;
using namespace bots;

int main() 
{
    Manager m;

    BattleRunner runner;
    KeyCapture keys(runner);
    UserInterface ui(runner);

    // Schedule all of the tasks.
    m.schedule(ui, 10ms)
     .schedule(runner, 1s)
     .schedule(keys, 10ms)
     .init()
     .run();

    endwin(); 
};