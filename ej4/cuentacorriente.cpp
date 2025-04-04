#include "cuentacorriente.h"
using namespace std;

CuentaCorriente::CuentaCorriente(const string& titular, double saldoInicial, CajaDeAhorro& caja)
    : Cuenta(titular, saldoInicial), cajaDeAhorro(caja) {}

void CuentaCorriente::retirar(double cantidad) {
        cout << "Intentando retirar $" << cantidad << " de la cuenta corriente de " << titularCuenta << endl;
    
        if (cantidad <= getBalance()) {
            setBalance(getBalance() - cantidad);
            cout << "Se retiraron $" << cantidad << " de la cuenta de " << titularCuenta << ". Nuevo balance: $" << getBalance() << endl;
            cout << "(No se usó la caja de ahorro para completar el retiro.)" << endl;
        } 
        else if (cantidad <= getBalance() + cajaDeAhorro.getBalance()) {
            double diferencia = cantidad - getBalance();
            
            cout << "El saldo en la cuenta corriente es insuficiente. Faltan $" << diferencia << ". Se intentará usar la caja de ahorro." << endl;
    
            setBalance(0);  // Se vacía la cuenta corriente
            if (diferencia > cajaDeAhorro.getBalance()) {
                cout << "Error inesperado: tratando de retirar más de lo disponible en caja de ahorro." << endl;
                return;
            }
    
            cout << "Se retiraron $" << diferencia << " de la caja de ahorro de " << titularCuenta << endl;
            cajaDeAhorro.setBalance(cajaDeAhorro.getBalance() - diferencia);  // Se retira solo lo necesario
    
            cout << "(Se usó la caja de ahorro para completar el retiro.)" << endl;
            cout << "Nuevo balance de caja de ahorro: $" << cajaDeAhorro.getBalance() << endl;
        } 
        else {
            cout << "No se puede retirar $" << cantidad << " de la cuenta de " << titularCuenta << ". Saldo insuficiente." << endl;
        }
}

void CuentaCorriente::mostrarInfo() {

    cout << "Titular: " << titularCuenta << ", Balance Cuenta Corriente: $" << getBalance() << endl;
    
}
