#include <iostream>
#include <iomanip>  // Para setw y setfill
#include <string>   // Para manejar a.m./p.m.

using namespace std;

class Time {

private:

    int hour, minute, second;
    bool isPM; // true si es PM, false si es AM


public: 

    // Constructores
    Time() : hour(0), minute(0), second(0), isPM(false) {} // Constructor por defecto
    Time(int h) { setHour(h); minute = second = 0; isPM = false; } // Constructor con hora
    Time(int h, int m) { setHour(h); setMinute(m); second = 0; isPM = false; } // Constructor con hora y minuto
    Time(int h, int m, int s) { setHour(h); setMinute(m); setSecond(s); isPM = false; } // Constructor con hora, minuto y segundo
    Time(int h, int m, int s, string am_pm) { setHour(h); setMinute(m); setSecond(s); setAMPM(am_pm); } // Constructor con hora, minuto, segundo y AM/PM

    // Formato 12 horas
    void displayTime() {
        cout << setw(2) << setfill('0') << hour << "h, "
             << setw(2) << setfill('0') << minute << "m, "
             << setw(2) << setfill('0') << second << "s "
             << (isPM ? "p.m." : "a.m.") << endl;
    }

    // Formato 24 horas
    void displayTime24h() {
        int hour24 = hour;

        if (isPM) {
            if (hour != 12) hour24 += 12;  // p.m. a formato 24h
        } else {
            if (hour == 12) hour24 = 0;  // 12 a.m. a 00
        }

        cout << setw(2) << setfill('0') << hour24 << ":"
             << setw(2) << setfill('0') << minute << ":"
             << setw(2) << setfill('0') << second << " (formato 24h)" << endl;
    }

    
    // Para modificar los valores y validar
    void setHour(int h) { 
        if (h >= 0 && h <= 12) hour = h;
        else cout << "Hora inválida, intente de nuevo (Tiene que estar entre 0 y 12)" << endl;
    }
    void setMinute(int m) { 
        if (m >= 0 && m < 60) minute = m;
        else cout << "Minuto inválido, intente de nuevo (Tiene que estar entre 0 y 59)" << endl;
    }
    void setSecond(int s) { 
        if (s >= 0 && s < 60) second = s;
        else cout << "Segundo inválido, intente de nuevo (Tiene que estar entre 0 y 59)" << endl;
    }
    void setAMPM(string am_pm) { 
        if (am_pm == "a.m." || am_pm == "p.m." || am_pm == "A.M." || am_pm == "P.M.") 
            isPM = (am_pm == "p.m." || am_pm == "P.M.");
        else cout << "Formato inválido (use 'a.m.' o 'p.m.')." << endl;
    }

    // Métodos para obtener los valores
    int getHour() const { return hour; }
    int getMinute() const { return minute; }
    int getSecond() const { return second; }
    string getAMPM() const { return (isPM ? "p.m." : "a.m."); }

};

// Menu de opciones
void showMenu() {
    cout << "\nMenú de configuración de hora:\n";
    cout << "1. Inicializar sin parámetros (0h, 0m, 0s a.m.)\n";
    cout << "2. Inicializar con solo la hora\n";
    cout << "3. Inicializar con hora y minutos\n";
    cout << "4. Inicializar con hora, minutos y segundos\n";
    cout << "5. Inicializar con hora, minutos, segundos y a.m./p.m.\n";
    cout << "6. Modificar hora\n";
    cout << "7. Modificar minutos\n";
    cout << "8. Modificar segundos\n";
    cout << "9. Modificar a.m./p.m.\n";
    cout << "10. Mostrar la hora completa en formato pedido\n";
    cout << "11. Mostrar valores individuales (hora, minutos, segundos, a.m./p.m.)\n";
    cout << "12. Mostrar la hora en formato 24h\n";
    cout << "0. Salir\n";
    cout << "Seleccione una opción: ";
}

int main() {

    Time reloj; // Inicializa el reloj con 0h, 0m, 0s a.m.
    int opcion, h, m, s;
    string am_pm;

    while (true) {

        showMenu();
        cin >> opcion;
        cin.ignore(); 

        switch (opcion) {
        
            case 1:
                reloj = Time();
                cout << "Reloj inicializado a 0h, 0m, 0s a.m." << endl;
                break;

            case 2:
                cout << "Ingrese la hora (0-12): ";
                cin >> h;
                reloj = Time(h);
                break;

            case 3:
                cout << "Ingrese la hora (0-12): ";
                cin >> h;  
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
                reloj = Time(h, m);
                break;

            case 4:
                cout << "Ingrese la hora (0-12): ";
                cin >> h;
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
                cout << "Ingrese los segundos (0-59): ";
                cin >> s;
                reloj = Time(h, m, s);
                break;

            case 5:
                cout << "Ingrese la hora (0-12): ";
                cin >> h;
                cout << "Ingrese los minutos (0-59): ";
                cin >> m;
                cout << "Ingrese los segundos (0-59): ";
                cin >> s;
                cout << "Ingrese a.m./p.m.: ";
                cin >> am_pm;
                reloj = Time(h, m, s, am_pm);
                break;

            case 6:
                cout << "Ingrese la nueva hora (0-12): ";
                cin >> h;
                reloj.setHour(h);
                break;

            case 7:
                cout << "Ingrese los nuevos minutos (0-59): ";
                cin >> m;
                reloj.setMinute(m);
                break;

            case 8:
                cout << "Ingrese los nuevos segundos (0-59): ";
                cin >> s;
                reloj.setSecond(s);
                break;

            case 9:
                cout << "Ingrese a.m./p.m.: ";
                cin >> am_pm;
                reloj.setAMPM(am_pm);
                break;

            case 10:
                cout << "Hora actual: ";
                reloj.displayTime();
                break;

            case 11:
                cout << "Hora: " << reloj.getHour() << endl;
                cout << "Minutos: " << reloj.getMinute() << endl;
                cout << "Segundos: " << reloj.getSecond() << endl;
                cout << "AM/PM: " << reloj.getAMPM() << endl;
                break;

            case 12:
                reloj.displayTime24h();
                break;

            case 0:
                cout << "Saliendo del programa." << endl;
                return 0;

            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
                break;
        }
    }
}