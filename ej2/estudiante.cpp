#include "estudiante.h"
#include <iostream>
#include <numeric>

Estudiante::Estudiante(const std::string& nombre, int legajo) 
    : nombre(nombre), legajo(legajo) {}

void Estudiante::agregarCurso(const std::string& curso, float nota) {
    cursos[curso] = nota;
}

std::string Estudiante::getNombre() const {
    return nombre;
}
int Estudiante::getLegajo() const {
    return legajo;
}

float Estudiante::getPromedio() const {
    if (cursos.empty()) return 0.0f; // Evitar división por cero
    float suma = std::accumulate(cursos.begin(), cursos.end(), 0.0f,
        [](float total, const std::pair<std::string, float>& par) {
            return total + par.second;
        });
    return suma / cursos.size();
}

bool Estudiante::operator<(const Estudiante& otro) const {
    return nombre < otro.nombre; // Ordenar por nombre
}

std::ostream& operator<<(std::ostream& os, const Estudiante& e) {
    os << "Nombre: " << e.nombre << ", Legajo: " << e.legajo << ", Promedio: " << e.getPromedio() << "\nCursos:\n";
    for (const auto& par : e.cursos) {
        os << "  " << par.first << ": " << par.second << "\n";
    }
    return os;
}

