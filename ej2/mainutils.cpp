#include "curso.h"
#include "estudiante.h"
#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm> // Para std::all_of
#include <limits>   // Para std::numeric_limits

using namespace std;

Curso* seleccionarCurso(vector<Curso>& cursos) {
    if (cursos.empty()) {
        cout << "No hay cursos disponibles.\n";
        return nullptr;
    }

    cout << "Seleccione un curso:\n";
    for (size_t i = 0; i < cursos.size(); ++i) {
        cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
    }
    cout << "Opción: ";
    int indexCurso;
    cin >> indexCurso;

    if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
        cout << "Opción inválida.\n";
        return nullptr;
    }

    return &cursos[indexCurso - 1];
}

shared_ptr<Estudiante> obtenerEstudiante(vector<shared_ptr<Estudiante>>& estudiantes) {
    string nombreEst;
    int legajo;

    cout << "Ingrese el nombre del estudiante (solo letras): ";
    cin.ignore();
    getline(cin, nombreEst);

    // Validar el nombre del estudiante
    while (!std::all_of(nombreEst.begin(), nombreEst.end(), [](char c) { return isalpha(c) || isspace(c); })) {
        cout << "Nombre inválido. Solo se permiten letras y espacios. Intente de nuevo: ";
        getline(cin, nombreEst);
    }

   // Validar el legajo del estudiante
    while (true) {
        cout << "Ingrese el legajo del estudiante (número entero positivo): ";
        cin >> legajo;

        if (cin.fail() || legajo <= 0) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Legajo inválido. Debe ser un número entero positivo. Intente de nuevo.\n";
        } else {
            break; 
        }
    }

    for (const auto& est : estudiantes) {
        if (est->getLegajo() == legajo) {
            cout << "El estudiante ya existe.\n";
            return est;
        }
    }

    auto nuevoEstudiante = make_shared<Estudiante>(nombreEst, legajo);
    estudiantes.push_back(nuevoEstudiante);
    return nuevoEstudiante;
}