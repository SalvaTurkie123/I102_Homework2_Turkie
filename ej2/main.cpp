#include "curso.h"

int main() {

    Curso curso;
    int opcion, legajo;
    std::string nombre, cursoNombre;
    float nota;

    while (true) {

        std::cout << "\nMenú de Curso:\n"
                  << "1. Inscribir estudiante\n"
                  << "2. Desinscribir estudiante\n"
                  << "3. Ver si un estudiante está inscrito\n"
                  << "4. Ver si el curso está completo\n"
                  << "5. Mostrar estudiantes\n"
                  << "6. Agregar nota a un estudiante\n"
                  << "0. Salir\n"
                  << "Ingrese una opción: ";

        std::cin >> opcion;
        std::cin.ignore(); 

        switch (opcion) {

            case 1:
                std::cout << "Ingrese nombre del estudiante: ";
                std::getline(std::cin, nombre);
                std::cout << "Ingrese legajo: ";
                std::cin >> legajo;
                if (curso.inscribirEstudiante(new Estudiante(nombre, legajo))) {
                    std::cout << "Estudiante inscrito correctamente.\n";
                } else {
                    std::cout << "No se pudo inscribir (curso lleno o estudiante ya inscrito).\n";
                }
                break;

            case 2:
                std::cout << "Ingrese legajo del estudiante a desinscribir: ";
                std::cin >> legajo;
                if (curso.desinscribirEstudiante(legajo)) {
                    std::cout << "Estudiante desinscrito.\n";
                } else {
                    std::cout << "No se encontró el estudiante.\n";
                }
                break;

            case 3:
                std::cout << "Ingrese legajo: ";
                std::cin >> legajo;
                std::cout << (curso.estaInscrito(legajo) ? "Inscrito" : "No inscrito") << std::endl;
                break;

            case 4:
                std::cout << (curso.estaCompleto() ? "Curso completo" : "Cupos disponibles") << std::endl;
                break;
            
            case 5:
                curso.imprimirEstudiantes();
                break;
            
            case 6:
                std::cout << "Ingrese legajo del estudiante: ";
                std::cin >> legajo;
                std::cin.ignore();
                std::cout << "Ingrese nombre del curso: ";
                std::getline(std::cin, cursoNombre);
                std::cout << "Ingrese nota: ";
                std::cin >> nota;
                break;

            case 0:
                std::cout << "Saliendo...\n";
                return 0;

            default:
                std::cout << "Opción no válida.\n";

        }
    }
}