// TITLE: Chemical Element Identifier
// DESCRIPTION:
// This program aims to display a particular element with its name, chemical symbol, atomic number and atomic mass
// and classify whether that certain element is an alkali metals, alkaline-earth metal, post-transition metals,
// transition metal, lanthanide, actinide, metalloid, nonmetal, halogen or noble gas.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>

using namespace std;

struct Element {

    string  name;
    string  symbol;
    int     atomicNumber;
    double  atomicMass;
    string  classification;
    string  userInput;

};

// --------------------------------- DATA SET --------------------------------- //
const int numElements = 118;
Element elements[numElements] = { 

    // Element name, Element symbol, Atomic number, Atomic mass, Classification
    { "Hydrogen", "H", 1, 1.008, "Nonmetal" },
    { "Helium", "He", 2, 4.003, "Noble Gas" },
    { "Lithium", "Li", 3, 6.941, "Alkali Metal" },
    { "Beryllium", "Be", 4, 9.012, "Alkaline Earth Metal" },
    { "Boron", "B", 5, 10.81, "Metalloid" },
    { "Carbon", "C", 6, 12.01, "Nonmetal" },
    { "Nitrogen", "N", 7, 14.001, "Nonmetal" },
    { "Oxygen", "O", 8, 16.00, "Nonmetal" },
    { "Fluorine", "F", 9, 19.00, "Halogen" },
    { "Neon", "Ne", 10, 20.18, "Noble Gas" },
    { "Sodium", "Na", 11, 22.99, "Alkali Metal" },
    { "Magnesium", "Mg", 12, 24.31, "Alkaline Earth Metal" },
    { "Aluminium", "Al", 13, 26.98, "Post-Transition Metal" },
    { "Silicon", "Si", 14, 28.09, "Metalloid" },
    { "Phosphorus", "P", 15, 30.97, "Nonmetal" },
    { "Sulfur", "S", 16, 32.07, "Nonmetal" },
    { "Chlorine", "Cl", 17, 35.45, "Halogen" },
    { "Argon", "Ar", 18, 39.95, "Noble Gas" },
    { "Potassium", "K", 19, 39.10, "Alkali Metal" },
    { "Calcium", "Ca", 20, 40.08, "Alkaline Earth Metal" },
    { "Scandium", "Sc", 21, 44.96, "Transition Metal" },
    { "Titanium", "Ti", 22, 47.87, "Transition Metal" },
    { "Vanadium", "V", 23, 50.94, "Transition Metal" },
    { "Chromium", "Cr", 24, 52.00, "Transition Metal" },
    { "Manganese", "Mn", 25, 54.94, "Transition Metal" },
    { "Iron", "Fe", 26, 55.84, "Transition Metal" },
    { "Cobalt", "Co", 27, 58.93, "Transition Metal" },
    { "Nickel", "Ni", 28, 58.69, "Transition Metal" },
    { "Copper", "Cu", 29, 63.55, "Transition Metal" },
    { "Zinc", "Zn", 30, 65.39, "Transition Metal" },
    { "Gallium", "Ga", 31, 69.72, "Post-Transition Metal" },
    { "Germanium", "Ge", 32, 72.63, "Metalloid" },
    { "Arsenic", "As", 33, 74.92, "Metalloid" },
    { "Selenium", "Se", 34, 78.96, "Nonmetal" },
    { "Bromine", "Br", 35, 79.90, "Halogen" },
    { "Krypton", "Kr", 36, 83.80, "Noble Gas" },
    { "Rubidium", "Rb", 37, 85.47, "Alkali Metal" },
    { "Strontium", "Sr", 38, 87.62, "Alkaline Earth Metal" },
    { "Yttrium", "Y", 39, 88.91, "Transition Metal" },
    { "Zirconium", "Zr", 40, 91.22, "Transition Metal" },
    { "Niobium", "Nb", 41, 92.91, "Transition Metal" },
    { "Molybdenum", "Mo", 42, 95.94, "Transition Metal" },
    { "Technetium", "Tc", 43, 98, "Transition Metal" },
    { "Ruthenium", "Ru", 44, 101.07, "Transition Metal" },
    { "Rhodium", "Rh", 45, 102.91, "Transition Metal" },
    { "Palladium", "Pd", 46, 106.42, "Transition Metal" },
    { "Silver", "Ag", 47, 107.87, "Transition Metal" },
    { "Cadmium", "Cd", 48, 112.41, "Transition Metal" },
    { "Indium", "In", 49, 114.82, "Post-Transition Metal" },
    { "Tin", "Sn", 50, 118.71, "Post-Transition Metal" },
    { "Antimony", "Sb", 51, 121.76, "Metalloid" },
    { "Tellurium", "Te", 52, 127.60, "Metalloid" },
    { "Iodine", "I", 53, 126.90, "Halogen" },
    { "Xenon", "Xe", 54, 131.29, "Noble Gas" },
    { "Cesium", "Cs", 55, 132.91, "Alkali Metal" },
    { "Barium", "Ba", 56, 137.33, "Alkaline Earth Metal" },
    { "Lanthanum", "La", 57, 138.91, "Lanthanide" },
    { "Cerium", "Ce", 58, 140.12, "Lanthanide" },
    { "Praseodymium", "Pr", 59, 140.91, "Lanthanide" },
    { "Neodymium", "Nd", 60, 144.24, "Lanthanide" },
    { "Promethium", "Pm", 61, 145, "Lanthanide" },
    { "Samarium", "Sm", 62, 150.36, "Lanthanide" },
    { "Europium", "Eu", 63, 151.96, "Lanthanide" },
    { "Gadolinium", "Gd", 64, 157.25, "Lanthanide" },
    { "Terbium", "Tb", 65, 158.93, "Lanthanide" },
    { "Dysprosium", "Dy", 66, 162.50, "Lanthanide" },
    { "Holmium", "Ho", 67, 164.93, "Lanthanide" },
    { "Erbium", "Er", 68, 167.26, "Lanthanide" },
    { "Thulium", "Tm", 69, 168.93, "Lanthanide" },
    { "Ytterbium", "Yb", 70, 173.04, "Lanthanide" },
    { "Lutetium", "Lu", 71, 174.97, "Lanthanide" },
    { "Hafnium", "Hf", 72, 178.49, "Transition Metal" },
    { "Tantalum", "Ta", 73, 180.95, "Transition Metal" },
    { "Tungsten", "W", 74, 183.84, "Transition Metal" },
    { "Rhenium", "Re", 75, 186.21, "Transition Metal" },
    { "Osmium", "Os", 76, 190.23, "Transition Metal" },
    { "Iridium", "Ir", 77, 192.22, "Transition Metal" },
    { "Platinum", "Pt", 78, 195.08, "Transition Metal" },
    { "Gold", "Au", 79, 196.97, "Transition Metal" },
    { "Mercury", "Hg", 80, 200.59, "Transition Metal" },
    { "Thallium", "Tl", 81, 204.38, "Post-Transition Metal" },
    { "Lead", "Pb", 82, 207.2, "Post-Transition Metal" },
    { "Bismuth", "Bi", 83, 208.98, "Post-Transition Metal" },
    { "Polonium", "Po", 84, 209, "Metalloid" },
    { "Astatine", "At", 85, 210, "Halogen" },
    { "Radon", "Rn", 86, 222, "Noble Gas" },
    { "Francium", "Fr", 87, 223, "Alkali Metal" },
    { "Radium", "Ra", 88, 226, "Alkaline Earth Metal" },
    { "Actinium", "Ac", 89, 227, "Actinide" },
    { "Thorium", "Th", 90, 232.04, "Actinide" },
    { "Protactinium", "Pa", 91, 231.04, "Actinide" },
    { "Uranium", "U", 92, 238.03, "Actinide" },
    { "Neptunium", "Np", 93, 237, "Actinide" },
    { "Plutonium", "Pu", 94, 244, "Actinide" },
    { "Americium", "Am", 95, 243, "Actinide" },
    { "Curium", "Cm", 96, 247, "Actinide" },
    { "Berkelium", "Bk", 97, 247, "Actinide" },
    { "Californium", "Cf", 98, 251, "Actinide" },
    { "Einsteinium", "Es", 99, 252, "Actinide" },
    { "Fermium", "Fm", 100, 257, "Actinide" },
    { "Mendelevium", "Md", 101, 258, "Actinide" },
    { "Nobelium", "No", 102, 259, "Actinide" },
    { "Lawrencium", "Lr", 103, 262, "Actinide" },
    { "Rutherfordium", "Rf", 104, 267, "Transition Metal" },
    { "Dubnium", "Db", 105, 268, "Transition Metal" },
    { "Seaborgium", "Sg", 106, 269, "Transition Metal" },
    { "Bohrium", "Bh", 107, 270, "Transition Metal" },
    { "Hassium", "Hs", 108, 269, "Transition Metal" },
    { "Meitnerium", "Mt", 109, 278, "Transition Metal" },
    { "Darmstadtium", "Ds", 110, 281, "Transition Metal" },
    { "Roentgenium", "Rg", 111, 281, "Transition Metal" },
    { "Copernicium", "Cn", 112, 285, "Transition Metal" },
    { "Nihonium", "Nh", 113, 286, "Post-Transition Metal" },
    { "Flerovium", "Fl", 114, 289, "Post-Transition Metal" },
    { "Moscovium", "Mc", 115, 289, "Post-Transition Metal" },
    { "Livermorium", "Lv", 116, 293, "Post-Transition Metal" },
    { "Tennessine", "Ts", 117, 294, "Halogen" },
    { "Oganesson", "Og", 118, 294, "Noble Gas" },
};

Element findFirstStruct(Element elements[], string userInput) {

    stringstream stream(userInput);     // created stringstream object and initialized with userInput
    int i, intInput = 0;            // intInput is the storage of the userInput if it is an integer

    if (stream >> i) {      // if the input is the Atomic Number
        int intInput = i;

        for (int i = 0; i < numElements; i++) {

            if (elements[i].atomicNumber == intInput) {
                return elements[i];
            }
  
        }      

    }
    else {                  // if the input is either the Element Name or Element Symbol

        string tempName;                // to set lowercase version of Element Name
        string tempInput = userInput;   // to set lowercase version of userInput for comparison with Element Name
        transform(tempInput.begin(), tempInput.end(), tempInput.begin(), ::tolower);    // set temporary userInput to lowercase

        for (int i = 0; i < numElements; i++) {

            tempName = elements[i].name;    // store the element name here temporarily to be able to convert it to lowercase w/o affecting the original string
            transform(tempName.begin(), tempName.end(), tempName.begin(), ::tolower);

            if (tempName == tempInput || elements[i].symbol == userInput) {
                return elements[i];
            }

        }

    }

    return Element();
}

int main() {

    int decision = 1;

    while (decision != 0) {

        system("CLS");

        string userInput = "";
        Element result;

        cout<<"---------------------------------------------------------------------------------------------";
        cout<<"\n\t\t\t\t THE MODERN PERIODIC TABLE\n";
        cout<<"---------------------------------------------------------------------------------------------\n\n";
        cout<<"\t\t H                                                      He"<<"\n\n";
        cout<<"\t\t Li Be                                 B  C   N  O   F  Ne"<<"\n\n";
        cout<<"\t\t Na Mg                                 Al Si  P  S   Cl Ar"<<"\n\n";
        cout<<"\t\t K  Ca Sc Ti V  Cr Mn Fe Co Ni Cu  Zn  Ga Ge  As Se  Br Kr"<<"\n\n";
        cout<<"\t\t Rb Sr Y  Zr Nb Mo Tc Ru Rh Pd Ag  Cd  In Sn  Sb Te  I  Xe"<<"\n\n";
        cout<<"\t\t Cs Ba La Hf Ta W  Re Os Ir Pt Au  Hg  Tl Pb  Bi Po  At Rn"<<"\n\n";
        cout<<"\t\t Fr Ra Ac Rf Db Sg Bh Hs Mt Ds Uuu Uub -  Uuq -  Uuh"<<"\n\n\n";
        cout<<"\t\t\t  Ce Pr Nd Pm Sm Eu Gd Tb Dy Ho Er Tm Yb Lu"<<"\n\n";
        cout<<"\t\t\t  Th Pa U  Np Pu Am Cm Bk Cf Es Fm Md No Lr"<<"\n\n\n";
    
        cout << "---------------------------------------------------------------------------------------------\n\t\t\t\t CHEMICAL ELEMENT IDENTIFIER \n";
        cout << "---------------------------------------------------------------------------------------------\nEnter an Element Name, Symbol, or Atomic Number to display its details and classification.\n";
        cout << "NOTE: Type your input correctly to avoid unknown results.\n";
        cout << "\nANSWER: ";
        cin >> userInput;

        result = findFirstStruct(elements, userInput);    // function call to find the element

        if (result.atomicMass == 0) {
            cout << "\nElement not found.";
        }
        else {
            cout << "---------------------------------------------------------------------------------------------\nELEMENT DETAILS\n";
            cout << "\nElement Name:\t  " << result.name;
            cout << "\nElement Symbol:\t  " << result.symbol;
            cout << "\nAtomic Number:\t  " << result.atomicNumber;
            cout << "\nAtomic Weight:\t  " << result.atomicMass;
            cout << "\nClassification:\t  " << result.classification;
        }

        cout << "\n---------------------------------------------------------------------------------------------\nDo you want to continue (enter any number) or not (enter 0)? ";
        cin >> decision;
    }

    return 0;
}
