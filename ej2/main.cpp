#include <iostream>
#include <limits>
#include "curso.h"
#include "estudiante.h"

void mostrarMenu() {
    std::cout << "\n==== SISTEMA DE GESTIÓN DE CURSOS ====\n";
    std::cout << "1. Agregar curso\n";
    std::cout << "2. Inscribir estudiante en curso\n";
    std::cout << "3. Desinscribir estudiante de curso\n";
    std::cout << "4. Mostrar estudiantes de un curso\n";
    std::cout << "5. Copiar curso\n";
    std::cout << "6. Asignar nota a un estudiante en un curso\n";
    std::cout << "7. Ver notas de un estudiante\n";
    std::cout << "8. Salir\n";
    std::cout << "======================================\n";
    std::cout << "Seleccione una opción: ";
}

// Función auxiliar para seleccionar un curso
Curso* seleccionarCurso(std::vector<Curso>& cursos) {
    if (cursos.empty()) {
        std::cout << "No hay cursos disponibles.\n";
        return nullptr;
    }

    std::cout << "Seleccione un curso:\n";
    for (size_t i = 0; i < cursos.size(); ++i) {
        std::cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
    }
    std::cout << "Opción: ";
    int indexCurso;
    std::cin >> indexCurso;

    if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
        std::cout << "Opción inválida.\n";
        return nullptr;
    }

    return &cursos[indexCurso - 1];
}


// Función auxiliar para buscar o crear un estudiante
Estudiante* obtenerEstudiante(std::vector<Estudiante*>& estudiantes) {
    std::string nombreEst;
    int legajo;

    std::cout << "Ingrese el nombre del estudiante: ";
    std::cin.ignore();
    std::getline(std::cin, nombreEst);

    std::cout << "Ingrese el legajo del estudiante: ";
    std::cin >> legajo;

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
    std::vector<Curso> cursos;
    std::vector<Estudiante*> estudiantes;

    int opcion;
    do {
        mostrarMenu();
        std::cin >> opcion;

        // Validación de entrada
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada inválida. Intente de nuevo.\n";
            continue;
        }

        switch (opcion) {
            case 1: { // Agregar curso
                std::string nombreCurso;
                std::cout << "Ingrese el nombre del curso: ";
                std::cin.ignore();
                std::getline(std::cin, nombreCurso);
                cursos.emplace_back(nombreCurso);
                std::cout << "Curso \"" << nombreCurso << "\" agregado correctamente.\n";
                break;
            }

            // Código del case 2 optimizado
            case 2: { // Inscribir estudiante
                Curso* curso = seleccionarCurso(cursos);
                if (!curso) break;

                Estudiante* estudiante = obtenerEstudiante(estudiantes);
                curso->inscribirEstudiante(estudiante);
                   
                if (!curso->estaCompleto()) std::cout << "Estudiante " << estudiante->getNombre() << " inscripto en " << curso->getNombre() << ".\n";
                break;
            }

            case 3: { // Desinscribir estudiante
                if (cursos.empty()) {
                    std::cout << "No hay cursos disponibles.\n";
                    break;
                }

                int legajo, indexCurso;
                std::cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    std::cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                std::cout << "Opción: ";
                std::cin >> indexCurso;
                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    std::cout << "Opción inválida.\n";
                    break;
                }
                std::cout << "Ingrese el legajo del estudiante a desinscribir: ";
                std::cin >> legajo;
                cursos[indexCurso - 1].desinscribirEstudiante(legajo);
                break;


            }

            case 4: { // Mostrar estudiantes del curso
                if (cursos.empty()) {
                    std::cout << "No hay cursos disponibles.\n";
                    break;
                }

                int indexCurso;
                std::cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    std::cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                std::cout << "Opción: ";
                std::cin >> indexCurso;

                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    std::cout << "Opción inválida.\n";
                    break;
                }

                std::cout << "Lista de estudiantes en " << cursos[indexCurso - 1].getNombre() << ":\n";
                cursos[indexCurso - 1].imprimirEstudiantes();
                break;
            }

            case 5: { // Copiar curso con nuevo nombre
                if (cursos.empty()) {
                    std::cout << "No hay cursos disponibles para copiar.\n";
                    break;
                }
            
                int indexCurso;
                std::cout << "Seleccione un curso para copiar:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    std::cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                std::cout << "Opción: ";
                std::cin >> indexCurso;
            
                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    std::cout << "Opción inválida.\n";
                    break;
                }
            
                std::cin.ignore();  // Limpiar buffer antes de getline
                std::cout << "Ingrese el nuevo nombre del curso (o deje en blanco para mantener el original): ";
                std::string nuevoNombre;
                std::getline(std::cin, nuevoNombre);
            
                Curso nuevoCurso = Curso(cursos[indexCurso - 1], nuevoNombre);
                cursos.push_back(nuevoCurso);
            
                std::cout << "Curso copiado con éxito como \"" << (nuevoNombre.empty() ? cursos[indexCurso - 1].getNombre() : nuevoNombre) << "\".\n";
                break;
            }
            case 6: { // Asignar nota
                if (cursos.empty()) {
                    std::cout << "No hay cursos disponibles.\n";
                    break;
                }
            
                int indexCurso;
                std::cout << "Seleccione un curso:\n";
                for (size_t i = 0; i < cursos.size(); ++i) {
                    std::cout << i + 1 << ". " << cursos[i].getNombre() << "\n";
                }
                std::cout << "Opción: ";
                std::cin >> indexCurso;
            
                if (indexCurso < 1 || indexCurso > static_cast<int>(cursos.size())) {
                    std::cout << "Opción inválida.\n";
                    break;
                }
            
                int legajo;
                float nota;
                std::cout << "Ingrese el legajo del estudiante: ";
                std::cin >> legajo;
                std::cout << "Ingrese la nota: ";
                std::cin >> nota;
            
                cursos[indexCurso - 1].asignarNotaAEstudiante(legajo, nota);
                break;
            }
            case 7: { // Ver notas
                if (estudiantes.empty()) {
                    std::cout << "No hay estudiantes registrados.\n";
                    break;
                }
            
                int legajo;
                std::cout << "Ingrese el legajo del estudiante: ";
                std::cin >> legajo;
            
                bool encontrado = false;
                for (auto* estudiante : estudiantes) {
                    if (estudiante->getLegajo() == legajo) {
                        estudiante->mostrarNotas();
                        encontrado = true;
                        break;
                    }
                }
            
                if (!encontrado) {
                    std::cout << "No se encontró un estudiante con legajo " << legajo << ".\n";
                }
                break;
            }
        
            case 8:
                std::cout << "Saliendo del sistema...\n";
                break;

            default:
                std::cout << "Opción no válida. Intente nuevamente.\n";
                break;
        }

    } while (opcion != 8);

    // Liberar memoria de los estudiantes
    for (auto* est : estudiantes) {
        delete est;
    }

    return 0;
}