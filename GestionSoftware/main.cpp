//Proyecto examen final Programaci�n I por Ferdynand Monroy 9959 24 14049 Mayo 2025
//Main de todo el programa
// Proyecto examen final Programaci�n I por Ferdynand Monroy 9959 24 14049 Mayo 2025
// Main de todo el programa
// Proyecto examen final Programaci�n I - Ferdynand Monroy 9959 24 14049 - Mayo 2025
// Archivo principal del programa

#include <iostream>
#include <fstream>
#include <cstring>
#include "Usuario.h"
#include "Menu.h"
#include "Bitacora.h"

using namespace std;

// Funci�n para autenticar usuario desde archivo binario
bool autenticarUsuario(Usuario& usuarioAutenticado) {
    char inputUser[15], inputPass[15];
    cout << "=== INICIO DE SESI�N ===" << endl;
    cout << "Usuario: ";
    cin >> inputUser;
    cout << "Contrase�a: ";
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

// Funci�n para mostrar el men� principal
void mostrarMenuPrincipal(Usuario usuario) {
    int opcion;
    do {
        Menu::mostrarMenuPrincipal(usuario.getUsername(), usuario.getCarnet(), usuario.getNombre());
        cout << "Seleccione una opci�n: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "\nEntrando a Cat�logos...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Entr� al submen� de cat�logos", "CAT001");
                break;

            case 2:
                cout << "\nGenerando informe (simulado)...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Gener� informe", "INF001");
                break;

            case 3: {
                cout << "\n--- Bit�cora de Seguridad ---\n";
                ifstream bitacora("logs/bitacora.dat");
                if (!bitacora.is_open()) {
                    cout << "No se pudo abrir la bit�cora.\n";
                    break;
                }
                string linea;
                while (getline(bitacora, linea)) {
                    cout << linea << endl;
                }
                bitacora.close();
                Bitacora::registrarAccion(usuario.getUsername(), "Consult� bit�cora", "SEG002");
                break;
            }

            case 4:
                cout << "\nSaliendo del sistema...\n";
                Bitacora::registrarAccion(usuario.getUsername(), "Cerr� sesi�n", "SAL001");
                break;

            default:
                cout << "Opci�n inv�lida. Intente de nuevo.\n";
                break;
        }
    } while (opcion != 4);
}

// Funci�n principal: punto de entrada del programa
//int main() { //comentado por problemas
   // Usuario usuario;

//  if (autenticarUsuario(usuario)) {
   //     cout << "\nAcceso concedido. Bienvenido, " << usuario.getNombre() << "!" << endl;
     //   Bitacora::registrarAccion(usuario.getUsername(), "Ingreso al sistema", "SEG001");
       // mostrarMenuPrincipal(usuario);
    //} else {
      //  cout << "\nError: Usuario o contrase�a incorrectos.\n";
    //}

//    return 0;
// }
