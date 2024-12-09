#ifndef VALIDACIONES_H
#define VALIDACIONES_H

#include <string>
#include <regex>
#include <conio.h>
#include <iostream>

class Validaciones {
public:
    // Validar cédula ecuatoriana
    static bool validarCedula(const std::string& cedula);

    // Validar nombre y apellido (sin caracteres especiales, solo letras)
    static bool validarNombre(const std::string& nombre);

    // Leer entrada sin espacios ni letras (para cédula)
    static std::string leerCedula();

    // Leer entrada sin números ni espacios (para nombre y apellido)
    static std::string leerNombre();
};

#endif // VALIDACIONES_H
