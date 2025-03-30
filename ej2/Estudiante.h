#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <map>

class Estudiante {

private:

    std::string nombre;
    int legajo;
    std::map<std::string, float> cursos; // curso -> Nota


public:

    // Constructor con nombre y legajo del estudiante, lo inicializa
    Estudiante(const std::string& nombre, int legajo);

    // Agregar un curso con su nota
    void agregarCurso(const std::string& curso, float nota);
    
    // Nombre del estudiante
    std::string getNombre() const;

    // Legajo del estudiante
    int getLegajo() const;

    // Promedio de las notas
    float getPromedio() const;

    // Sobrecarga de operadores 
    bool operator<(const Estudiante& otro) const; // Para ordenar por nombre
    friend std::ostream& operator<<(std::ostream& os, const Estudiante& e); // Para imprimir información del estudiante.
    
};

#endif