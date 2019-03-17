#ifndef _ACTION_H
#define _ACTION_H

#include <string>

namespace bots 
{
    class Action
    {
        public:
            Action(std::string name, int trigger, std::string emit) 
            {
                mName = name;
                mTrigger = trigger;
                mEmit = emit;
            };

            inline std::string name() const {return mName;}
            inline int trigger() const {return mTrigger;}
            inline std::string emit() const {return mEmit;}

        private:

            std::string mName;
            int mTrigger;
            std::string mEmit;

    };
}

#endif