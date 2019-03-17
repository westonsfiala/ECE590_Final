#include "key_capture.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

using namespace bots;

const std::string KeyCapture::sKeyPressEvent = "KeyPress";
const std::string KeyCapture::sKeyPressKey = "Key";

KeyCapture::KeyCapture(BattleRunner& runner) : Process("key capture"), mRunner(runner) {};

void KeyCapture::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR.
    int capture = getch();

    if(capture == '0')
    {
        halt();
        return;
    }

    auto& currentState = mRunner.current_interactable();

    currentState.act_on_key(capture);
}