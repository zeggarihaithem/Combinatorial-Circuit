#ifndef OUTPUTGATE_HPP
#define OUTPUTGATE_HPP
#include "Circuit.hpp"
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

class OutputGate{
    private:
        char name;
        Circuit * output;
        string getTextualForm() const;
        int getDepth() const;
        bool evaluate() const;
        Circuit * synthesizeOutput(string textualForm);
    public:
        OutputGate(char name, Circuit * output);
        //Synthétiser OutputGate à partir d'une forme textuelle écrit dans un fichier
        OutputGate(string fileName);
        void displayTextualForm() const;
        void displayInConsole() const;
        void saveInFile() const;
};
#endif

