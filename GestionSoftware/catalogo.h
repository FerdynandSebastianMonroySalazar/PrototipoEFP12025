//Ferdynand Monroy 9959 24 14049
#ifndef CATALOGO_H
#define CATALOGO_H

#include <string>

class Catalogo {
private:
    int id;
    std::string nombre;
    float precio;
public:
    Catalogo();
    Catalogo(int, std::string, float);
    int getId();
    std::string getNombre();
    float getPrecio();
    void mostrar();
};

#endif
