#include "CircularList.h"
#include <iostream>
#include <string>
#include <conio.h> // Para usar _getch()

void retirarVehiculo(ListaCircular& parqueadero) {
    while (true) {
        std::string opcion;

        // Solicitar la opción de retiro
        std::cout << "Deseas retirar por puesto (1) o por placa (2)? (Escribe 'menu' para regresar): ";
        std::getline(std::cin, opcion);

        // Regresar al menú principal
        if (opcion == "menu") {
            std::cout << "Regresando al menu principal...\n";
            return;
        }

        // Validar opción de retiro
        if (opcion == "1") {
            // Retiro por número de puesto
            std::string entrada;
            char tecla;

            std::cout << "Ingresa el numero del parqueadero: ";

            // Captura de entrada con _getch
            while (true) {
                tecla = _getch(); // Leer una tecla sin mostrarla en pantalla

                // Si el usuario presiona Enter, finaliza la entrada
                if (tecla == '\r') { // '\r' es el código para Enter
                    std::cout << "\n";
                    break;
                }

                // Validar que la tecla sea un número
                if (std::isdigit(tecla)) {
                    entrada += tecla; // Agregar el número a la entrada
                    std::cout << tecla; // Mostrarlo en pantalla
                } else {
                    std::cout << "\nError: Solo se permiten numeros.\n";
                    entrada.clear(); // Reinicia la entrada
                    std::cout << "Ingresa el numero del parqueadero: ";
                }
            }

            // Convertir la entrada a un número
            int numeroParqueadero = std::stoi(entrada);

            // Intentar retirar el vehículo
            if (parqueadero.retirarCarro(numeroParqueadero)) {
                std::cout << "Vehiculo retirado correctamente.\n";
                break;
            } else {
                std::cout << "Numero de parqueadero invalido o no hay vehiculo en ese espacio. Intenta de nuevo.\n";
            }
        } else if (opcion == "2") {
            // Retiro por placa
            std::string placa;
            std::cout << "Ingresa la placa del vehiculo: ";
            std::cin >> placa;

            // Intentar retirar el vehículo por placa
            if (parqueadero.retirarCarroPorPlaca(placa)) {
                std::cout << "Vehiculo con placa " << placa << " retirado correctamente.\n";
                break;
            } else {
                std::cout << "Error: No se encontro un vehiculo con la placa " << placa << ". Intenta de nuevo.\n";
            }
        } else {
            // Opción inválida
            std::cout << "Opcion invalida. Intenta de nuevo.\n";
        }
    }
}

