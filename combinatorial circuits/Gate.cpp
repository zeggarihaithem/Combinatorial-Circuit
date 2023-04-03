#include "Gate.hpp"

Gate::Gate(Circuit * firstInput, Circuit * secondInput){
    this->firstInput = firstInput;
    this->secondInput = secondInput;
}

Circuit * Gate::getFirstInput() const {
    return firstInput;
}

Circuit * Gate::getSecondInput() const {
    return secondInput;
}

int Gate::getDepth() const {
    if(firstInput->isInput() && secondInput->isInput()) return 1;
    return firstInput->getDepth() + secondInput->getDepth();
}

bool Gate::isInput() const {
    return false;
}
void Gate::displayInConsole(ostream& out) const {
    for ( int i = 0; i < firstInput->getDepth(); i++){
        out << "     ";
    }
    out << firstInput;
    for ( int i = 0; i < secondInput->getDepth(); i++){
        out << "     ";
    }
    out << secondInput << endl;

    for ( int i = 0; i < firstInput->getDepth(); i++){
        out << "     ";
    }
    out << "  |";
    for ( int i = 0; i < secondInput->getDepth(); i++){
        out << "     ";
    }
    out << "  |\n";
    for ( int i = 0; i < firstInput->getDepth(); i++){
        out << "     ";
    }
    out << "  |";
    for ( int i = 0; i < secondInput->getDepth(); i++){
        out << "     ";
    }
    out << "  |\n";
    
    for ( int i = 0; i < firstInput->getDepth(); i++){
        out << "     ";
    }
    for ( int i = 0; i < firstInput->getDepth(); i++){
        out << "-";
    }
   out<<getGateName();
    

}
string Gate::getTextualForm() const {
    stringstream ss;
    ss << getGateName() << "(" << firstInput->getTextualForm() << ", " << secondInput->getTextualForm() << ")";
    return ss.str();
}