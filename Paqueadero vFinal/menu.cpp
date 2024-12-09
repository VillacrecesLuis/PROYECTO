#include "menu.h"
#include <iostream>
#include <conio.h>

void mostrarMenu(int opcionSeleccionada, const std::string opciones[], int totalOpciones) {
    system("cls"); // Limpia la pantalla
    std::cout << "MENU PRINCIPAL\n";
    std::cout << "=============================\n";
    for (int i = 0; i < totalOpciones; ++i) {
        if (i == opcionSeleccionada) {
            std::cout << " > "; // Indicar opción seleccionada
        } else {
            std::cout << "   "; // Espaciado para opciones no seleccionadas
        }
        std::cout << opciones[i] << "\n";
    }
    std::cout << "=============================\n";
}

int menuConFlechas() {
    const std::string opciones[] = {
        "Ingresar vehiculo",
        "Retirar vehiculo",
        "Mostrar parqueadero",
        "Mostrar vehiculos autorizados",
        "Eliminar vehiculo autorizado",
        "Mostrar resumen del parqueadero",
        "Autorizar nuevo vehiculo",
        "Dibujar parqueadero",
        "Salir"
    };
    const int totalOpciones = sizeof(opciones) / sizeof(opciones[0]);

    int opcionSeleccionada = 0; // Índice inicial (base 0)
    while (true) {
        mostrarMenu(opcionSeleccionada, opciones, totalOpciones);

        // Capturar la tecla presionada
        char tecla = _getch();

        if (tecla == -32) { // Detecta tecla especial (flechas)
            tecla = _getch(); // Lee el valor de la tecla especial
            if (tecla == 72) { // Flecha hacia arriba
                opcionSeleccionada = (opcionSeleccionada - 1 + totalOpciones) % totalOpciones;
            } else if (tecla == 80) { // Flecha hacia abajo
                opcionSeleccionada = (opcionSeleccionada + 1) % totalOpciones;
            }
        } else if (tecla == '\r') { // Enter
            return opcionSeleccionada + 1; // Convertir a base 1
        }
    }
}
