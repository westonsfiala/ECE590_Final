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
    KeyCapture keys;
    UserInterface ui(runner);

    m.schedule(ui, 10_ms)
     .schedule(runner, 10_ms)  
     .schedule(keys, 10_ms)     
     .init()
     .run();

    endwin(); 
};