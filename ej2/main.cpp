#include <iostream>
#include <limits>
#include "curso.h"
#include "estudiante.h"

using namespace std;

void mostrarMenu() {
    cout << "\n==== SISTEMA DE GESTIÓN DE CURSOS ====\n";
    cout << "1. Agregar curso\n";
    cout << "2. Inscribir estudiante en curso\n";
    cout << "3. Desinscribir estudiante de curso\n";
    cout << "4. Mostrar estudiantes de un curso\n";
    cout << "5. Copiar curso\n";
    cout << "6. Asignar nota a un estudiante en un curso\n";
    cout << "7. Ver notas de un estudiante\n";
    cout << "8. Salir\n";
    cout << "======================================\n";
    cout << "Seleccione una opción: ";
}

// Función auxiliar para seleccionar un curso
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

// Función auxiliar para buscar o crear un estudiante
Estudiante* obtenerEstudiante(vector<Estudiante*>& estudiantes) {
    string nombreEst;
    int legajo;

    cout << "Ingrese el nombre del estudiante: ";
    cin.ignore();
    getline(cin, nombreEst);

    cout << "Ingrese el legajo del estudiante: ";
    cin >> legajo;

    // Buscar si el estudiante ya existe
    for (auto* est : estudiantes) {
        if (est->getLegajo() == legajo) {
            return est;
        }
    }

    // Si no existe, lo creamos
    auto* nuevoEstudiante = new Estudiante(nombreEst, legajo);
    estudiantes.push_back(nuevoEstudiante);
    return nuevoEstudiante;
}

int main() {
    vector<Curso> cursos;
    vector<Estudiante*> estudiantes;

    int opcion;
    do {
        mostrarMenu();
        cin >> opcion;

        // Validación de entrada
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: { // Agregar curso
                string nombreCurso;
                cout << "Ingrese el nombre del curso: ";
                cin.ignore();
                getline(cin, nombreCurso);
                cursos.emplace_back(nombreCurso);
                cout << "Curso \"" << nombreCurso << "\" agregado correctamente.\n";
                break;
            }

            case 2: { // Inscribir estudiante
                Curso* curso = seleccionarCurso(cursos);
                if (!curso) break;

                Estudiante* estudiante = obtenerEstudiante(estudiantes);
                curso->inscribirEstudiante(estudiante);

                if (!curso->estaCompleto()) cout << "Estudiante " << estudiante->getNombre() << " inscripto en " << curso->getNombre() << ".\n";
                break;
            }

            case 3: { // Desinscribir estudiante
                if (cursos.empty()) {
                    cout << "No hay cursos disponibles.\n";
                    break;
                }

                int legajo, indexCurso;
                cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                cout << "Opción: ";
                cin >> indexCurso;
                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    cout << "Opción inválida.\n";
                    break;
                }
                cout << "Ingrese el legajo del estudiante a desinscribir: ";
                cin >> legajo;
                cursos[indexCurso - 1].desinscribirEstudiante(legajo);
                break;
            }

            case 4: { // Mostrar estudiantes del curso
                if (cursos.empty()) {
                    cout << "No hay cursos disponibles.\n";
                    break;
                }

                int indexCurso;
                cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                cout << "Opción: ";
                cin >> indexCurso;

                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    cout << "Opción inválida.\n";
                    break;
                }

                cout << "Lista de estudiantes en " << cursos[indexCurso - 1].getNombre() << ":\n";
                cursos[indexCurso - 1].imprimirEstudiantes();
                break;
            }

            case 5: { // Copiar curso con nuevo nombre
                if (cursos.empty()) {
                    cout << "No hay cursos disponibles para copiar.\n";
                    break;
                }

                int indexCurso;
                cout << "Seleccione un curso para copiar:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                cout << "Opción: ";
                cin >> indexCurso;

                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    cout << "Opción inválida.\n";
                    break;
                }

                cin.ignore();  // Limpiar buffer antes de getline
                cout << "Ingrese el nuevo nombre del curso (o deje en blanco para mantener el original): ";
                string nuevoNombre;
                getline(cin, nuevoNombre);

                Curso nuevoCurso = Curso(cursos[indexCurso - 1], nuevoNombre);
                cursos.push_back(nuevoCurso);

                cout << "Curso copiado con éxito como \"" << (nuevoNombre.empty() ? cursos[indexCurso - 1].getNombre() : nuevoNombre) << "\".\n";
                break;
            }

            case 6: { // Asignar nota
                if (cursos.empty()) {
                    cout << "No hay cursos disponibles.\n";
                    break;
                }

                int indexCurso;
                cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                cout << "Opción: ";
                cin >> indexCurso;

                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    cout << "Opción inválida.\n";
                    break;
                }

                int legajo;
                float nota;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;
                cout << "Ingrese la nota: ";
                cin >> nota;

                cursos[indexCurso - 1].asignarNotaAEstudiante(legajo, nota);
                break;
            }

            case 7: { // Ver notas
                if (estudiantes.empty()) {
                    cout << "No hay estudiantes registrados.\n";
                    break;
                }

                int legajo;
                cout << "Ingrese el legajo del estudiante: ";
                cin >> legajo;

                bool encontrado = false;
                for (auto* estudiante : estudiantes) {
                    if (estudiante->getLegajo() == legajo) {
                        estudiante->mostrarNotas();
                        encontrado = true;
                        break;
                    }
                }

                if (!encontrado) {
                    cout << "No se encontró un estudiante con legajo " << legajo << ".\n";
                }
                break;
            }

            case 8:
                cout << "Saliendo del sistema...\n";
                break;

            default:
                cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 8);

    // Liberar memoria de los estudiantes
    for (auto* est : estudiantes) {
        delete est;
    }

    return 0;
}
