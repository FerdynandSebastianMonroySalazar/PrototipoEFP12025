//Ferdynand Monroy 9959 24 14049 Mayo 2025
#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
private:
    std::string nombre;
    std::string carnet;
    std::string username;
    std::string password;
public:
    Usuario();
    Usuario(std::string, std::string, std::string, std::string);
    std::string getNombre();
    std::string getCarnet();
    std::string getUsername();
    std::string getPassword();
    void mostrarDatos();
};

#endif
