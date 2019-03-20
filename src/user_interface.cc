#include "user_interface.h"
#include <ncurses.h>

using namespace bots;

UserInterface::UserInterface(BattleRunner& runner) : Process("user input"), mRunner(runner) {
    initscr();   // Start ncurses
    timeout(1);  // Timeout for waiting for user input
    noecho();    // Do not echo user input to the screen
    curs_set(0); // Do not show the cursor
    start_color(); // Start color up.

    // Set up a bunch of colors that can be used.
    init_pair(1, COLOR_BLACK, COLOR_WHITE);
    init_pair(2, COLOR_RED, COLOR_BLACK);
    init_pair(3, COLOR_GREEN, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_BLUE, COLOR_BLACK);
    init_pair(6, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(7, COLOR_CYAN, COLOR_BLACK);
    init_pair(8, COLOR_WHITE, COLOR_BLACK);
};

void UserInterface::update() 
{
    clear();

    attron(COLOR_PAIR(7));
    print_line(1, mRunner.get_state_title());

    auto line = 2;

    attron(COLOR_PAIR(4));
    for(const auto& actionLine : mRunner.get_action_strings())
    {
        print_line(line,actionLine);
        ++line;
    }

    ++line;

    attron(COLOR_PAIR(8));
    for(auto displayLine : mRunner.get_display())
    {
        print_line(line,displayLine);
        ++line;
    }
}

void UserInterface::print_line(uint32_t row, const std::string& text)
{
    mvprintw(row,1,text.c_str());
}