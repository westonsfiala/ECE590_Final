#include "user_interface.h"
#include <ncurses.h>

using namespace bots;

UserInterface::UserInterface(BattleRunner& runner) : Process("user input"), mRunner(runner) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
};

void UserInterface::update() 
{
    clear();

    mvprintw(1,1,"Battle Runner is in development.");

    mvprintw(3,1,mRunner.get_state_name().c_str());
    mvprintw(4,1,mRunner.get_action_string().c_str());

    auto line = 6;
    for(auto displayLine : mRunner.get_display())
    {
        mvprintw(line,1,displayLine.c_str());
        ++line;
    }

}