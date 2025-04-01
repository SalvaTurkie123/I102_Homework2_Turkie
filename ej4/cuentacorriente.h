#ifndef CUENTACORRIENTE_H
#define CUENTACORRIENTE_H

#include "cuenta.h"
#include "cajadeahorro.h"

class CuentaCorriente : public Cuenta {

    private:

        CajaDeAhorro& cajaDeAhorro;

    public:

        CuentaCorriente(const std::string& titular, double saldoInicial, CajaDeAhorro& caja);
        void retirar(double cantidad) override;
        void mostrarInfo() override;

        friend class CajaDeAhorro;
};

#endif