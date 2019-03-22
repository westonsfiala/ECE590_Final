#ifndef _ACTION_H
#define _ACTION_H

#include <string>

namespace bots 
{

    //! A class for defining actions that the user can take.
    class Action
    {
        public:
            //! Constructor

            //! \param name Display name of the action. Shown to user.
            //! \param trigger Integer representation of a key press.
            //! \param emit Text to emit when the trigger is activated.
            Action(std::string name, int trigger, std::string emit) 
            {
                mName = name;
                mTrigger = trigger;
                mEmit = emit;
            };

            //! Getter
            //! \return Display name of the action. Shown to user.
            inline std::string name() const {return mName;}
            
            //! Getter
            //! \return Integer representation of a key press.
            inline int trigger() const {return mTrigger;}
            
            //! Getter
            //! \return Text to emit when the trigger is activated.
            inline std::string emit() const {return mEmit;}

        private:

            std::string mName;
            int mTrigger;
            std::string mEmit;
    };
}

#endif