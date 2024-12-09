#include "CircularList.h"
#include "VehiculosAutorizados.h"
#include "validacionPlaca.h"
#include <iostream>

void ingresarVehiculo(ListaCircular& parqueadero, VehiculosAutorizados& autorizados) {
    while (true) {
        std::string placa;
        int puestoDeseado;

        // Solicitar la placa del vehículo
        std::cout << "Ingrese la placa del vehiculo (o escribe 'menu' para regresar): ";
        std::cin >> placa;

        // Regresar al menú principal
        if (placa == "menu") {
            std::cout << "Regresando al menu principal...\n";
            break;
        }

        // Validar el formato de la placa
        placa = convertirAMayusculas(placa);
        if (!validarPlaca(placa)) {
            std::cout << "Error: La placa ingresada no es valida. Intenta de nuevo.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Verificar si la placa ya está ocupando un puesto
        if (parqueadero.placaEnUso(placa)) {
            std::cout << "Error: La placa ya esta ocupando un puesto en el parqueadero. Intenta con otra placa.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Verificar si la placa está autorizada
        if (!autorizados.estaAutorizado(placa)) {
            std::cout << "Error: La placa no esta autorizada. Intenta de nuevo.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Mostrar el estado actual del parqueadero
        parqueadero.mostrarParqueadero();

        // Solicitar el puesto deseado
        std::cout << "Ingrese el numero de puesto deseado (o escribe 'menu' para regresar): ";
        std::string entrada;
        std::cin >> entrada;

        // Regresar al menú principal
        if (entrada == "menu") {
            std::cout << "Regresando al menu principal...\n";
            break;
        }

        // Validar que el puesto ingresado sea un número
        try {
            puestoDeseado = std::stoi(entrada);
        } catch (...) {
            std::cout << "Error: El puesto ingresado no es un numero valido. Intenta de nuevo.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Intentar ingresar el vehículo en el puesto deseado
        if (parqueadero.ingresarCarro(placa, puestoDeseado)) {
            std::cout << "Vehiculo con placa " << placa << " ingresado correctamente en el puesto " << puestoDeseado << ".\n";
            break; // Salir del bucle tras una operación exitosa
        } else {
            std::cout << "Error: El puesto " << puestoDeseado << " no esta disponible o es invalido. Intenta de nuevo.\n";
        }
    }
}
