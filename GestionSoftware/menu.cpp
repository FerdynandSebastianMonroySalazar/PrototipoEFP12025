//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mostrarMenuPrincipal(const char* usuario, const char* carnet, const char* nombre) {
    cout << "\n=== MEN� PRINCIPAL ===\n";
    cout << "Usuario: " << usuario << "\n";
    cout << "Carnet: " << carnet << "\n";
    cout << "Nombre: " << nombre << "\n\n";
    cout << "1. Cat�logos\n";
    cout << "2. Generar informe\n";
    cout << "3. Ver bit�cora\n";
    cout << "4. Salir\n";
}
