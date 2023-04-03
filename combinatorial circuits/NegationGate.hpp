#ifndef NEGATIONGATE_HPP
#define NEGATIONGATE_HPP
#include "Gate.hpp"
#include<string>
#include<iostream>
#include<sstream>

class NegationGate : public Gate{
    private:
        const string GATENAME;
    public:
        NegationGate(Circuit * firstInput);
        string getGateName() const override;
        bool evaluate() const override;
        void displayInConsole(ostream& out) const override;
        string getTextualForm() const override;
};
#endif

