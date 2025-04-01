#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Curso {

private:

    std::string nombre;
    std::vector<Estudiante*> estudiantes;
    unsigned int maxEstudiantes = 4;
    static std::vector<Curso*> cursosDisponibles; 

public:



    Curso(const std::string& nombre);
    ~Curso();

    // Constructor de copia (shallow copy)
    Curso(const Curso& otro,  const std::string& nuevoNombre = "");

    // Operador de asignación (shallow copy)
    Curso& operator=(const Curso& otro);

    void inscribirEstudiante(Estudiante* estudiante);
    void asignarNotaAEstudiante(int legajo, float nota);
    void desinscribirEstudiante(int legajo);
    bool estaInscripto(int legajo) const;
    bool estaCompleto() const;
    void imprimirEstudiantes() const;
    

    std::string getNombre() const { return nombre; }

    friend std::ostream& operator<<(std::ostream& os, const Curso& curso);

};

#endif