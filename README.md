
![](.github/IMG/challenger.svg)

![Travis (.com)](https://img.shields.io/travis/com/folksgl/challenger.svg)
![Coveralls github](https://img.shields.io/coveralls/github/folksgl/challenger.svg)
[![contributions welcome](https://img.shields.io/badge/contributions-welcome-brightgreen.svg?style=flat)](https://github.com/dwyl/esta/issues)

Challenger is my own custom chess engine.

The goal of challenger is to take on the stockfish 10 chess engine, which is currently the best chess engine in the world.

## Progress

Current level completed: **None**

Percentage winning next level: **0%**
 
The progress of challenger will be gauged as follows: Challenger will play stockfish starting at its lowest level. Once the Challenger engine can beat the stockfish engine at the given level at least 60% of the time, the stockfish level will be increased, the "Current level completed" label above will be updated, and a release of the code will be made to snapshot the progress made.
The "Percentage winning next level" label indicates challenger's progress in beating the next level of stockfish.

Percentages will be determined by playing 10 games and recording winnings.

## Ongoing Work:
- [ ] Implement all UCI compatibility
- [ ] Improve position evaluation
- [ ] Improve move generation
- [ ] General optimizations

## Installation

To install the challenger engine and run it against another chess engine, you will need to install a UCI (Universal Chess Interface) compatible chess program. I recommend Lucas Chess, as it is the one I use for challenger.

1) Download and install Arena
   1. Navigate to the [Arena Website](http://www.playwitharena.de/) and head to the downloads section.
   2. Unzip and install.
2) Head over to the [release page](https://github.com/folksgl/challenger/releases) and download the latest challenger executable for your platform. and compile challenger. The following should work for most linux systems:
   
3) Open Arena and import the challenger engine executable. Navigate to Engines -> Install new engine... and select the challenger executable that was just downloaded or compiled. (If you compiled challenger from source, the executable will be in the challenger project build directory)

## Development and Contributing
Development for challenger will be done in C++, using the googletest framework for testing. Before opening issues or pull requests, please read the [contributing page](https://github.com/folksgl/challenger/blob/master/.github/CONTRIBUTING.md) for Challenger.

Contributions of all kinds are welcomed and encouraged. This project is far from finished and there are always portions of the code or documentation that can be improved.
