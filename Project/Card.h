#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>

class Card {
public:
    virtual ~Card() = default;
    virtual int getCardsPerCoin(int coins) const = 0;
    virtual std::string getName() const = 0;
    virtual void print(std::ostream& out) const = 0;

    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        card.print(out);
        return out;
    }
};

class Blue : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 4;
            case 2: return 6;
            case 3: return 8;
            case 4: return 10;
            default: return -1;
        }
    }
    std::string getName() const override { return "Blue"; }
    void print(std::ostream& out) const override { out << "B"; }
};

class Chili : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 6;
            case 3: return 8;
            case 4: return 9;
            default: return -1;
        }
    }
    std::string getName() const override { return "Chili"; }
    void print(std::ostream& out) const override { out << "C"; }
};

class Stink : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 7;
            case 4: return 8;
            default: return -1;
        }
    }
    std::string getName() const override { return "Stink"; }
    void print(std::ostream& out) const override { out << "S"; }
};

class Green : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 3;
            case 2: return 5;
            case 3: return 6;
            case 4: return 7;
            default: return -1;
        }
    }
    std::string getName() const override { return "Green"; }
    void print(std::ostream& out) const override { out << "G"; }
};

class Soy : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 6;
            case 4: return 7;
            default: return -1;
        }
    }
    std::string getName() const override { return "Soy"; }
    void print(std::ostream& out) const override { out << "s"; }
};

class Black : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 4;
            case 3: return 5;
            case 4: return 6;
            default: return -1;
        }
    }
    std::string getName() const override { return "Black"; }
    void print(std::ostream& out) const override { out << "b"; }
};

class Red : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 1: return 2;
            case 2: return 3;
            case 3: return 4;
            case 4: return 5;
            default: return -1;
        }
    }
    std::string getName() const override { return "Red"; }
    void print(std::ostream& out) const override { out << "R"; }
};

class Garden : public Card {
public:
    int getCardsPerCoin(int coins) const override {
        switch (coins) {
            case 2: return 2;
            case 3: return 3;
            default: return -1;
        }
    }
    std::string getName() const override { return "Garden"; }
    void print(std::ostream& out) const override { out << "g"; }
};

#endif // CARD_H
