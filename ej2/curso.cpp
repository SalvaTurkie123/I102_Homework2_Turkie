#include "curso.h"

// Constructores

Curso::Curso() {}

Curso::Curso(const Curso& otro) {
    for (const auto& estudiante : otro.estudiantes) {
        estudiantes.push_back(new Estudiante(*estudiante)); // 
    }
}

/*
Justificación: Se usa una copia profunda para evitar que al destruir un objeto
Curso se eliminen estudiantes que aún pertenecen a otro curso.
*/

Curso::~Curso() {
    for (auto* estudiante : estudiantes) {
        delete estudiante;
    }
}

// Métodos

bool Curso::inscribirEstudiante(Estudiante* estudiante) {
    if (estaCompleto() || estaInscrito(estudiante->getLegajo()))
        return false;
    estudiantes.push_back(estudiante);
    return true;
}

bool Curso::desinscribirEstudiante(int legajo) {
    auto it = std::remove_if(estudiantes.begin(), estudiantes.end(),
        [legajo](Estudiante* e) { return e->getLegajo() == legajo; });
    if (it != estudiantes.end()) {
        delete *it; // Liberar memoria del estudiante
        estudiantes.erase(it, estudiantes.end());
        return true;
    }
    return false;
}

bool Curso::estaInscrito(int legajo) const {
    return std::any_of(estudiantes.begin(), estudiantes.end(),
        [legajo](Estudiante* e) { return e->getLegajo() == legajo; });
}   

bool Curso::estaCompleto() const {
    return estudiantes.size() >= maxEstudiantes;
}

void Curso::imprimirEstudiantes() const {
    std::vector<Estudiante*> copia = estudiantes;
    std::sort(copia.begin(), copia.end(), [](Estudiante* a, Estudiante* b) {
        return *a < *b;
    });

    for (auto* e : copia) {
        std::cout << *e << std::endl;
    }
}

std::ostream& operator<<(std::ostream& os, const Curso& curso) {
    os << "Curso con " << curso.estudiantes.size() << " estudiantes:";
    for (auto* e : curso.estudiantes) {
        os << "\n" << *e;
    }
    return os;
}

