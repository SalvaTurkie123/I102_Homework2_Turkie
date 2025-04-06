#ifndef CUENTA_H
#define CUENTA_H

#include <iostream>
#include <string>

class Cuenta {

    /*
    balance: private para evitar accesos no controlados y garantizar que solo se modifique mediante métodos específicos.
    titularCuenta: protected para que las clases derivadas puedan acceder al titular sin exponerlo directamente.
    Métodos públicos: Los métodos como depositar, retirar, y mostrarInfo son public porque deben ser accesibles desde cualquier parte del programa.
    */

    private:

        double balance; 

    protected:

        std::string titularCuenta; 

    public:

        Cuenta(const std::string& titular, double saldoInicial);
        virtual ~Cuenta();

        void depositar(double cantidad);
        virtual void retirar(double cantidad) = 0;
        virtual void mostrarInfo() = 0;

        double getBalance() const;
        void setBalance(double nuevoBalance);

};

#endif