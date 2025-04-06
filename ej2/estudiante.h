#ifndef ESTUDIANTE_H
#define ESTUDIANTE_H

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Estudiante {

private:
    string nombre;
    int legajo;
    map<string, float> cursos; 

public:
    Estudiante(const string& nombre, int legajo);

    void asignarNota(const string& curso, float nota);
    void mostrarNotas() const;
    void eliminarNota(const string& curso);

    string getNombre() const;
    int getLegajo() const;
    float getPromedio() const;

    // Sobrecarga de operadores
    bool operator<(const Estudiante& otro) const; // Para ordenar por nombre
    friend ostream& operator<<(ostream& os, const Estudiante& e); // Para imprimir información del estudiante.
};

#endif