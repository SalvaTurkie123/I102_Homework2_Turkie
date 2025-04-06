#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "cuenta.h"
#include "cajadeahorro.h"

class CuentaCorriente : public Cuenta {

    /*
    cajaDeAhorro: private porque es un detalle interno de la clase y no debe ser accesible desde fuera.
    Métodos públicos: Los métodos como retirar y mostrarInfo son public porque deben ser accesibles desde cualquier parte del programa.
    friend: Se utiliza para permitir que CajaDeAhorro acceda a los detalles internos de CuentaCorriente. -> (En caso de que la caja de ahorro tampoco tenga dinero, se imprimirá un aviso
    de que la cuenta no posee dinero. Utilizar friend para esto.)
    */

    private:

        CajaDeAhorro& cajaDeAhorro;

    public:

        CuentaCorriente(const std::string& titular, double saldoInicial, CajaDeAhorro& caja);
        void retirar(double cantidad) override;
        void mostrarInfo() override;

        friend class CajaDeAhorro;
};

#endif