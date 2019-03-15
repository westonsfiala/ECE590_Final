#include "key_capture.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

using namespace bots;

KeyCapture::KeyCapture() : Process("key capture") {};

void KeyCapture::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR (which is
    // ignored below since there is no condition in the switch statement)
    int c = getch();

    switch ( c ) {            
        case 's':
            emit(Event("start/stop"));
            break;
        case 'r':
            emit(Event("reset"));
            clear(); // Clear the screen of old stuff
            break;
        case 'l':
            emit(Event("lap"));
            break;
        case 'q':
            std::cout << "halting\n";
            halt();
            break;
    }
}