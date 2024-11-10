#include "Table.h"
#include "CardFactory.h"
#include <iostream>
#include <string>

int main() {
    // Initialize player names
    std::string player1, player2;
    std::cout << "Enter name for Player 1: ";
    std::cin >> player1;
    std::cout << "Enter name for Player 2: ";
    std::cin >> player2;

    // Create game table and deck from CardFactory
    Table gameTable(player1, player2);
    CardFactory* factory = CardFactory::getFactory();
    gameTable.getDeck() = factory->getDeck();

    // Main game loop
    std::string winner;
    while (!gameTable.win(winner)) {
        // Loop through each player for their turn
        for (Player* player : {gameTable.getPlayer1(), gameTable.getPlayer2()}) {
            std::cout << "\n" << player->getName() << "'s turn\n";
            std::cout << "Current game state:\n" << gameTable << "\n";

            // Check if the player wants to quit
            std::cout << "Press 'q' to quit or any other key to continue: ";
            std::string input;
            std::cin >> input;
            if (input == "q") {
                std::cout << "Game terminated by player.\n";
                return 0; // End the program immediately
            }

            // Draw top card from the deck and add to player's hand
            Card* drawnCard = gameTable.getDeck().draw();
            if (drawnCard) {
                std::cout << "Drew card: " << *drawnCard << std::endl;
                player->printHand(std::cout, true);
            } else {
                std::cout << "No more cards in deck!\n";
                break;
            }

            // Offer player a choice to play the drawn card or discard it
            std::cout << "Choose an action:\n";
            std::cout << "1. Play the card\n";
            std::cout << "2. Discard the card\n";
            std::cout << "Enter choice (1 or 2): ";
            std::cin >> input;

            if (input == "q") {
                std::cout << "Game terminated by player.\n";
                return 0;
            }

            if (input == "1") {
                std::cout << "Playing top card: " << *drawnCard << std::endl;
                // Assuming player has logic to add the drawn card to a chain
                // player->addToChain(drawnCard);
            } else if (input == "2") {
                std::cout << "Discarding the card.\n";
                gameTable.getDiscardPile().addCard(std::unique_ptr<Card>(drawnCard));
            }

            // Optionally interact with the trade area
            if (gameTable.getTradeArea().numCards() > 0) {
                std::cout << "Trade Area: " << gameTable.getTradeArea() << "\n";
                std::cout << "Do you want to take cards from the Trade Area? (y/n): ";
                std::cin >> input;
                
                if (input == "q") {
                    std::cout << "Game terminated by player.\n";
                    return 0;
                }
                
                if (input == "y") {
                    for (int i = 0; i < gameTable.getTradeArea().numCards(); ++i) {
                        Card* tradeCard = gameTable.getTradeArea().trade(drawnCard->getName());
                        if (tradeCard) {
                            // Assuming player has logic to add to a chain
                            // player->addToChain(tradeCard);
                            delete tradeCard;
                        }
                    }
                }
            }

            // Draw two more cards for the player, if desired
            std::cout << "Do you want to draw two more cards? (y/n): ";
            std::cin >> input;
            
            if (input == "q") {
                std::cout << "Game terminated by player.\n";
                return 0;
            }
            
            if (input == "y") {
                for (int i = 0; i < 2; ++i) {
                    Card* newCard = gameTable.getDeck().draw();
                    if (newCard) {
                        std::cout << "Drew card: " << *newCard << std::endl;
                        player->printHand(std::cout, true);
                    } else {
                        std::cout << "Deck is empty.\n";
                        break;
                    }
                }
            }
        }
    }

    // End game: Announce the winner
    std::cout << "\nGame over! Winner: " << winner << std::endl;

    return 0;
}
