#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Curso {

private:

    string nombre;
    vector<Estudiante*> estudiantes;
    unsigned int maxEstudiantes = 20;
    static vector<Curso*> cursosDisponibles; 

public:

    Curso(const string& nombre);
    ~Curso();

    // Constructor de copia (shallow copy)
    Curso(const Curso& otro, const string& nuevoNombre = "");

    // Operador de asignación (shallow copy)
    Curso& operator=(const Curso& otro);

    void inscribirEstudiante(Estudiante* estudiante);
    void asignarNotaAEstudiante(int legajo, float nota);
    void desinscribirEstudiante(int legajo);
    bool estaInscripto(int legajo) const;
    bool estaCompleto() const;
    void imprimirEstudiantes() const;

    string getNombre() const { return nombre; }

    friend ostream& operator<<(ostream& os, const Curso& curso);

};

#endif
