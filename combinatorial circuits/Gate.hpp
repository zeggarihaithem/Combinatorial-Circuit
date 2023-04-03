#ifndef GATE_HPP
#define GATE_HPP
#include "Circuit.hpp"
#include <string>
#include <iostream>
#include<sstream>

using namespace std;

class Gate : public Circuit{
    private:
        const string GATENAME;
        Circuit * firstInput;
        Circuit * secondInput;
    public:
        Gate(Circuit * firstInput, Circuit * secondInput);
        Circuit * getFirstInput() const;
        Circuit * getSecondInput() const;
        virtual string getGateName() const = 0;
        int getDepth() const;
        bool isInput() const override;
        virtual bool evaluate() const = 0;
        void displayInConsole(ostream& out) const override;
        string getTextualForm() const override;
};

#endif

