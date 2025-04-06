#include "curso.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <memory> 
using namespace std;

vector<Curso*> Curso::cursosDisponibles;

Curso::Curso(const string& nombre) : nombre(nombre) {}

Curso::~Curso() {}

// Constructor de copia
/*
Cuando se copia un objeto de la clase Curso, el constructor de copia realiza una copia superficial (shallow copy). Esto significa que:

El nombre del curso Se copia directamente como un nuevo std::string, lo que implica que el nuevo curso tiene su propio nombre independiente.
El vector de estudiantes (estudiantes): Se copia el vector de std::shared_ptr<Estudiante>. Esto no crea duplicados de los objetos Estudiante, sino que incrementa el contador de referencias de los shared_ptr que apuntan a los mismos objetos Estudiante.
Como resultado, tanto el curso original como el curso copiado comparten los mismos objetos Estudiante. 

El uso de std::shared_ptr en el vector estudiantes implica que los objetos Estudiante son compartidos entre los cursos. Esto es útil en escenarios donde varios cursos necesitan acceder a los mismos estudiantes sin duplicar los datos.

*/

Curso::Curso(const Curso& otro, const string& nuevoNombre)
    : nombre(nuevoNombre.empty() ? otro.nombre : nuevoNombre), estudiantes(otro.estudiantes) {}

Curso& Curso::operator=(const Curso& otro) {
    if (this != &otro) {
        nombre = otro.nombre;
        estudiantes = otro.estudiantes;
    }
    return *this;
}

void Curso::inscribirEstudiante(shared_ptr<Estudiante> estudiante) {
    if (estaInscripto(estudiante->getLegajo())) {
        cout << "El estudiante ya está inscripto en el curso.\n";
        return;
    }

    if (estaCompleto()) {
        cout << "El curso está completo. No se puede inscribir más estudiantes.\n";
        return;
    }

    estudiantes.push_back(estudiante);
    cout << "Estudiante inscrito en el curso " << nombre << ".\n";
}

void Curso::asignarNotaAEstudiante(int legajo, float nota) {
    for (const auto& estudiante : estudiantes) {
        if (estudiante->getLegajo() == legajo) {
            estudiante->asignarNota(nombre, nota);
            cout << "Nota " << nota << " asignada a " << estudiante->getNombre() << " en el curso " << nombre << ".\n";
            return;
        }
    }
    cout << "Estudiante con legajo " << legajo << " no encontrado en el curso " << nombre << ".\n";
}

void Curso::desinscribirEstudiante(int legajo) {
    auto it = remove_if(estudiantes.begin(), estudiantes.end(),
        [legajo, this](const shared_ptr<Estudiante>& est) {
            if (est->getLegajo() == legajo) {
                est->eliminarNota(nombre);
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
    return estudiantes.size() >= maxEstudiantes;
}

void Curso::imprimirEstudiantes() const {
    // Crear una copia del vector de estudiantes para ordenarlo
    vector<shared_ptr<Estudiante>> estudiantesOrdenados = estudiantes;

    // Ordenar los estudiantes por nombre
    sort(estudiantesOrdenados.begin(), estudiantesOrdenados.end(),
         [](const shared_ptr<Estudiante>& a, const shared_ptr<Estudiante>& b) {
             return *a < *b; // Usa la sobrecarga del operador "<" de Estudiante
         });

    // Imprimir los estudiantes ordenados
    for (const auto& estudiante : estudiantesOrdenados) {
        cout << *estudiante << "\n";
    }
}

string Curso::getNombre() const {
    return nombre;
}

ostream& operator<<(ostream& os, const Curso& curso) {
    os << "Curso: " << curso.nombre << "\nEstudiantes:\n";
    for (const auto& estudiante : curso.estudiantes) {
        os << *estudiante << "\n";
    }
    return os;
}