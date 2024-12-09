#ifndef PUESTO_H
#define PUESTO_H

#include <string>
#include <ctime>

struct Puesto {
    int id;            // Identificador del puesto
    bool ocupado;      // Indica si el puesto está ocupado
    std::string placa; // Placa del vehículo en el puesto
    time_t horaEntrada; // Hora de entrada
    Puesto* siguiente; // Puntero al siguiente puesto

    Puesto(int _id) : id(_id), ocupado(false), placa(""), horaEntrada(0), siguiente(nullptr) {}
};

#endif // PUESTO_H
