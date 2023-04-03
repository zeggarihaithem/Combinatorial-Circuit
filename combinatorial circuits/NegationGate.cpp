#include "NegationGate.hpp"

NegationGate::NegationGate(Circuit * firstInput):Gate(firstInput,nullptr), GATENAME("NEGATE"){}


bool NegationGate::evaluate() const {
    return !(getFirstInput()->evaluate());
}

string NegationGate::getGateName() const {
    return GATENAME;
}

void NegationGate::displayInConsole(ostream& out) const {
    //out << getGateName() << "(" << firstInput << ")";
}

string NegationGate::getTextualForm() const {
    stringstream ss;
    ss << getGateName() << "(" << getFirstInput()->getTextualForm() << ")";
    return ss.str();
}

