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

    class BattleBot
    {
        public:

            BattleBot(string name, BattleRunner& runner);
            ~BattleBot();

            void reset();
            std::string name();
            std::string display();
            std::string get_battle_stats();
            std::string get_simple_loadout();
            std::vector<std::string> get_detailed_loadout();

            void trigger();
            void react(BattleBot* attacker, json attackData);

            bool is_dead() { return mHealth <= 0; }
            
            int32_t constitution();
            int32_t strength();
            int32_t dexterity();
            int32_t AC();
            int32_t num_damage_die();
            int32_t damage_die();
            int32_t num_attacks();
            int32_t attack_modifier();
            int32_t damage_modifier();

            void set_frame(int32_t id);
            void set_armor(int32_t id);
            void set_weapon(int32_t id);
            void set_specialty(int32_t id);

            int32_t get_num_frames() { return mFrames.size(); }
            int32_t get_num_armors() { return mArmors.size(); }
            int32_t get_num_weapons() { return mWeapons.size(); }
            int32_t get_num_specialties() { return mSpecialties.size(); }

            std::vector<Action> get_frame_actions(int32_t key_base);
            std::vector<Action> get_armor_actions(int32_t key_base);
            std::vector<Action> get_weapon_actions(int32_t key_base);
            std::vector<Action> get_specialty_actions(int32_t key_base);

            void match_configuration(BattleBot& other);
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

            FrameItem* mFrame;
            ArmorItem* mArmor;
            WeaponItem* mWeapon;
            SpecialtyItem* mSpecialty;

            FrameItem mEmptyFrame;
            ArmorItem mEmptyArmor;
            WeaponItem mEmptyWeapon;
            SpecialtyItem mEmptySpecialty;
            
            std::vector<FrameItem*> mFrames;
            std::vector<ArmorItem*> mArmors;
            std::vector<WeaponItem*> mWeapons;
            std::vector<SpecialtyItem*> mSpecialties;

            std::vector<int32_t> mConfig;

            BattleRunner& mRunner;

            void calculate_health();
            void attack();

            void destroy_items();
            void destroy_frame();
            void destroy_armor();
            void destroy_weapon();
            void destroy_specialty();

            void fill_empty_items();
            void init_items();
            void init_frame_items();
            void init_armor_items();
            void init_weapon_items();
            void init_specialty_items();
    };
}

#endif