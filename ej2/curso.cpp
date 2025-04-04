#include "curso.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<Curso*> Curso::cursosDisponibles;

// Constructores

Curso::Curso(const string& nombre) : nombre(nombre) {}

Curso::~Curso() {}

// Constructor de copia (Shallow Copy)
/*
 Dado que varios cursos pueden compartir estudiantes, este constructor copia los punteros a los estudiantes,
 en lugar de duplicar los objetos de estudiante. Esto significa que cualquier cambio en los estudiantes
 (como modificar su nota o eliminarlo) se reflejará en todas las instancias de Curso que lo contengan.
 */
// Constructor de copia con opción de renombrar
Curso::Curso(const Curso& otro, const string& nuevoNombre)
    : nombre(nuevoNombre.empty() ? otro.nombre : nuevoNombre), estudiantes(otro.estudiantes) {}
// Operador de asignación (Shallow Copy)
/*
 Similar al constructor de copia, este operador copia la lista de punteros a estudiantes.
 Se asegura de que el curso de destino tenga los mismos estudiantes que el curso de origen.
 */
Curso& Curso::operator=(const Curso& otro) {
    if (this != &otro) {  // Evita autoasignación
        nombre = otro.nombre;
        estudiantes = otro.estudiantes;
    }
    return *this;
}

// Métodos
void Curso::asignarNotaAEstudiante(int legajo, float nota) {
    for (auto* estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) {
            estudiante->asignarNota(nombre, nota);
            return;
        }
    }
    cout << "Estudiante con legajo " << legajo << " no encontrado en el curso " << nombre << ".\n";
}

void Curso::inscribirEstudiante(Estudiante* estudiante) {

    if (estaInscripto(estudiante->getLegajo())) {
        cout << "El estudiante ya está inscripto en el curso.\n";
        return;
    }

    if (estaCompleto()) {
        cout << "El curso está completo. No se puede inscribir más estudiantes.\n";
        return;
    }

    estudiantes.push_back(estudiante);
    cout << "Estudiante " << estudiante->getNombre() << " inscrito en el curso " << nombre << ".\n";
    cout << "------------------------\n";

}

void Curso::desinscribirEstudiante(int legajo) {
    if (!estaInscripto(legajo)) {
        cout << "Estudiante con legajo " << legajo << " no encontrado en el curso " << nombre << ".\n";
        return;
    }

    auto it = remove_if(estudiantes.begin(), estudiantes.end(),
        [legajo, this](Estudiante* est) {
            if (est->getLegajo() == legajo) {
                est->eliminarNota(nombre); // Elimina las notas del curso
                return true;
            }
            return false;
        });

    estudiantes.erase(it, estudiantes.end());
    cout << "Estudiante con legajo " << legajo << " desinscripto del curso " << nombre << ".\n";
}

bool Curso::estaInscripto(int legajo) const {
    for (const auto& estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) return true;
    }
    return false;
}

bool Curso::estaCompleto() const {
    return estudiantes.size() >= 20;
}

void Curso::imprimirEstudiantes() const {
    for (const auto& estudiante : estudiantes) {
        cout << *estudiante << "\n";
    }
}

ostream& operator<<(ostream& os, const Curso& curso) {
    os << "Curso: " << curso.nombre;
    return os;
}