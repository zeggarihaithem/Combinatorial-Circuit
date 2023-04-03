#ifndef ORGATE_HPP
#define ORGATE_HPP
#include "Gate.hpp"
#include<string>

class OrGate : public Gate{
    private:
        const string GATENAME;
    public:
        OrGate(Circuit * firstInput, Circuit * secondInput);
        string getGateName() const override;
        bool evaluate() const override;
};
#endif

