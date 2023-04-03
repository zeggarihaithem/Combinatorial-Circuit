#ifndef NXORGATE_HPP
#define NXORGATE_HPP
#include "Gate.hpp"
#include<string>

class NxorGate : public Gate{
    private:
        const string GATENAME;
    public:
        NxorGate(Circuit * firstInput, Circuit * secondInput);
        string getGateName() const override;
        bool evaluate() const override;
};
#endif

