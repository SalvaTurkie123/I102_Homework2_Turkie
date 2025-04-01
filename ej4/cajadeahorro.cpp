#include "cajadeahorro.h"

CajaDeAhorro::CajaDeAhorro(const std::string& titular, double saldoInicial) 
    : Cuenta(titular, saldoInicial), contadorMostrar(0) {}

void CajaDeAhorro::retirar(double cantidad) {

    if (cantidad > getBalance()) {
        std::cout << "No se puede retirar " << cantidad << " de la cuenta de " << titularCuenta << ". Saldo insuficiente." << std::endl;
    } else {
        setBalance(getBalance() - cantidad);
        std::cout << "Se retiraron $" << cantidad << " de la cuenta de " << titularCuenta << ". El nuevo balance es " << getBalance() << "." << std::endl;
    }
}

void CajaDeAhorro::mostrarInfo() {

    std::cout << "Titular: " << titularCuenta << ", Balance Caja De Ahorro: $" << getBalance() << std::endl;

    contadorMostrar++;
    if (contadorMostrar > 2) {
        std::cout << "Se realizó un descuento de $20 del balance luego de mostrar más de 2 veces la informacón de la cuenta. " << std::endl;
        setBalance(getBalance() - 20);
        std::cout << "Nuevo balance: $" << getBalance() << std::endl;
    }
}
