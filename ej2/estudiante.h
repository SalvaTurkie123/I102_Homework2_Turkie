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

    void asignarNota(const std::string& curso, float nota);
    void mostrarNotas() const;
    void eliminarNota(const std::string& curso);
    
    std::string getNombre() const;
    int getLegajo() const;
    float getPromedio() const;

    // Sobrecarga de operadores 
    bool operator<(const Estudiante& otro) const; // Para ordenar por nombre
    friend std::ostream& operator<<(std::ostream& os, const Estudiante& e); // Para imprimir información del estudiante.
    
};

#endif