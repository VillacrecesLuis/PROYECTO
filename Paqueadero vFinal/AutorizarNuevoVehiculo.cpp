#include "VehiculosAutorizados.h"
#include "validacionPlaca.h"
#include "Validaciones.h"
#include <iostream>
#include <fstream>
#include <unordered_map>

// Cargar los datos actuales desde el archivo para evitar duplicados
std::unordered_map<std::string, std::pair<std::string, std::string>> cargarDatos() {
    std::unordered_map<std::string, std::pair<std::string, std::string>> datos;
    std::ifstream archivo("vehiculosAutorizados.txt");
    if (archivo) {
        std::string placa, nombre, cedula;
        while (archivo >> placa >> nombre >> cedula) {
            datos[placa] = {nombre, cedula};
        }
        archivo.close();
    }
    return datos;
}

void autorizarNuevoVehiculo(VehiculosAutorizados& autorizados) {
    // Cargar los datos actuales
    auto datosExistentes = cargarDatos();

    while (true) {
        std::string placa, propietario, cedula;

        // Solicitar la placa del vehículo
        std::cout << "Ingrese la placa del vehiculo (o escribe 'menu' para regresar): ";
        std::cin >> placa;

        if (placa == "menu") {
            std::cout << "Regresando al menu principal...\n";
            break;
        }

        placa = convertirAMayusculas(placa);
        if (!validarPlaca(placa)) {
            std::cout << "Error: La placa ingresada no es valida. Intenta de nuevo.\n";
            continue;
        }

        if (autorizados.estaAutorizado(placa)) {
            std::cout << "Error: La placa ya esta autorizada. Intenta de nuevo.\n";
            continue;
        }

        // Solicitar el nombre del propietario
        std::cout << "Ingrese el nombre del propietario: ";
        propietario = Validaciones::leerNombre();
        if (!Validaciones::validarNombre(propietario)) {
            std::cout << "Error: El nombre ingresado no es valido. Intenta de nuevo.\n";
            continue;
        }

        // Solicitar la cédula del propietario
        std::cout << "Ingrese la cedula del propietario: ";
        cedula = Validaciones::leerCedula();
        if (!Validaciones::validarCedula(cedula)) {
            std::cout << "Error: La cedula ingresada no es valida. Intenta de nuevo.\n";
            continue;
        }

        // Verificar si la cédula ya está en uso
        bool cedulaValida = true;
        for (const auto& [_, datos] : datosExistentes) {
            const auto& [nombreExistente, cedulaExistente] = datos;
            if (cedula == cedulaExistente && propietario != nombreExistente) {
                std::cout << "Error: La cedula ya esta asociada a otro nombre (" << nombreExistente << ").\n";
                cedulaValida = false;
                break;
            }
        }

        if (!cedulaValida) continue;

        // Agregar la placa al sistema en memoria
        autorizados.agregarVehiculo(placa, propietario);

        // Actualizar el archivo
        std::ofstream archivo("vehiculosAutorizados.txt", std::ios::app);
        if (!archivo) {
            std::cout << "Error: No se pudo abrir el archivo.\n";
            return;
        }
        archivo << placa << " " << propietario << " " << cedula << "\n";
        archivo.close();

        std::cout << "Vehiculo con placa " << placa << ", propietario " << propietario
                  << " y cedula " << cedula << " autorizado correctamente.\n";
        break;
    }
}
