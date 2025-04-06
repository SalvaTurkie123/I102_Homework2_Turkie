#ifndef CURSO_H
#define CURSO_H

#include "estudiante.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <memory>

using namespace std;

class Curso {

private:
    string nombre;
    vector<shared_ptr<Estudiante>> estudiantes;
    unsigned int maxEstudiantes = 20;
    static vector<Curso*> cursosDisponibles;

public:


    Curso(const string& nombre);
    ~Curso();

    // Constructor de copia
    Curso(const Curso& otro, const string& nuevoNombre = "");
    Curso& operator=(const Curso& otro);

    void inscribirEstudiante(shared_ptr<Estudiante> estudiante);
    void desinscribirEstudiante(int legajo);
    bool estaInscripto(int legajo) const;
    bool estaCompleto() const;
    void imprimirEstudiantes() const;

    void asignarNotaAEstudiante(int legajo, float nota);
    
    // Métodos para acceder a los miembros privados
    string getNombre() const; 
    const vector<shared_ptr<Estudiante>>& getEstudiantes() const;

    friend ostream& operator<<(ostream& os, const Curso& curso); // Para imprimir información del curso
};

#endif