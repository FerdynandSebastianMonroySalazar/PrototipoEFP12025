//Proyecto examen final Programación I por Ferdynand Monroy 9959 24 14049 Mayo 2025
//Main de todo el programa
// Proyecto examen final Programación I por Ferdynand Monroy 9959 24 14049 Mayo 2025
// Main de todo el programa
// Proyecto examen final Programación I - Ferdynand Monroy 9959 24 14049 - Mayo 2025
// Archivo principal del programa

#include <iostream>
#include <fstream>
#include <cstring>
#include "Usuario.h"
#include "Menu.h"
#include "Bitacora.h"

using namespace std;

// Función para autenticar usuario desde archivo binario
bool autenticarUsuario(Usuario& usuarioAutenticado) {
    char inputUser[15], inputPass[15];
    cout << "=== INICIO DE SESIÓN ===" << endl;
    cout << "Usuario: ";
    cin >> inputUser;
    cout << "Contraseña: ";
    cin >> inputPass;

    ifstream file("bin/usuarios.dat", ios::binary);
    if (!file.is_open()) {
        cerr << "No se pudo abrir el archivo binario de usuarios.\n";
        return false;
    }

    Usuario temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Usuario))) {
        if (strcmp(temp.getUsername(), inputUser) == 0 &&
            strcmp(temp.getPassword(), inputPass) == 0) {
            usuarioAutenticado = temp;
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Función para mostrar el menú principal
void mostrarMenuPrincipal(Usuario usuario) {
    int opcion;
    do {
        Menu::mostrarMenuPrincipal(usuario.getUsername(), usuario.getCarnet(), usuario.getNombre());
        cout << "Seleccione una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nEntrando a Catálogos...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Entró al submenú de catálogos", "CAT001");
                break;

            case 2:
                cout << "\nGenerando informe (simulado)...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Generó informe", "INF001");
                break;

            case 3: {
                cout << "\n--- Bitácora de Seguridad ---\n";
                ifstream bitacora("logs/bitacora.dat");
                if (!bitacora.is_open()) {
                    cout << "No se pudo abrir la bitácora.\n";
                    break;
                }
                string linea;
                while (getline(bitacora, linea)) {
                    cout << linea << endl;
                }
                bitacora.close();
                Bitacora::registrarAccion(usuario.getUsername(), "Consultó bitácora", "SEG002");
                break;
            }

            case 4:
                cout << "\nSaliendo del sistema...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Cerró sesión", "SAL001");
                break;

            default:
                cout << "Opción inválida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
}

// Función principal: punto de entrada del programa
//int main() { //comentado por problemas
   // Usuario usuario;

//  if (autenticarUsuario(usuario)) {
   //     cout << "\nAcceso concedido. Bienvenido, " << usuario.getNombre() << "!" << endl;
     //   Bitacora::registrarAccion(usuario.getUsername(), "Ingreso al sistema", "SEG001");
       // mostrarMenuPrincipal(usuario);
    //} else {
      //  cout << "\nError: Usuario o contraseña incorrectos.\n";
    //}

//    return 0;
// }
