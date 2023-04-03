#include "NxorGate.hpp"

NxorGate::NxorGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("NXOR"){}


bool NxorGate::evaluate() const {
    return !(getFirstInput()->evaluate() != getSecondInput()->evaluate());
}

string NxorGate::getGateName() const {
    return GATENAME;
}