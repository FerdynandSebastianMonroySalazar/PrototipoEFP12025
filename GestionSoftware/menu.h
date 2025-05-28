//menu por Ferdynand Monroy 99592414049 mayo 2025
#ifndef MENU_H
#define MENU_H

#include <string>

class Menu {
public:
    static void mostrarMenuPrincipal(const std::string& usuario, const std::string& carnet, const std::string& nombre);
    static void mostrarMenuCatalogo();
    static void mostrarMenuSeguridad();
};

#endif

