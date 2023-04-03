#ifndef ANDGATE_HPP
#define ANDGATE_HPP
#include "Gate.hpp"
#include<string>

class AndGate : public Gate{
    private:
        const string GATENAME;
    public:
        AndGate(Circuit * firstInput, Circuit * secondInput);
        string getGateName() const override;
        bool evaluate() const override;
};
#endif

