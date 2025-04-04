#include "cajadeahorro.h"
using namespace std;

CajaDeAhorro::CajaDeAhorro(const string& titular, double saldoInicial) 
    : Cuenta(titular, saldoInicial), contadorMostrar(0) {}

void CajaDeAhorro::retirar(double cantidad) {

    if (cantidad > getBalance()) {
        cout << "No se puede retirar " << cantidad << " de la cuenta de " << titularCuenta << ". Saldo insuficiente." << endl;
    } else {
        setBalance(getBalance() - cantidad);
        cout << "Se retiraron $" << cantidad << " de la cuenta de " << titularCuenta << ". El nuevo balance es " << getBalance() << "." << endl;
    }
}

void CajaDeAhorro::mostrarInfo() {

    cout << "Titular: " << titularCuenta << ", Balance Caja De Ahorro: $" << getBalance() << endl;

    contadorMostrar++;
    if (contadorMostrar > 2) {
        cout << "Se realizó un descuento de $20 del balance luego de mostrar más de 2 veces la informacón de la cuenta. " << endl;
        setBalance(getBalance() - 20);
        cout << "Nuevo balance: $" << getBalance() << endl;
    }
}
