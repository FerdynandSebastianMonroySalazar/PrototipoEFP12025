#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

// Estructura de usuario con campos fijos para escribir binarios
struct UsuarioBin {
    char nombre[30];
    char carnet[10];
    char username[15];
    char password[15];
};

int main() {
    UsuarioBin u;

    cout << "=== Crear Usuario para el Sistema ===" << endl;
    string nombre, carnet, username, password;

    cout << "Nombre completo: ";
    getline(cin, nombre);
    cout << "Carnet: ";
    getline(cin, carnet);
    cout << "Nombre de usuario: ";
    getline(cin, username);
    cout << "Contraseña: ";
    getline(cin, password);

    // Copiar strings a los campos fijos (rellenando con ceros si hace falta)
    strncpy(u.nombre, nombre.c_str(), sizeof(u.nombre));
    strncpy(u.carnet, carnet.c_str(), sizeof(u.carnet));
    strncpy(u.username, username.c_str(), sizeof(u.username));
    strncpy(u.password, password.c_str(), sizeof(u.password));

    ofstream archivo("bin/usuarios.dat", ios::binary | ios::app);
    if (!archivo) {
        cerr << "No se pudo abrir el archivo bin/usuarios.dat\n";
        return 1;
    }

    archivo.write(reinterpret_cast<char*>(&u), sizeof(UsuarioBin));
    archivo.close();

    cout << "\nUsuario creado exitosamente." << endl;
    return 0;
}
