#ifndef _BATTLEBOT_ITEM_H
#define _BATTLEBOT_ITEM_H

#include <string>

namespace bots {

    class BattleBot;

    class BattleBotItem
    {
        public:

            BattleBotItem(std::string name, std::string description) : 
            mName(name), 
            mDescription(description),
            mAttachedBot(nullptr) 
            {};

            inline std::string name() { return mName; }
            inline std::string description() { return mName; }
            inline void setBattleBot(BattleBot* bot) { mAttachedBot = bot; } 
            std::string stat_display();

            inline virtual int32_t constitution_modifier() { return 0; }
            inline virtual int32_t strength_modifier() { return 0; }
            inline virtual int32_t dexterity_modifier() { return 0; }
            inline virtual int32_t AC_modifier() { return 0; }
            inline virtual int32_t num_damage_dice_modifier() { return 0; }
            inline virtual int32_t damage_die_modifier() { return 0; }
            inline virtual int32_t attack_modifier() { return 0; }
            inline virtual int32_t damage_modifier() { return 0; }

        protected:
            BattleBot* mAttachedBot;

        private:
            std::string mName;
            std::string mDescription;

    };
}

#endif