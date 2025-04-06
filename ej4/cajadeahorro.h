#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include "cuenta.h"

class CajaDeAhorro : public Cuenta {

    /*
    contadorMostrar: private porque es un detalle interno de la clase y no debe ser accesible desde fuera.
    Métodos públicos: Los métodos como retirar y mostrarInfo son public porque deben ser accesibles desde cualquier parte del programa.
    */

    private:

        mutable int contadorMostrar;
        

    public:
    
        CajaDeAhorro(const std::string& titular, double saldoInicial);
        void retirar(double cantidad) override;
        void mostrarInfo() override;

};

#endif 