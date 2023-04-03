#ifndef NORGATE_HPP
#define NORGATE_HPP
#include "Gate.hpp"
#include<string>

class NorGate : public Gate{
    private:
        const string GATENAME;
    public:
        NorGate(Circuit * firstInput, Circuit * secondInput);
        string getGateName() const override;
        bool evaluate() const override;
};
#endif

