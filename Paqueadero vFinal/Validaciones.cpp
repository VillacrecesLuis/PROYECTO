#include "Validaciones.h"

bool Validaciones::validarCedula(const std::string& cedula) {
    if (cedula.length() != 10) return false;

    int suma = 0;
    for (int i = 0; i < 9; ++i) {
        int num = cedula[i] - '0';
        if (i % 2 == 0) { // Posiciones pares
            num *= 2;
            if (num > 9) num -= 9;
        }
        suma += num;
    }

    int digitoVerificador = cedula[9] - '0';
    int modulo = suma % 10;
    int resultado = modulo == 0 ? 0 : 10 - modulo;

    return resultado == digitoVerificador;
}

bool Validaciones::validarNombre(const std::string& nombre) {
    const std::regex pattern(R"([A-Za-z]+(\s[A-Za-z]+)*)"); // Permite nombres compuestos
    return std::regex_match(nombre, pattern);
}

std::string Validaciones::leerCedula() {
    std::string entrada;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (isdigit(ch)) {
            entrada += ch;
            std::cout << ch;
        }
        else if (ch == '\b' && !entrada.empty()) {
            entrada.pop_back();
            std::cout << "\b \b";
        }
    }
    std::cout << std::endl;
    return entrada;
}

std::string Validaciones::leerNombre() {
    std::string entrada;
    char ch;
    while ((ch = _getch()) != '\r') {
        if (isalpha(ch) || ch == ' ') {
            entrada += ch;
            std::cout << ch;
        }
        else if (ch == '\b' && !entrada.empty()) {
            entrada.pop_back();
            std::cout << "\b \b";
        }
    }
    std::cout << std::endl;
    return entrada;
}
