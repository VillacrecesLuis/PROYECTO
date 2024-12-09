#include "validacionPlaca.h"
#include <set>
#include <cctype>

// Lista de letras válidas para las provincias de Ecuador
const std::set<char> provinciasValidas = {
    'A', 'B', 'U', 'C', 'X', 'H', 'O', 'E', 'W',
    'G', 'I', 'L', 'R', 'M', 'V', 'N', 'S', 'P',
    'Q', 'K', 'T', 'Z', 'Y', 'J'
};

bool validarPlaca(const std::string& placa) {
    // Convertir la placa a mayúsculas
    std::string placaMayus = convertirAMayusculas(placa);

    // Verificar longitud: debe ser de 6 o 7 caracteres
    if (placaMayus.size() != 6 && placaMayus.size() != 7) {
        return false;
    }

    // Verificar que el primer carácter sea una provincia válida
    char provincia = placaMayus[0];
    if (provinciasValidas.find(provincia) == provinciasValidas.end()) {
        return false;
    }

    // Verificar que los caracteres 2 y 3 sean letras
    if (!std::isalpha(placaMayus[1]) || !std::isalpha(placaMayus[2])) {
        return false;
    }

    // Verificar que los últimos caracteres sean números
    for (size_t i = 3; i < placaMayus.size(); ++i) {
        if (!std::isdigit(placaMayus[i])) {
            return false;
        }
    }

    // Si pasa todas las verificaciones
    return true;
}

std::string convertirAMayusculas(const std::string& texto) {
    std::string resultado = texto;
    for (char& c : resultado) {
        c = std::toupper(c);
    }
    return resultado;
}

