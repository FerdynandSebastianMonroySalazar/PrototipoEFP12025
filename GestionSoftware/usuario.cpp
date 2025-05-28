//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Usuario.h"
#include <cstring>
#include <iostream>

Usuario::Usuario() {
    std::memset(nombre, 0, sizeof(nombre));
    std::memset(carnet, 0, sizeof(carnet));
    std::memset(username, 0, sizeof(username));
    std::memset(password, 0, sizeof(password));
}

Usuario::Usuario(const char* nom, const char* car, const char* user, const char* pass) {
    std::strncpy(nombre, nom, sizeof(nombre));
    std::strncpy(carnet, car, sizeof(carnet));
    std::strncpy(username, user, sizeof(username));
    std::strncpy(password, pass, sizeof(password));
}

const char* Usuario::getNombre() const { return nombre; }
const char* Usuario::getCarnet() const { return carnet; }
const char* Usuario::getUsername() const { return username; }
const char* Usuario::getPassword() const { return password; }

void Usuario::mostrarDatos() const {
    std::cout << "Nombre: " << nombre << " | Carnet: " << carnet << std::endl;
}
