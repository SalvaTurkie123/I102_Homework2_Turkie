#include "entero.h"
#include "real.h"
#include "complejo.h"
#include <iostream>

using namespace std;

void probarNumeros() {
     
    // Crear objetos de las clases Entero, Real y Complejo
    Entero e1(5), e2(-3);
    Real r1(4.5), r2(0.0);
    Complejo c1(2, 3), c2(1, -4);

    // Operaciones entre números del mismo tipo
    cout << "=== Operaciones entre números del mismo tipo ===" << endl;
    
    cout << "Entero: " << e1.toString() << " + " << e2.toString() 
         << " = " << e1.suma(e2)->toString() << endl;

    cout << "Real: " << r1.toString() << " - " << r2.toString() 
         << " = " << r1.resta(r2)->toString() << endl;

    cout << "Complejo: " << c1.toString() << " * " << c2.toString() 
         << " = " << c1.multiplicacion(c2)->toString() << endl;
}

int main() {
    probarNumeros();
    return 0;
}