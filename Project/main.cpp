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
        for (Player* player : {gameTable.getPlayer1(), gameTable.getPlayer2()}) {
            std::cout << "\n" << player->getName() << "'s turn\n";
            std::cout << "Current game state:\n" << gameTable << "\n";

            // Display player's hand and chains
            std::cout << *player << "\n";

            // Check if the player wants to quit
            std::cout << "Press 'q' to quit or any other key to continue: ";
            std::string input;
            std::cin >> input;
            if (input == "q") {
                std::cout << "Game terminated by player.\n";
                return 0;
            }

            // Draw top card from the deck and add to player's hand
            Card* drawnCard = gameTable.getDeck().draw();
            if (drawnCard) {
                std::cout << "Drew card: " << *drawnCard << std::endl;

                // Add the drawn card to the player's hand
                player->addCardToHand(drawnCard);
                player->printHand(std::cout, true);
            } else {
                std::cout << "No more cards in deck!\n";
                break;
            }

            // Offer player a choice to manage chains
            std::cout << "Choose an action:\n";
            std::cout << "1. Add drawn card to a chain\n";
            std::cout << "2. Sell a chain\n";
            std::cout << "3. Discard the card\n";
            std::cin >> input;

            if (input == "q") {
                std::cout << "Game terminated by player.\n";
                return 0;
            }

            if (input == "1") {
                try {
                    player->addToChain(drawnCard);
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << "\n";
                    gameTable.getDiscardPile().addCard(drawnCard);
                }
            } else if (input == "2") {
                std::cout << "Enter the chain index to sell: ";
                int chainIndex;
                std::cin >> chainIndex;

                try {
                    int earnedCoins = player->sellChain(chainIndex - 1); // Chains are indexed from 0
                    std::cout << "Sold chain for " << earnedCoins << " coins.\n";
                } catch (const std::runtime_error& e) {
                    std::cout << e.what() << "\n";
                }
            } else if (input == "3") {
                std::cout << "Discarding the card.\n";
                gameTable.getDiscardPile().addCard(drawnCard);
            }

            // Handle Trade Area
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
                            try {
                                player->addToChain(tradeCard);
                            } catch (const std::runtime_error& e) {
                                std::cout << e.what() << "\n";
                                delete tradeCard; // Clean up memory if the card cannot be used
                            }
                        }
                    }
                }
            }

            // Draw two more cards
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

                        // Add the new cards to the player's hand
                        player->addCardToHand(newCard);
                        player->printHand(std::cout, true);
                    } else {
                        std::cout << "Deck is empty.\n";
                        break;
                    }
                }
            }
        }
    }

    // Announce the winner
    std::cout << "\nGame over! Winner: " << winner << std::endl;

    return 0;
}
