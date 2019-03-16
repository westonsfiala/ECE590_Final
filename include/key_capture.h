#ifndef _KEY_CAPTURE_H
#define _KEY_CAPTURE_H

#include "elma/elma.h"

using namespace elma;
using namespace std::chrono;

namespace bots {

    class KeyCapture : public Process {

        public:

        KeyCapture();

        void init() {}
        void start() {}
        void update();
        void stop() {}

        const static std::string sKeyPressEvent;

    };

}

#endif