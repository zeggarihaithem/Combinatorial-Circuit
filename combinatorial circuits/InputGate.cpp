#include "InputGate.hpp"

InputGate::InputGate(char name, bool value){
    this->name = name;
    this->value = value;
}

void InputGate::setValue(bool value){
    this->value = value;
}

bool InputGate::isInput() const {
    return true;
}

int InputGate::getDepth() const {
    return 1;
}
bool InputGate::evaluate() const {
    return value;
}

void InputGate::displayInConsole(ostream& out) const {
    out << name << " = " << evaluate();
}
string InputGate::getTextualForm() const {
    stringstream ss;
    ss << name << " = " << evaluate();
    return ss.str();
}
