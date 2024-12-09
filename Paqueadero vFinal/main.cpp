#include "CircularList.h"
#include "VehiculosAutorizados.h"
#include "menu.h"
#include <iostream>
#include <conio.h>

// Declaraciones de las funciones de las opciones del menú
void ingresarVehiculo(ListaCircular& parqueadero, VehiculosAutorizados& autorizados);
void retirarVehiculo(ListaCircular& parqueadero);
void mostrarParqueadero(ListaCircular& parqueadero);
void mostrarVehiculosAutorizados(VehiculosAutorizados& autorizados);
void eliminarVehiculoAutorizado(VehiculosAutorizados& autorizados);
void mostrarResumen(ListaCircular& parqueadero);
void autorizarNuevoVehiculo(VehiculosAutorizados& autorizados);

int main() {
    ListaCircular parqueadero;
    parqueadero.crearParqueadero(80);

    VehiculosAutorizados autorizados;
    autorizados.cargarDesdeArchivo("vehiculosAutorizados.txt");

    int opcion;
    do {
        opcion = menuConFlechas(); // Obtener opción seleccionada
        switch (opcion) {
        case 1:
            ingresarVehiculo(parqueadero, autorizados);
            break;
        case 2:
            retirarVehiculo(parqueadero);
            break;
        case 3:
            mostrarParqueadero(parqueadero);
            break;
        case 4:
            mostrarVehiculosAutorizados(autorizados);
            break;
        case 5:
            eliminarVehiculoAutorizado(autorizados);
            break;
        case 6:
            mostrarResumen(parqueadero);
            break;
        case 7:
            autorizarNuevoVehiculo(autorizados);
            break;
        case 8:
            parqueadero.dibujarParqueaderoCircular();
            break;
        case 9:
            std::cout << "Saliendo del sistema...\n";
            break;
        default:
            std::cout << "Opción inválida. Intenta de nuevo.\n";
        }

        if (opcion != 9) {
            std::cout << "\nPresiona cualquier tecla para continuar...\n";
            _getch(); // Pausa antes de regresar al menú
        }
    } while (opcion != 9);

    return 0;
}
