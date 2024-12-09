#include "CircularList.h"
#include "dibujarParqueadero.h"
#include <iostream>

ListaCircular::ListaCircular() : cabeza(nullptr) {}

ListaCircular::~ListaCircular() {
    if (cabeza) {
        Puesto* actual = cabeza->siguiente;
        Puesto* temporal;
        while (actual != cabeza) {
            temporal = actual;
            actual = actual->siguiente;
            delete temporal;
        }
        delete cabeza;
    }
}

void ListaCircular::crearParqueadero(int cantidad) {
    if (cantidad <= 0) return;

    cabeza = new Puesto(1);
    Puesto* actual = cabeza;

    for (int i = 2; i <= cantidad; ++i) {
        Puesto* nuevoPuesto = new Puesto(i);
        actual->siguiente = nuevoPuesto;
        actual = nuevoPuesto;
    }
    actual->siguiente = cabeza; // Hacerlo circular
}

void ListaCircular::mostrarParqueadero() {
    if (!cabeza) {
        std::cout << "No hay espacios de parqueadero disponibles.\n";
        return;
    }

    Puesto* actual = cabeza;
    do {
        std::cout << "Puesto " << actual->id;
        if (actual->ocupado) {
            std::cout << " - Ocupado";
        } else {
            std::cout << " - Disponible";
        }
        std::cout << "\n";
        actual = actual->siguiente;
    } while (actual != cabeza);
}

bool ListaCircular::ingresarCarro(const std::string& placa, int numeroPuesto) {
    if (!cabeza) return false;

    Puesto* actual = cabeza;
    do {
        if (actual->id == numeroPuesto) {
            if (!actual->ocupado) {
                actual->ocupado = true;
                actual->placa = placa;
                actual->horaEntrada = std::time(nullptr); // Registrar hora de entrada

                // Guardar en el historial
                std::ofstream historial("historial.txt", std::ios::app);
                if (historial) {
                    historial << "Entrada - Puesto: " << actual->id
                              << ", Placa: " << placa
                              << ", Hora: " << std::ctime(&actual->horaEntrada);
                }
                historial.close();

                return true;
            } else {
                return false; // El puesto está ocupado
            }
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false; // No se encontró el puesto
}

bool ListaCircular::placaEnUso(const std::string& placa) {
    if (!cabeza) return false;

    Puesto* actual = cabeza;
    do {
        if (actual->ocupado && actual->placa == placa) {
            return true; // La placa ya está ocupando un puesto
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false; // La placa no está en uso
}


bool ListaCircular::retirarCarro(int numeroPuesto) {
    if (!cabeza) return false;

    Puesto* actual = cabeza;
    do {
        if (actual->id == numeroPuesto && actual->ocupado) {
            time_t horaSalida = std::time(nullptr); // Registrar hora de salida

            // Guardar en el historial
            std::ofstream historial("historial.txt", std::ios::app);
            if (historial) {
                historial << "Salida - Puesto: " << actual->id
                          << ", Placa: " << actual->placa
                          << ", Hora entrada: " << std::ctime(&actual->horaEntrada)
                          << ", Hora salida: " << std::ctime(&horaSalida);
            }
            historial.close();

            // Liberar el puesto
            actual->ocupado = false;
            actual->placa = "";
            actual->horaEntrada = 0;

            return true;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false; // No se encontró el puesto o no está ocupado
}

bool ListaCircular::retirarCarroPorPlaca(const std::string& placa) {
    if (!cabeza) return false;

    Puesto* actual = cabeza;
    do {
        if (actual->ocupado && actual->placa == placa) {
            time_t horaSalida = std::time(nullptr); // Registrar hora de salida

            // Guardar en el historial
            std::ofstream historial("historial.txt", std::ios::app);
            if (historial) {
                historial << "Salida - Puesto: " << actual->id
                          << ", Placa: " << actual->placa
                          << ", Hora entrada: " << std::ctime(&actual->horaEntrada)
                          << ", Hora salida: " << std::ctime(&horaSalida);
            }
            historial.close();

            // Liberar el puesto
            actual->ocupado = false;
            actual->placa = "";
            actual->horaEntrada = 0;

            return true;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    return false; // No se encontró el vehículo con esa placa
}



void ListaCircular::resumenParqueadero() {
    if (!cabeza) {
        std::cout << "El parqueadero está vacío.\n";
        return;
    }

    int espaciosTotales = 0, espaciosOcupados = 0;
    Puesto* actual = cabeza;

    do {
        espaciosTotales++;
        if (actual->ocupado) {
            espaciosOcupados++;
        }
        actual = actual->siguiente;
    } while (actual != cabeza);

    std::cout << "Resumen del Parqueadero:\n";
    std::cout << "Espacios totales: " << espaciosTotales << "\n";
    std::cout << "Espacios ocupados: " << espaciosOcupados << "\n";
    std::cout << "Espacios disponibles: " << (espaciosTotales - espaciosOcupados) << "\n";
}

void ListaCircular::dibujarParqueaderoCircular() {
    if (!cabeza) {
        std::cout << "No hay puestos en el parqueadero.\n";
        return;
    }

    int totalPuestos = 0;
    Puesto* actual = cabeza;

    do {
        totalPuestos++;
        actual = actual->siguiente;
    } while (actual != cabeza);

    ::dibujarParqueadero(cabeza, totalPuestos); // Usar el operador :: para llamar a la función global
}

