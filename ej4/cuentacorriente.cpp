#include "cuentacorriente.h"

CuentaCorriente::CuentaCorriente(const std::string& titular, double saldoInicial, CajaDeAhorro& caja)
    : Cuenta(titular, saldoInicial), cajaDeAhorro(caja) {}

void CuentaCorriente::retirar(double cantidad) {
        std::cout << "Intentando retirar $" << cantidad << " de la cuenta corriente de " << titularCuenta << std::endl;
    
        if (cantidad <= getBalance()) {
            setBalance(getBalance() - cantidad);
            std::cout << "Se retiraron $" << cantidad << " de la cuenta de " << titularCuenta << ". Nuevo balance: $" << getBalance() << std::endl;
            std::cout << "(No se usó la caja de ahorro para completar el retiro.)" << std::endl;
        } 
        else if (cantidad <= getBalance() + cajaDeAhorro.getBalance()) {
            double diferencia = cantidad - getBalance();
            
            std::cout << "El saldo en la cuenta corriente es insuficiente. Faltan $" << diferencia << ". Se intentará usar la caja de ahorro." << std::endl;
    
            setBalance(0);  // Se vacía la cuenta corriente
            if (diferencia > cajaDeAhorro.getBalance()) {
                std::cout << "Error inesperado: tratando de retirar más de lo disponible en caja de ahorro." << std::endl;
                return;
            }
    
            std::cout << "Se retiraron $" << diferencia << " de la caja de ahorro de " << titularCuenta << std::endl;
            cajaDeAhorro.setBalance(cajaDeAhorro.getBalance() - diferencia);  // Se retira solo lo necesario
    
            std::cout << "(Se usó la caja de ahorro para completar el retiro.)" << std::endl;
            std::cout << "Nuevo balance de caja de ahorro: $" << cajaDeAhorro.getBalance() << std::endl;
        } 
        else {
            std::cout << "No se puede retirar $" << cantidad << " de la cuenta de " << titularCuenta << ". Saldo insuficiente." << std::endl;
        }
}

void CuentaCorriente::mostrarInfo() {

    std::cout << "Titular: " << titularCuenta << ", Balance Cuenta Corriente: $" << getBalance() << std::endl;
    
}  


