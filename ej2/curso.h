#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <vector>
#include <algorithm>
#include <iostream>

class Curso {

private:
    
    std::vector<Estudiante*> estudiantes;
    const int maxEstudiantes = 20;

public:

    Curso();
    Curso(const Curso& otro); // Constructor de copia
    ~Curso();

    // i.
    bool inscribirEstudiante(Estudiante* estudiante);
    bool desinscribirEstudiante(int legajo);

    bool estaInscrito(int legajo) const; // ii.

    bool estaCompleto() const; // iii.

    void imprimirEstudiantes() const; // iv.
    
    friend std::ostream& operator<<(std::ostream& os, const Curso& curso);

};

#endif