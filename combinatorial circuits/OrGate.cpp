#include "OrGate.hpp"

OrGate::OrGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("OR"){}


bool OrGate::evaluate() const {
    return getFirstInput()->evaluate() || getSecondInput()->evaluate();
}

string OrGate::getGateName() const {
    return GATENAME;
}