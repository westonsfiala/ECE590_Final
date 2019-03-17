#ifndef _ACTION_H
#define _ACTION_H

#include <string>

namespace bots 
{
    class Action
    {
        public:
            Action(std::string name, int trigger, std::string output) 
            {
                mName = name;
                mTrigger = trigger;
                mOutput = output;
            };

            inline std::string name() const {return mName;}
            inline int trigger() const {return mTrigger;}
            inline std::string output() const {return mOutput;}

        private:

            static const int sPrepareKey;

            std::string mName;
            int mTrigger;
            std::string mOutput;

    };
}

#endif