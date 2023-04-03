#include "XorGate.hpp"

XorGate::XorGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("XOR"){}


bool XorGate::evaluate() const {
    return getFirstInput()->evaluate() != getSecondInput()->evaluate();
}

string XorGate::getGateName() const {
    return GATENAME;
}