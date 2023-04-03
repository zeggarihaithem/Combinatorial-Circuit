#ifndef CIRCUIT_HPP
#define CIRCUIT_HPP

#include <iostream>

using namespace std;

class Circuit{
    public:
        virtual bool isInput() const = 0;
        virtual int getDepth() const = 0;
        virtual bool evaluate() const = 0;
        virtual void displayInConsole(ostream& out) const = 0;
        virtual string getTextualForm() const = 0;
};

ostream& operator<<(ostream& out, const Circuit * c);


#endif

