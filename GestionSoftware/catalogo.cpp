//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Catalogo.h"
#include <iostream>

Catalogo::Catalogo() {}

Catalogo::Catalogo(int id, std::string nombre, float precio) {
    this->id = id;
    this->nombre = nombre;
    this->precio = precio;
}

int Catalogo::getId() {
    return id;
}

std::string Catalogo::getNombre() {
    return nombre;
}

float Catalogo::getPrecio() {
    return precio;
}

void Catalogo::mostrar() {
    std::cout << "ID: " << id << " | Nombre: " << nombre << " | Precio: Q" << precio << std::endl;
}
