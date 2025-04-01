#ifndef CAJADEAHORRO_H
#define CAJADEAHORRO_H

#include "cuenta.h"

class CajaDeAhorro : public Cuenta {


    private:

        mutable int contadorMostrar;
        

    public:
    
        CajaDeAhorro(const std::string& titular, double saldoInicial);
        void retirar(double cantidad) override;
        void mostrarInfo() override;

};

#endif 