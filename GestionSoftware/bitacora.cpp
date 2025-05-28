//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Bitacora.h"
#include <fstream>
#include <ctime>

void Bitacora::registrarAccion(const char* usuario, const char* accion, const char* codigo) {
    std::ofstream archivo("logs/bitacora.dat", std::ios::app);
    if (archivo.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now); // ya incluye \n
        archivo << "Usuario: " << usuario
                << " | Acción: " << accion
                << " | Código: " << codigo
                << " | Fecha y hora: " << dt;
        archivo.close();
    }
}
