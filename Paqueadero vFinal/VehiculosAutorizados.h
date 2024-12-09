#ifndef VEHICULOSAUTORIZADOS_H
#define VEHICULOSAUTORIZADOS_H

#include <string>
#include <unordered_map>

class VehiculosAutorizados {
private:
    std::unordered_map<std::string, std::string> autorizados;

public:
    void agregarVehiculo(const std::string& placa, const std::string& propietario);
    void eliminarVehiculo(const std::string& placa);
    void mostrarVehiculos();
    bool estaAutorizado(const std::string& placa);
    void cargarDesdeArchivo(const std::string& nombreArchivo);
    std::unordered_map<std::string, std::string> obtenerTodos() const; // Declaración sin cuerpo
};

#endif // VEHICULOSAUTORIZADOS_H

