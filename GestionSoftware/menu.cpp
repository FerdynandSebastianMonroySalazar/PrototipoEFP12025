//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Menu.h"
#include <iostream>
using namespace std;

void Menu::mostrarMenuPrincipal(const char* usuario, const char* carnet, const char* nombre) {
    cout << "\n=== MENÚ PRINCIPAL ===\n";
    cout << "Usuario: " << usuario << "\n";
    cout << "Carnet: " << carnet << "\n";
    cout << "Nombre: " << nombre << "\n\n";
    cout << "1. Catálogos\n";
    cout << "2. Generar informe\n";
    cout << "3. Ver bitácora\n";
    cout << "4. Salir\n";
}
