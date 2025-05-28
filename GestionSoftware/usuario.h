//Ferdynand Monroy 9959 24 14049 Mayo 2025
#ifndef USUARIO_H
#define USUARIO_H

class Usuario {
private:
    char nombre[30];
    char carnet[10];
    char username[15];
    char password[15];
public:
    Usuario(); // Constructor por defecto
    Usuario(const char*, const char*, const char*, const char*);

    const char* getNombre() const;
    const char* getCarnet() const;
    const char* getUsername() const;
    const char* getPassword() const;

    void mostrarDatos() const;
};

#endif

