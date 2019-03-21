#include "key_capture.h"
#include <unistd.h>
#include <iostream>
#include <ncurses.h>

#include "battle_runner.h"

using namespace bots;

const std::string KeyCapture::sKeyPressEvent = "KeyPress";
const std::string KeyCapture::sKeyPressKey = "Key";

KeyCapture::KeyCapture(BattleRunner& runner) : Process("key capture"), mRunner(runner) 
{
};

KeyCapture::~KeyCapture() 
{
};

void KeyCapture::update() {

    // USER INPUT
    // get a character from the user, if one is ready.
    // If no character is ready, getch() returns ERR.
    int capture = getch();

    if(capture != ERR)
    {
        mRunner.act_on_key(capture);
    }
}

