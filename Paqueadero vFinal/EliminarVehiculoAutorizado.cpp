#include "VehiculosAutorizados.h"
#include "validacionPlaca.h"
#include <iostream>
#include <fstream>

void eliminarVehiculoAutorizado(VehiculosAutorizados& autorizados) {
    while (true) {
        std::string placa;

        // Solicitar la placa del vehículo
        std::cout << "Ingrese la placa del vehiculo a eliminar (o escribe 'menu' para regresar): ";
        std::cin >> placa;

        // Regresar al menú principal
        if (placa == "menu") {
            std::cout << "Regresando al menu principal...\n";
            break;
        }

        // Convertir la placa a mayúsculas para consistencia
        placa = convertirAMayusculas(placa);

        // Validar el formato de la placa
        if (!validarPlaca(placa)) {
            std::cout << "Error: La placa ingresada no es valida. Intenta de nuevo.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Verificar si la placa está autorizada
        if (!autorizados.estaAutorizado(placa)) {
            std::cout << "Error: La placa no esta autorizada. Intenta de nuevo.\n";
            continue; // Permitir que el usuario intente nuevamente
        }

        // Eliminar la placa del sistema en memoria
        autorizados.eliminarVehiculo(placa);

        // Reescribir el archivo con los datos actualizados
        std::ofstream archivo("vehiculosAutorizados.txt");
        if (!archivo) {
            std::cout << "Error: No se pudo abrir el archivo para actualizar los datos.\n";
            break;
        }

        for (const auto& [placa, propietario] : autorizados.obtenerTodos()) {
            archivo << placa << " " << propietario << "\n";
        }

        archivo.close();
        std::cout << "Vehiculo con placa " << placa << " eliminado correctamente.\n";
        break; // Salir del bucle tras una operación exitosa
    }
}
