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

    void displayTime() {
        cout << setw(2) << setfill('0') << hour << "h, "
             << setw(2) << setfill('0') << minute << "m, "
             << setw(2) << setfill('0') << second << "s "
             << (isPM ? "p.m." : "a.m.") << endl;
    }

    // Para modificar los valores y validar
    void setHour(int h) { 
        if (h >= 0 && h <= 12) hour = h;
        else cout << "Hora inválida." << endl;
    }
    void setMinute(int m) { 
        if (m >= 0 && m < 60) minute = m;
        else cout << "Minuto inválido." << endl;
    }
    void setSecond(int s) { 
        if (s >= 0 && s < 60) second = s;
        else cout << "Segundo inválido." << endl;
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