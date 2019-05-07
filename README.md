
![](.github/IMG/challenger.svg)

![Travis (.com)](https://img.shields.io/travis/com/folksgl/challenger.svg)
![Coveralls github](https://img.shields.io/coveralls/github/folksgl/challenger.svg)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues)

Challenger is my own custom chess engine.

The goal of challenger is to take on the stockfish 10 chess engine, which is currently the best chess engine in the world.

## Progress

Current Level beaten: **None**

Percentage winning next level: **0%**
 
The progress of challenger will be gauged as follows: Challenger will play stockfish starting at its lowest level. Once the Challenger engine can beat the stockfish engine at the given level at least 60% of the time, the stockfish level will be increased, the "Current Level Beaten" label above will be updated, and a release of the code will be made to snapshot the progress made.
The "Percentage winning next level" label indicates challenger's progress in beating the next level of stockfish.

Percentages will be determined by playing 10 games and recording winnings.

## TODO
- [x] Implement base UCI compatibility
- [ ] Implement all UCI compatibility
- [x] Create board representation
- [x] Implement input move handling
- [ ] Implement move generation
- [ ] Search possible moves
- [x] Evaluate possible moves

## Installation

To install the challenger engine and run it against another chess engine, you will need to install a UCI (Universal Chess Interface) compatible chess program. I recommend Lucas Chess, as it is the one I use for challenger.

1) Download and install Lucas Chess
   1. Windows - navigate to the [Lucas Chess Website](https://lucaschess.pythonanywhere.com/index.html) and head to the downloads tab.
   2. Linux - Linux users will need to compile the source code (but hey, you're using linux... you know that's super simple!). You can follow the [installation guide from Lucas Chess's repository](https://github.com/lukasmonk/lucaschess/blob/master/Linux/LinuxInstallation.md)
   3. Mac/OSX - Well if you're using a Mac I'm afraid you're still going to have to compile the source code. Don't worry it's not as scary as it sounds. If you need help, just ask a Linux user! Unfortunately Lucas Chess does not provide a guide for OSX like it does for linux but luckily they're not too different. Just follow the Lunix guide using homebrew (or install apt-get if you're command-line savvy) for the package manager and you should be fine (note - I have not tested this so I won't be able to answer questions)
2) Starting with version 1.0, you can head over to the [release page](https://github.com/folksgl/challenger/releases) and download the challenger executable for your platform. Until then, clone and compile challenger. The following should work for most linux systems:
   ```
   git clone https://github.com/folksgl/challenger.git
   cd challenger/
   make
   ```
   For more make options, including building for developers please review the contributing page.
   
3) Open Lucas Chess and import the challenger engine executable. Navigate to Tools -> Engines -> External Engines and select to "Add" the challenger executable that was just downloaded or compiled. (If you compiled challenger, the executable will be in the challenger project build directory)

## Development and Contributing
Development for challenger will be done in C++, using the googletest framework for testing. Before opening issues or pull requests, please read the [contributing page](https://github.com/folksgl/challenger/blob/master/.github/CONTRIBUTING.md) for Challenger.

Contributions of all kinds are welcomed and encouraged. This project is far from finished and there are always portions of the code or documentation that can be improved.
