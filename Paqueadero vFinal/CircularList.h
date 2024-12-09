#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include "puesto.h" // Incluir la definición de la estructura Puesto
#include <iostream>
#include <fstream>
#include <string>

class ListaCircular {
private:
    Puesto* cabeza; // Cambiar de Nodo* a Puesto*

public:
    ListaCircular();
    ~ListaCircular();

    void crearParqueadero(int cantidad);
    void mostrarParqueadero();
    bool ingresarCarro(const std::string& placa, const std::string& usuario);
    bool retirarCarro(int numeroParqueadero);
    void resumenParqueadero();
    void dibujarParqueaderoCircular(); // Cambiar nombre para evitar conflicto
    bool ingresarCarro(const std::string& placa, int numeroPuesto);
    bool retirarCarroPorPlaca(const std::string& placa);
    bool placaEnUso(const std::string& placa);



};

#endif // CIRCULARLIST_H
