//VehiculosAutorizados.cpp
#include "VehiculosAutorizados.h"
#include <iostream>
#include <fstream>
#include <ctime>
#include <sstream> // Para std::istringstream

void VehiculosAutorizados::agregarVehiculo(const std::string& placa, const std::string& propietario) {
    // Agregar al mapa en memoria
    autorizados[placa] = propietario;

    // Mensaje de confirmación
    std::cout << "Vehiculo autorizado correctamente.\n";
}

void VehiculosAutorizados::eliminarVehiculo(const std::string& placa) {
    auto it = autorizados.find(placa);
    if (it != autorizados.end()) {
        // Eliminar del mapa en memoria
        autorizados.erase(it);

        // Mensaje de confirmación
        std::cout << "Vehiculo eliminado correctamente.\n";
    } else {
        std::cout << "Vehiculo con placa " << placa << " no esta autorizado.\n";
    }
}

void VehiculosAutorizados::mostrarVehiculos() {
    if (autorizados.empty()) {
        std::cout << "No hay vehículos autorizados.\n";
        return;
    }

    std::cout << "--- Vehiculos Autorizados ---\n";
    for (const auto& [placa, propietario] : autorizados) {
        std::cout << "Placa: " << placa << ", Propietario: " << propietario << "\n";
    }
}


bool VehiculosAutorizados::estaAutorizado(const std::string& placa) {
    return autorizados.find(placa) != autorizados.end();
}

void VehiculosAutorizados::cargarDesdeArchivo(const std::string& nombreArchivo) {
    std::ifstream archivo(nombreArchivo);
    if (!archivo) {
        std::cout << "Error: No se pudo abrir el archivo " << nombreArchivo << ".\n";
        return;
    }

    std::string placa, propietario, cedula;
    while (archivo) {
        std::string linea;
        std::getline(archivo, linea);
        if (linea.empty()) continue;

        std::istringstream stream(linea);

        if (stream >> placa >> propietario) {
            // Leer cédula si está presente, pero no almacenarla
            if (stream >> cedula) {
                std::cout << "Cargando con cédula: " << cedula << "\n"; // Depuración opcional
            }
            autorizados[placa] = propietario;
        } else {
            std::cout << "Error: Formato de línea inválido en el archivo: " << linea << "\n";
        }
    }

    archivo.close();
    std::cout << "Vehículos autorizados cargados correctamente.\n";
}


std::unordered_map<std::string, std::string> VehiculosAutorizados::obtenerTodos() const {
    return autorizados;
}
