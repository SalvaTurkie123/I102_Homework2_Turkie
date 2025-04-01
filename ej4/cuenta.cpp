#include "cuenta.h"

Cuenta::Cuenta(const std::string& titular, double saldoInicial) : titularCuenta(titular), balance(saldoInicial) {}

Cuenta::~Cuenta() {}

void Cuenta::depositar(double cantidad) {
    
    if (cantidad >= 0) {
        balance += cantidad;
        std::cout << "Se depositaron $" << cantidad << " en la cuenta de " << titularCuenta << "." << std::endl;
    }

    else {
        std::cout << "No se puede depositar una cantidad negativa." << std::endl;
    }

}

double Cuenta::getBalance() const {
    return balance;
}

void Cuenta::setBalance(double nuevoBalance) {
    balance = nuevoBalance;
}