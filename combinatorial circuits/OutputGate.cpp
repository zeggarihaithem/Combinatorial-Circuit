#include "OutputGate.hpp"
#include "InputGate.hpp"
#include "AndGate.hpp"
#include "NandGate.hpp"
#include "OrGate.hpp"
#include "NorGate.hpp"
#include "XorGate.hpp"
#include "NxorGate.hpp"
#include "NegationGate.hpp"

int OutputGate::getDepth() const {
    return output->getDepth();
}

string OutputGate::getTextualForm() const {
    stringstream ss;
    ss << name << " = " << output->getTextualForm() << " = " << evaluate();
    return ss.str();
}

bool OutputGate::evaluate() const {
    return output->evaluate();
}

OutputGate::OutputGate(char name, Circuit * output){
    this->name = name;
    this->output = output;
}

int getCommaPosition(string textualForm){
    int openParenthesis = -1;
    int index = 0;
    while(textualForm[index] != ','){
        if(textualForm[index] == '(') openParenthesis++;
        index++;
    }
    if(openParenthesis == 0) return textualForm.find(',');
    openParenthesis = -1;
    index = 0;
    while(textualForm[index] != ')'){
        if(textualForm[index] == '(') openParenthesis++;
        index++;
    }
    index = 0;
    while(openParenthesis > 0){
        if(textualForm[index] == ')') openParenthesis--;
        index++;
    }
    return index;
}

Circuit * OutputGate::synthesizeOutput(string textualForm){
    int index = 0;
    int commaPosition = getCommaPosition(textualForm);
    int length = textualForm.length();
    if(textualForm[index]>='A'&&textualForm[index]<='Z'){
        if(textualForm.substr(index, index+3) == "AND"){
            index+=4;
            AndGate * andGate = new AndGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return andGate;   
        }
        if(textualForm.substr(index, index+4) == "NAND"){
            index+=5;
            NandGate * nandGate = new NandGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return nandGate;   
        }
        if(textualForm.substr(index, index+2) == "OR"){
            index+=3;
            OrGate * orGate = new OrGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return orGate;   
        }
        if(textualForm.substr(index, index+3) == "NOR"){
            index+=4;
            NorGate * norGate = new NorGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return norGate;   
        }
        if(textualForm.substr(index, index+3) == "XOR"){
            index+=4;
            XorGate * xorGate = new XorGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return xorGate;   
        }
        if(textualForm.substr(index, index+4) == "NXOR"){
            index+=5;
            NxorGate * nxorGate = new NxorGate(synthesizeOutput(textualForm.substr(index,commaPosition-index)),synthesizeOutput(textualForm.substr(commaPosition+2,length-commaPosition+1)));  
            return nxorGate;   
        }
        if(textualForm.substr(index, index+3) == "NEG"){
            index+=7;
            NegationGate * negation = new NegationGate(synthesizeOutput(textualForm.substr(index,length-index-1)));
            return negation;
        }
    }else{
        bool value ;
        if(textualForm[4] == '0') value = false;
        if(textualForm[4] == '1') value = true;
        InputGate * input = new InputGate(textualForm[0], value);
        return input;
    }
    return nullptr;
}

OutputGate::OutputGate(string filename){
   string textualForm;
   fstream file(filename);
   getline (file, textualForm);
   name = textualForm[0];
   output = synthesizeOutput(textualForm.substr(4,textualForm.length()-8));
}

void OutputGate::displayTextualForm() const {
    cout << getTextualForm() << endl;
}

void OutputGate::saveInFile() const {
    string fileName(1, name);
    ofstream file(fileName+".txt");
    file << getTextualForm();
    file.close();
}


void OutputGate::displayInConsole() const{
   cout <<output << endl;
   for (size_t i = 0; i < getDepth(); i++){
       cout << "     ";
   }
   cout << "  |\n";
   for (size_t i = 0; i < getDepth(); i++){
       cout << "     ";
   }
   cout << "  |\n";
   for (size_t i = 0; i < getDepth(); i++){
       cout << "     ";
   }
   cout << name << " = " << evaluate()<< endl;
}