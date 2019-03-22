#ifndef _BATTLEBOT_H
#define _BATTLEBOT_H

#include "elma/elma.h"
#include "frame_items.h"
#include "armor_items.h"
#include "weapon_items.h"
#include "specialty_items.h"
#include "action.h"

using namespace elma;

namespace bots {

    class BattleRunner;
    class BuildBotState;

    //! Class for defining a battler in the simulator.
    class BattleBot
    {
        public:

            //! Constructor
            //! \param name Name of the BattleBot.
            //! \param runner Battle Runner this bot is tied to.
            BattleBot(string name, BattleRunner& runner);

            //! Destructor
            ~BattleBot();

            //! Resets the bot by clearing away all items and clearing tracked stats.
            void reset();

            //! Getter
            //! \return Name of the bot.
            std::string name();

            //! Getter
            //! \return Display of the bots current battle abilities.
            std::string display();

            //! Getter
            //! \return String representing the actions that the battle bot took during the fight.
            std::string get_battle_stats();

            //! Getter
            //! \return String of the items loaded onto this bot.
            std::string get_simple_loadout();

            //! Getter
            //! \return Detailed descriptions of each item the bot has attached.
            std::vector<std::string> get_detailed_loadout();

            //! Tells the bot to take an action in the battle.
            void trigger();
            
            //! Reacts to the actions of a different battlebot.
            void react(BattleBot* attacker, json attackData);

            //! Checks if the bot is dead.
            //! \return If the bot is dead.
            bool is_dead() { return mHealth <= 0; }
            
            //! Getter
            //! \return Constitution of the bot.
            int32_t constitution();
            
            //! Getter
            //! \return Strength of the bot.
            int32_t strength();
            
            //! Getter
            //! \return Dexterity of the bot.
            int32_t dexterity();
            
            //! Getter
            //! \return AC of the bot. Helps determine if an attack hits or not.
            int32_t AC();
            
            //! Getter
            //! \return Number of damage die rolled.
            int32_t num_damage_die();
            
            //! Getter
            //! \return What damage die is rolled.
            int32_t damage_die();
            
            //! Getter
            //! \return Number of attacks made in one action.
            int32_t num_attacks();
            
            //! Getter
            //! \return Modifier added to attack rolls of the bot. Used to determine if an attack hits.
            int32_t attack_modifier();
            
            //! Getter
            //! \return Modifier added to the damage rolls of the bot.
            int32_t damage_modifier();

            //! Setter
            //! \param id ID of the frame item to use. If id does not point to a item id, sets empty item.
            void set_frame(int32_t id);

            //! Setter
            //! \param id ID of the armor item to use. If id does not point to a item id, sets empty item.
            void set_armor(int32_t id);

            //! Setter
            //! \param id ID of the weapon item to use. If id does not point to a item id, sets empty item.
            void set_weapon(int32_t id);

            //! Setter
            //! \param id ID of the specialty item to use. If id does not point to a item id, sets empty item.
            void set_specialty(int32_t id);

            //! Getter
            //! \return The number of frame items availale.
            int32_t get_num_frames() { return mFrames.size(); }

            //! Getter
            //! \return The number of armor items availale.
            int32_t get_num_armors() { return mArmors.size(); }

            //! Getter
            //! \return The number of weapon items availale.
            int32_t get_num_weapons() { return mWeapons.size(); }

            //! Getter
            //! \return The number of specialty items availale.
            int32_t get_num_specialties() { return mSpecialties.size(); }

            //! Getter
            //! \param key_base number to add to all the actions
            //! \return All of the actions for frame items in a contiguous block staring from \p key_base.
            std::vector<Action> get_frame_actions(int32_t key_base);

            //! Getter
            //! \param key_base number to add to all the actions
            //! \return All of the actions for armor items in a contiguous block staring from \p key_base.
            std::vector<Action> get_armor_actions(int32_t key_base);

            //! Getter
            //! \param key_base number to add to all the actions
            //! \return All of the actions for weapon items in a contiguous block staring from \p key_base.
            std::vector<Action> get_weapon_actions(int32_t key_base);

            //! Getter
            //! \param key_base number to add to all the actions
            //! \return All of the actions for specialty items in a contiguous block staring from \p key_base.
            std::vector<Action> get_specialty_actions(int32_t key_base);

            //! Matches the configuration of this bot to the given bot.
            //! \param other Bot to match configuration to.
            void match_configuration(BattleBot& other);

            //! Getter
            //! \return All attached item ids: frame, armor, weapon, specialty.
            std::vector<int32_t> get_config() { return mConfig; }

        protected:

            std::string mName;

            uint32_t mHealth;

            // Log variables
            uint32_t mAttacks;
            uint32_t mHits;
            uint32_t mDamageDealt;
            uint32_t mAttacksBlocked;
            uint32_t mKills;

            BattleBotItem* mFrame;
            BattleBotItem* mArmor;
            BattleBotItem* mWeapon;
            BattleBotItem* mSpecialty;

            BattleBotItem mEmptyItem;
            
            std::vector<BattleBotItem*> mFrames;
            std::vector<BattleBotItem*> mArmors;
            std::vector<BattleBotItem*> mWeapons;
            std::vector<BattleBotItem*> mSpecialties;

            std::vector<int32_t> mConfig;

            BattleRunner& mRunner;

            //! Sets maximum health based on constitution.
            void calculate_health();

            //! Performs the attack action and sends it to the battle runner.
            void attack();
            
            //! Helper method for getting the actions from an item list.
            //! \param key_base number to add to all the actions
            //! \param items BattleBot items that will be used to create actions.
            //! \return All of the actions for provided items in a contiguous block staring from \p key_base.
            std::vector<Action> get_item_actions(int32_t key_base, std::vector<BattleBotItem*>& items);

            //! Destroys all items and frees their memory. Only to be used bt the destructor.
            void destroy_items();

            //! Destroys all provided items and frees their memory. Only to be used bt the destructor.
            //! \param items Items to destroy.
            void destroy_items_helper(std::vector<BattleBotItem*>& items);

            //! Clears away all set items from the bot.
            void fill_empty_items();

            //! Initialized all items by setting this bot as their attached bot.
            void init_items();

            //! Initialized all items by setting this bot as their attached bot.
            //! \param items Items to attach to bot.
            void init_items_helper(std::vector<BattleBotItem*>& items);
    };
}

#endif