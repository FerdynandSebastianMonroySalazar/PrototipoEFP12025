//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Usuario.h"
#include <iostream>

Usuario::Usuario() {}

Usuario::Usuario(std::string nombre, std::string carnet, std::string username, std::string password) {
    this->nombre = nombre;
    this->carnet = carnet;
    this->username = username;
    this->password = password;
}

std::string Usuario::getNombre() {
    return nombre;
}

std::string Usuario::getCarnet() {
    return carnet;
}

std::string Usuario::getUsername() {
    return username;
}

std::string Usuario::getPassword() {
    return password;
}

void Usuario::mostrarDatos() {
    std::cout << "Nombre: " << nombre << " | Carnet: " << carnet << std::endl;
}
