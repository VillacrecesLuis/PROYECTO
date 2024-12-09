#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <set>
#include "Validaciones.h"
#include "validacionPlaca.h"

// Función para verificar y limpiar el archivo vehiculosAutorizados.txt
void verificarYLimpiarArchivo(const std::string& archivo) {
    std::ifstream archivoEntrada(archivo);
    if (!archivoEntrada) {
        std::cout << "Error: No se pudo abrir el archivo " << archivo << " para verificar.\n";
        return;
    }

    std::unordered_map<std::string, std::pair<std::string, std::string>> datosValidos; // Mapa de placa -> {nombre, cédula}
    std::set<std::string> cedulasUsadas; // Almacenar cédulas únicas
    std::set<std::string> entradasInvalidas; // Almacenar líneas con errores

    std::string linea, placa, nombre, cedula;
    while (std::getline(archivoEntrada, linea)) {
        std::istringstream stream(linea);
        if (!(stream >> placa >> nombre >> cedula)) {
            entradasInvalidas.insert(linea);
            continue;
        }

        // Validar cada campo
        if (!validarPlaca(placa)) {
            entradasInvalidas.insert(linea);
            continue;
        }

        if (!Validaciones::validarNombre(nombre)) {
            entradasInvalidas.insert(linea);
            continue;
        }

        if (!Validaciones::validarCedula(cedula)) {
            entradasInvalidas.insert(linea);
            continue;
        }

        // Verificar duplicados de cédula con diferente nombre
        if (cedulasUsadas.count(cedula) && datosValidos[placa].first != nombre) {
            entradasInvalidas.insert(linea);
            continue;
        }

        // Si todo está bien, guardar el registro
        datosValidos[placa] = {nombre, cedula};
        cedulasUsadas.insert(cedula);
    }

    archivoEntrada.close();

    // Escribir los datos válidos al archivo
    std::ofstream archivoSalida(archivo);
    if (!archivoSalida) {
        std::cout << "Error: No se pudo abrir el archivo " << archivo << " para escribir los datos verificados.\n";
        return;
    }

    for (const auto& [placa, datos] : datosValidos) {
        archivoSalida << placa << " " << datos.first << " " << datos.second << "\n";
    }
    archivoSalida.close();

    // Reportar resultados
    if (entradasInvalidas.empty()) {
        std::cout << "Archivo verificado: No se encontraron errores.\n";
    } else {
        std::cout << "Archivo verificado: Se encontraron y corrigieron errores en las siguientes entradas:\n";
        for (const auto& entrada : entradasInvalidas) {
            std::cout << entrada << "\n";
        }
    }
}
