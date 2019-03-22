#ifndef _BATTLEBOT_ITEM_H
#define _BATTLEBOT_ITEM_H

#include <string>

namespace bots {

    class BattleBot;

    //! Items that can be added to a battle bot to modify its stats.
    
    //! There are four varieties: Frame, Armor, Weapon, and Specialty.
    class BattleBotItem
    {
        public:

            //! Constructor
            //! \param name Name of the item.
            //! \param description Description of the item.
            BattleBotItem(std::string name = "Empty", std::string description = "") : 
            mName(name), 
            mDescription(description),
            mAttachedBot(nullptr) 
            {};

            //! Getter
            //! \return Name of the item.
            inline std::string name() { return mName; }

            //! Getter
            //! \return Description of the item.
            inline std::string description() { return mDescription; }

            //! Setter
            //! \param Bot Sets the bot that the item is attached to. Used for determining stats.
            inline void set_battlebot(BattleBot* bot) { mAttachedBot = bot; } 
            
            //! Getter
            //! \return String representation of all the changes that an item gives.
            std::string stat_display();

            //! Getter
            //! \return Changes to the bots constitution.
            inline virtual int32_t constitution_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots strenth.
            inline virtual int32_t strength_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots dexterity.
            inline virtual int32_t dexterity_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots AC.
            inline virtual int32_t AC_modifier() { return 0; }

            //! Getter
            //! \return Changes to the number of dice rolled for damage.
            inline virtual int32_t num_damage_dice_modifier() { return 0; }

            //! Getter
            //! \return Changes to the dice rolled for damage.
            inline virtual int32_t damage_die_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots number of attacks per turn.
            inline virtual int32_t num_attacks_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots attack modifier.
            inline virtual int32_t attack_modifier() { return 0; }

            //! Getter
            //! \return Changes to the bots damage modifier.
            inline virtual int32_t damage_modifier() { return 0; }

        protected:
            BattleBot* mAttachedBot;

        private:
            std::string mName;
            std::string mDescription;

    };
}

#endif