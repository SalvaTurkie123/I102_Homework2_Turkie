#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>

class Cuenta {

    private:

        double balance;

    protected:

        std::string titularCuenta;

    public:

        // Por defecto
        Cuenta(const std::string& titular, double saldoInicial);
        virtual ~Cuenta();

        void depositar(double cantidad);
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;

        double getBalance() const;
        void setBalance(double nuevoBalance);

};

#endif