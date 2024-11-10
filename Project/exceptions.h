#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class IllegalType : public std::runtime_error {
public:
    explicit IllegalType(const std::string& message = "Illegal card type for this chain")
        : std::runtime_error(message) {}
};

class NotEnoughCoins : public std::runtime_error {
public:
    explicit NotEnoughCoins(const std::string& message = "Not enough coins to buy a third chain")
        : std::runtime_error(message) {}
};

#endif // EXCEPTIONS_H
