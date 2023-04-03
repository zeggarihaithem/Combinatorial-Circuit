#include "NorGate.hpp"

NorGate::NorGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("NOR"){}


bool NorGate::evaluate() const {
    return !(getFirstInput()->evaluate() || getSecondInput()->evaluate());
}

string NorGate::getGateName() const {
    return GATENAME;
}