#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Hand.h"
#include "Card.h"
#include "Chain.h"
#include "ChainBase.h"

class Player {
    std::string name;
    int coins = 0;
    Hand hand;
    std::vector<std::unique_ptr<ChainBase>> chains; // Use ChainBase for polymorphic behavior
    int maxChains;

public:
    Player(const std::string& playerName, int maxChains = 2);
    std::string getName() const;
    int getNumCoins() const;
    void addCoins(int num);
    void buyThirdChain();
    int getMaxNumChains() const;
    int getNumChains() const;
    void addChain(std::unique_ptr<ChainBase> chain);
    ChainBase* getChain(int index) const;
    void printHand(std::ostream& out, bool showAll) const;

    friend std::ostream& operator<<(std::ostream& out, const Player& player) {
        out << player.name << " has " << player.coins << " coins\n";
        for (size_t i = 0; i < player.chains.size(); ++i) {
            if (player.chains[i]) {
                out << "Chain " << i + 1 << ": " << *player.chains[i] << "\n";
            }
        }
        player.printHand(out, true);
        return out;
    }
};

#endif // PLAYER_H
