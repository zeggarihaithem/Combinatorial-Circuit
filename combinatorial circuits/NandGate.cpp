#include "NandGate.hpp"

NandGate::NandGate(Circuit * firstInput, Circuit * secondInput):Gate(firstInput, secondInput), GATENAME("NAND"){}


bool NandGate::evaluate() const {
    return !(getFirstInput()->evaluate() && getSecondInput()->evaluate());
}

string NandGate::getGateName() const {
    return GATENAME;
}