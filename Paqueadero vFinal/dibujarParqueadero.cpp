#include "dibujarParqueadero.h"
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <iomanip>

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

void dibujarParqueadero(Puesto* cabeza, int totalPuestos) {
    if (!cabeza) {
        std::cout << "No hay puestos en el parqueadero.\n";
        return;
    }

    // Configuración del círculo
    const int radius = 15; // Radio del círculo (ajustado para evitar solapamientos)
    const int gridSize = radius * 2 + 5; // Tamaño de la cuadrícula
    std::vector<std::vector<std::string>> grid(gridSize, std::vector<std::string>(gridSize, "     "));

    // Centro del círculo
    const int centerX = gridSize / 2;
    const int centerY = gridSize / 2;

    // Incremento angular para distribuir los puestos uniformemente
    double angleIncrement = 2 * M_PI / totalPuestos;
    double angle = 0.0;

    Puesto* actual = cabeza;

    for (int i = 0; i < totalPuestos; ++i) {
        // Calcular posición (x, y) en la cuadrícula usando coordenadas polares
        int x = centerX + static_cast<int>(radius * cos(angle));
        int y = centerY + static_cast<int>(radius * sin(angle));

        // Asegurarse de que las coordenadas están dentro del rango de la cuadrícula
        if (x >= 0 && x < gridSize && y >= 0 && y < gridSize) {
            // Solo colocar si la celda está vacía
            if (grid[y][x] == "     ") {
                grid[y][x] = actual->ocupado ? "[" + std::to_string(actual->id) + "X]" : "[" + std::to_string(actual->id) + " ]";
            }
        }

        // Mover al siguiente puesto y actualizar el ángulo
        actual = actual->siguiente;
        angle += angleIncrement;
    }

    // Dibujar la cuadrícula
    std::cout << "Parqueadero Circular:\n\n";
    for (const auto& row : grid) {
        for (const auto& cell : row) {
            std::cout << cell;
        }
        std::cout << '\n';
    }

    // Leyenda
    std::cout << "\nLeyenda:\n";
    std::cout << "[N ] - Libre (N es el numero del puesto)\n";
    std::cout << "[NX] - Ocupado\n";
}
