#include "user_interface.h"
#include <ncurses.h>

using namespace bots;

UserInterface::UserInterface(BattleRunner& runner) : Process("user input"), mRunner(runner) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
    start_color(); // Start color up.
    
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_YELLOW, COLOR_BLACK);
    init_pair(3, COLOR_WHITE, COLOR_BLACK);
};

void UserInterface::update() 
{
    clear();

    attron(COLOR_PAIR(1));
    mvprintw(1,1,mRunner.get_state_title().c_str());

    auto line = 2;
    attron(COLOR_PAIR(2));
    for(const auto& actionLine : mRunner.get_action_strings())
    {
        mvprintw(line,1,actionLine.c_str());
        ++line;
    }

    ++line;

    attron(COLOR_PAIR(3));
    for(auto displayLine : mRunner.get_display())
    {
        mvprintw(line,1,displayLine.c_str());
        ++line;
    }
}