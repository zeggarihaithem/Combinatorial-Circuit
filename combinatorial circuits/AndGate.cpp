#include "AndGate.hpp"

AndGate::AndGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("AND"){}


bool AndGate::evaluate() const {
    return getFirstInput()->evaluate() && getSecondInput()->evaluate();
}

string AndGate::getGateName() const {
    return GATENAME;
}
