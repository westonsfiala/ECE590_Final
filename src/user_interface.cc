#include "user_interface.h"
#include <ncurses.h>

using namespace bots;


const char UserInterface::sBeginRed = '[';
const char UserInterface::sEndRed = ']';

const char UserInterface::sBeginBlue = '(';
const char UserInterface::sEndBlue = ')';

const char UserInterface::sBeginGreen = '<';
const char UserInterface::sEndGreen = '>';

const char UserInterface::sBeginMagenta = '{';
const char UserInterface::sEndMagenta = '}';

UserInterface::UserInterface(BattleRunner& runner) : Process("user input"), mRunner(runner) {
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
    auto charLocation = 1;
    for(auto letter : text)
    {
        if(letter == sBeginRed)
        {
            attron(COLOR_PAIR(2));
        }
        else if (letter == sBeginBlue)
        {
            attron(COLOR_PAIR(5));
        }
        else if (letter == sBeginGreen)
        {
            attron(COLOR_PAIR(3));
        }
        else if (letter == sBeginMagenta)
        {
            attron(COLOR_PAIR(6));
        }
        else if(letter == sEndRed || letter == sEndBlue || letter == sEndGreen || letter == sEndMagenta)
        {
            attron(COLOR_PAIR(8));
        }
        else 
        {
            char str[2] = {letter, 0};
            mvprintw(row, charLocation, str);
            charLocation++;
        }
    }
}