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

    m.schedule(ui, 10ms)
     .schedule(runner, 1s)
     .schedule(keys, 10ms);

    runner.setup(m);

    m.init()
     .run();

    endwin(); 
};