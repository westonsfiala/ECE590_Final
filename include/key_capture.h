#ifndef _KEY_CAPTURE_H
#define _KEY_CAPTURE_H

#include "elma/elma.h"

namespace bots {

    using namespace std::chrono;
    using namespace elma;

    class KeyCapture : public Process {

        public:

        KeyCapture();

        void init() {}
        void start() {}
        void update();
        void stop() {}

    };

}

#endif