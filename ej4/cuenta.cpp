#include "cuenta.h"

Cuenta::Cuenta(const std::string& titular, double saldoInicial) : titularCuenta(titular), balance(saldoInicial) {}

void Cuenta::depositar(double cantidad) {

        balance += cantidad;
        std::cout << "Se depositaron " << cantidad << " en la cuenta de " << titularCuenta << ". El nuevo balance es " << balance << "." << std::endl;

}

double Cuenta::getBalance() const {
    return balance;
}

void Cuenta::setBalance(double nuevoBalance) {
    balance = nuevoBalance;
}