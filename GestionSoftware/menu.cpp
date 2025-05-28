//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Menu.h"
#include <iostream>

void Menu::mostrarMenuPrincipal(const std::string& usuario, const std::string& carnet, const std::string& nombre) {
    std::cout << "\n===== SISTEMA - Bienvenido " << nombre << " (" << carnet << ") =====\n";
    std::cout << "1. Catálogos\n";
    std::cout << "2. Informes\n";
    std::cout << "3. Seguridad\n";
    std::cout << "4. Salir\n";
    std::cout << "Seleccione una opción: ";
}

void Menu::mostrarMenuCatalogo() {
    std::cout << "\n--- Catálogo de Productos ---\n";
    std::cout << "1. Agregar\n";
    std::cout << "2. Mostrar\n";
    std::cout << "3. Buscar\n";
    std::cout << "4. Modificar\n";
    std::cout << "5. Eliminar\n";
    std::cout << "6. Regresar\n";
    std::cout << "Seleccione una opción: ";
}

void Menu::mostrarMenuSeguridad() {
    std::cout << "\n--- Bitácora de Seguridad ---\n";
    std::cout << "1. Mostrar Bitácora\n";
    std::cout << "2. Regresar\n";
    std::cout << "Seleccione una opción: ";
}
