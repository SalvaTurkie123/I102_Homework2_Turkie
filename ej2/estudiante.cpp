#include "estudiante.h"
#include <iostream>
#include <numeric>

using namespace std;

Estudiante::Estudiante(const std::string& nombre, int legajo) 
    : nombre(nombre), legajo(legajo) {}

std::string Estudiante::getNombre() const {
    return nombre;
}
int Estudiante::getLegajo() const {
    return legajo;
}

float Estudiante::getPromedio() const {
    if (cursos.empty()) return 0.0f;

    float suma = 0.0f;
    for (const auto& [curso, nota] : cursos) {
        suma += nota;
    }

    return suma / cursos.size();
}

void Estudiante::mostrarNotas() const {
    if (cursos.empty()) {
        cout << "El estudiante " << nombre << " no tiene notas registradas.\n";
        return;
    }

    cout << "Notas de " << nombre << " (Legajo: " << legajo << "):\n";
    for (const auto& [curso, nota] : cursos) {
        cout << "- " << curso << ": " << nota << "\n";
    }

    cout << "Promedio general: " << getPromedio() << "\n";
}

void Estudiante::eliminarNota(const std::string& curso) {
    auto it = cursos.find(curso);
    if (it != cursos.end()) {
        cursos.erase(it);
        cout << "Nota del curso " << curso << " eliminada para el estudiante " << nombre << ".\n";
    } else {
        cout << "El estudiante " << nombre << " no tiene nota registrada para el curso " << curso << ".\n";
    }
  }

void Estudiante::asignarNota(const std::string& curso, float nota) {
    cursos[curso] = nota;
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
