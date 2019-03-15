#ifndef _BATTLE_RUNNER_H
#define _BATTLE_RUNNER_H

#include "elma/elma.h"

using namespace elma;

namespace bots
{
    class BattleRunner : public StateMachine
    {
        public:
            BattleRunner() : StateMachine("runner") {}
    };
}

#endif