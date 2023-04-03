#ifndef INPUTGATE_HPP
#define INPUTGATE_HPP
#include "Circuit.hpp"
#include<iostream>
#include <sstream>

using namespace std;

class InputGate : public Circuit{
    private:
        char name;
        bool value;
    public:
        InputGate(char _name, bool value);
        void setValue(bool value);
        bool isInput() const override;
        int getDepth() const override;
        bool evaluate() const override;
        void displayInConsole(ostream& out) const override;
        string getTextualForm() const override;
};

#endif

