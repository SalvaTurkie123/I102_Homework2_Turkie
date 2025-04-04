#include "cuenta.h"
using namespace std;

Cuenta::Cuenta(const string& titular, double saldoInicial) : titularCuenta(titular), balance(saldoInicial) {}

Cuenta::~Cuenta() {}

void Cuenta::depositar(double cantidad) {
    
    if (cantidad >= 0) {
        balance += cantidad;
        cout << "Se depositaron $" << cantidad << " en la cuenta de " << titularCuenta << "." << endl;
    }

    else {
        cout << "No se puede depositar una cantidad negativa." << endl;
    }

}

double Cuenta::getBalance() const {
    return balance;
}

void Cuenta::setBalance(double nuevoBalance) {
    balance = nuevoBalance;
}