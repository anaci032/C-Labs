// ChainBase.h
#ifndef CHAINBASE_H
#define CHAINBASE_H

#include <iostream>

class ChainBase {
public:
    virtual ~ChainBase() = default;                 // Virtual destructor for polymorphism
    virtual int sell() const = 0;                   // Pure virtual function for selling
    virtual void print(std::ostream& out) const = 0; // Pure virtual function for printing
};

// Overload the stream insertion operator for printing
inline std::ostream& operator<<(std::ostream& out, const ChainBase& chain) {
    chain.print(out);
    return out;
}

#endif // CHAINBASE_H
