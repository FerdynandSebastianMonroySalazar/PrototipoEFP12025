//Ferdynand Monroy 9959 24 14049 Mayo 2025
#include "Bitacora.h"
#include <fstream>
#include <iostream>

void Bitacora::registrarAccion(const std::string& usuario, const std::string& accion, const std::string& appCode) {
    std::ofstream archivo("logs/bitacora.dat", std::ios::app | std::ios::binary);
    if (archivo.is_open()) {
        time_t now = time(0);
        char* dt = ctime(&now);
        archivo << "Usuario: " << usuario
                << " | Acción: " << accion
                << " | Código: " << appCode
                << " | Fecha y hora: " << dt;
        archivo.close();
    } else {
        std::cerr << "Error al registrar en la bitácora.\n";
    }
}
