#include "Circuit.hpp"
#include "InputGate.hpp"
#include "Gate.hpp"
#include "AndGate.hpp"
#include "OrGate.hpp"
#include "XorGate.hpp"
#include "NandGate.hpp"
#include "NorGate.hpp"
#include "NxorGate.hpp"
#include "NegationGate.hpp"
#include "OutputGate.hpp"
#include <iostream>

using namespace std;

int main(){
   InputGate * a = new InputGate('a', true);
   InputGate * b = new InputGate('b', false);
   Gate * andGate = new AndGate(a, b);
   Gate * andGate_two = new AndGate(a, andGate);
   Gate * orGate = new OrGate(andGate, andGate_two);
   OutputGate * A = new OutputGate('A', orGate);
   A->displayTextualForm();
   A->saveInFile();
   OutputGate * B = new OutputGate("A.txt");
   B->displayTextualForm();
}