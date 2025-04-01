#include "cajadeahorro.h"
#include "cuentacorriente.h"

int main() {
    // Crear una caja de ahorro con $500
    CajaDeAhorro caja("Salvador Turkie", 500);

    // Crear una cuenta corriente con $200, vinculada a la caja de ahorro
    CuentaCorriente cuenta("Salvador Turkie", 300, caja);

    // Pruebas
    cuenta.mostrarInfo();
    caja.mostrarInfo();
    cuenta.retirar(300);
    cuenta.retirar(500);  

    // Depositar en la cuenta y en la caja de ahorro
    cuenta.depositar(200);
    caja.depositar(900);
    cuenta.mostrarInfo();
    caja.mostrarInfo();

    // Retirar de la cuenta corriente más de lo que tiene en la cuenta corriente

    cuenta.retirar(1000);  // Esto debería usar la caja de ahorro
    cuenta.mostrarInfo();
    
    caja.mostrarInfo(); // Se descuentan $20 por mostrar más de 2 veces la información
}