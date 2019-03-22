# ECE590_Final

This repo is for my final project in ECE590. The goal for this project is to create a 2D battle bot simulator. When the program starts, the user will select the parts they want to add to their battle bot. At completion of part selection, the battle will begin. A battle will involve their battle bot automatically moving though the displayed map and attempting to destroy the enemy battle bot. A battle ends when only one bot remains.

## Success

This project will be a success when a user is able to create their own battle bot and compete with it against other battle bots. This project will involve integration with the [ELMA](https://github.com/klavinslab/elma) manager, but will otherwise be coded from scratch in C++.

## Playing the game

To play the game, have docker installed on your machine and clone this repo. Open a console and navigate to the directory you cloned to. Use either the run.ps1 powershell script, or run.sh script. Either will get the game up and running. Follow the prompts on the screen to play the game. Have Fun!

## Milestones

1. Modify ELMA to run in simulated time instead of realtime. Allows for faster testing.

1. Create base classes for battle bots, and different weapons they can use.

1. Create 2D battle map for battle bots to fight in.

1. Develop display adapter for showing the battlebots in the arena.

1. Create command prompt for accepting user inputs while building battle bot.

1. Document how to create a battle bot and run the program.

1. Turn in the project on time! March 22nd 2019

## Progress updates

### 3/16/2019

1. Updated the elma [manager](elma/src/manager.cc) to run in simulated time through the use of `use_simulated_time()` and `use_real_time()`.
    * This code was pulled ints the master elma repo by the professor.
1. Updated the elma [manager](elma/src/manager.cc) to sleep until the next process is scheduled to run.
    * Only sleeps when running in realtime mode
    * [Pull request](https://github.com/klavinslab/elma/pull/6) has been submitted but no confirmation on if it will be accepted.
1. Created base classes for the battlebot simulator.
    * No funtionality in them yet, but they have been created
    * See src & include directories
1. Started looking at [ncurses](https://invisible-island.net/ncurses/man/ncurses.3x.html) documentation for how to do gui.

### 3/22/2019

Milestone updates and changes that occured while coding.

1. Simulated time works and has been tested in unit tests. (Completed)
1. Base classes have been created. There is 1 `BattleRunner`, 5 `states`, 1 `BattleBot`, and 4 `BattleBotItem` types. (Completed)
1. 2D map was considered, but deemed too difficult to complete in the time frame alloted. (Not Completed)
1. A battle state that shows the bots stats and a log of all their actions has been created and works. (Completed)
1. Used the ncurses library to get keys that are pressed by the user and acted on by the battle runner. (Completed)
1. Documentation has been created and is up to date. (Completed)
1. Project has been completed on time. (Completed)