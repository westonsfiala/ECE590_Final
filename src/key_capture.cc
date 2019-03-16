#include "key_capture.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

using namespace bots;

const std::string KeyCapture::sKeyPressEvent = "KeyPress";

KeyCapture::KeyCapture() : Process("key capture") {};

void KeyCapture::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR.
    int c = getch();

    switch ( c ) {
        case '0':
            halt();
            break;
        default:
            emit(Event("KeyPress", c));
            break;
    }
}