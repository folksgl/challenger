
![](.github/IMG/challenger.svg)

[![Build Status](https://travis-ci.com/folksgl/challenger.svg?branch=master)](https://travis-ci.com/folksgl/challenger)
[![Coverage Status](https://coveralls.io/repos/github/folksgl/challenger/badge.svg?branch=master)](https://coveralls.io/github/folksgl/challenger?branch=master)
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

**IMPORTANT**

**Arena, the UCI GUI that challenger initially used to gauge its progress and play matches, has since become unavailable and the website returns http 500 responses. I am in the process of switching to a new GUI and will update the installation documentation accordingly.**

To install the challenger engine and run it against another chess engine, you will need to install a UCI (Universal Chess Interface) compatible chess program. I recommend Arena, as it is the one I use for challenger.

1) Download and Install [Arena](http://www.playwitharena.com/?Download).
2) Starting with version 1.0, you can head over to the [release page](https://github.com/folksgl/challenger/releases) and download the challenger executable for your platform. Until then, clone and compile challenger. The following should work for most linux systems:
   ```
   git clone https://github.com/folksgl/challenger.git
   cd challenger/
   make
   ```
   For more make options, including building for developers please review the contributing page.
   
3) Open Arena and import the challenger engine executable. Navigate to Engines -> Install New Engine and choose the challenger executable that was just compiled. (Will be in the challenger project build directory)

## Development and Contributing
Development for challenger will be done in C++, using the googletest framework for testing. Before opening issues or pull requests, please read the [contributing page](https://github.com/folksgl/challenger/blob/master/.github/CONTRIBUTING.md) for Challenger.

Contributions of all kinds are welcomed and encouraged. This project is far from finished and there are always portions of the code or documentation that can be improved.
