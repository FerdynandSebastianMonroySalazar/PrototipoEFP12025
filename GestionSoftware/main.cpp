//Proyecto examen final Programación I por Ferdynand Monroy 9959 24 14049 Mayo 2025
//Main de todo el programa
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include "Usuario.h"
#include "Menu.h"
#include "Bitacora.h"
#include "Catalogo.h"

using namespace std;

//Funciones
bool autenticarUsuario(Usuario &usuarioAutenticado) {
    string username, password;
    cout << "Ingrese su nombre de usuario: ";
    cin >> username;
    cout << "Ingrese su contraseña: ";
    cin >> password;

    ifstream file("bin/usuarios.dat", ios::binary);
    if (!file) {
        cerr << "Error al abrir archivo de usuarios.\n";
        return false;
    }

    Usuario temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Usuario))) {
        if (temp.getUsername() == username && temp.getPassword() == password) {
            usuarioAutenticado = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void menuCatalogo(const string& usuario) {
    int opcion;
    do {
        Menu::mostrarMenuCatalogo();
        cin >> opcion;
        switch (opcion) {
            case 1:
                cout << "Funcionalidad de agregar producto.\n";
                Bitacora::registrarAccion(usuario, "Agregar producto", "CAT001");
                break;
            case 2:
                cout << "Mostrar productos...\n";
                Bitacora::registrarAccion(usuario, "Mostrar productos", "CAT002");
                break;
            case 3:
                cout << "Buscar producto...\n";
                Bitacora::registrarAccion(usuario, "Buscar producto", "CAT003");
                break;
            case 4:
                cout << "Modificar producto...\n";
                Bitacora::registrarAccion(usuario, "Modificar producto", "CAT004");
                break;
            case 5:
                cout << "Eliminar producto...\n";
                Bitacora::registrarAccion(usuario, "Eliminar producto", "CAT005");
                break;
            case 6:
                cout << "Regresando...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);
}

void menuSeguridad() {
    int opcion;
    do {
        Menu::mostrarMenuSeguridad();
        cin >> opcion;
        switch (opcion) {
            case 1: {
                ifstream bitacora("logs/bitacora.dat");
                string linea;
                while (getline(bitacora, linea)) {
                    cout << linea << endl;
                }
                bitacora.close();
                break;
            }
            case 2:
                cout << "Regresando...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 2);
}

int main() {
    Usuario usuarioActual;

    cout << "===== SISTEMA DE AUTENTICACIÓN =====\n";
    if (!autenticarUsuario(usuarioActual)) {
        cout << "Usuario o contraseña incorrectos.\n";
        return 1;
    }

    system("cls");
    int opcion;
    do {
        Menu::mostrarMenuPrincipal(usuarioActual.getUsername(), usuarioActual.getCarnet(), usuarioActual.getNombre());
        cin >> opcion;
        switch (opcion) {
            case 1:
                menuCatalogo(usuarioActual.getUsername());
                break;
            case 2:
                cout << "Generando informe en TXT...\n";
                Bitacora::registrarAccion(usuarioActual.getUsername(), "Generar informe", "INF001");
                break;
            case 3:
                menuSeguridad();
                break;
            case 4:
                cout << "Saliendo del sistema...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 4);

    return 0;
}
