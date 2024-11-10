# Card Game Project

## How to Play

This is a two-player card game where each player tries to collect the most coins by building chains of similar cards. Players take turns drawing cards, choosing whether to play them, discard them, or add matching cards from the trade area. The game continues until the deck is empty or a player decides to quit by pressing "q". The player with the most coins at the end wins.

## Running the Game

To compile and run the game:
1. Compile:
   ```bash
   clang++ -std=c++14 main.cpp Table.cpp Player.cpp Deck.cpp CardFactory.cpp TradeArea.cpp Hand.cpp -o main
   ```
2. Run:
   ```bash
   ./main
   ```
