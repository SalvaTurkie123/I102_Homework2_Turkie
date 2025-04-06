#include "cajadeahorro.h"
#include "cuentacorriente.h"

using namespace std;

int main() {
    // Crear una caja de ahorro con $500
    CajaDeAhorro caja("Salvador Turkie", 500);

    // Crear una cuenta corriente con $300, vinculada a la caja de ahorro
    CuentaCorriente cuenta("Salvador Turkie", 300, caja);

    // Mostrar información inicial
    cout << "=== Información inicial ===" << endl;
    cuenta.mostrarInfo();
    caja.mostrarInfo();

    // Intentar retirar dinero de la cuenta corriente
    cout << "\n=== Retirar $200 de la cuenta corriente ===" << endl;
    cuenta.retirar(200);
    cuenta.mostrarInfo();

    // Intentar retirar más dinero del que hay en la cuenta corriente
    cout << "\n=== Retirar $200 más de la cuenta corriente (usando caja de ahorro) ===" << endl;
    cuenta.retirar(200);
    cuenta.mostrarInfo();
    caja.mostrarInfo();

    // Intentar retirar más dinero del que hay en ambas cuentas
    cout << "\n=== Intentar retirar $1000 (más de lo disponible en ambas cuentas) ===" << endl;
    cuenta.retirar(1000);
    cuenta.mostrarInfo();
    caja.mostrarInfo();

    // Mostrar información más de 2 veces para aplicar el descuento de $20
    cout << "\n=== Mostrar información de la caja de ahorro 3 veces ===" << endl;
    caja.mostrarInfo();
    caja.mostrarInfo();
    caja.mostrarInfo();

    // Depositar dinero en ambas cuentas
    cout << "\n=== Depositar $300 en la cuenta corriente y $500 en la caja de ahorro ===" << endl;
    cuenta.depositar(300);
    caja.depositar(500);
    cuenta.mostrarInfo();
    caja.mostrarInfo();

    return 0;
}