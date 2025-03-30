#ifndef NUMERO_H
#define NUMERO_H

#include <string>

class Numero {
    
    public:
        virtual ~Numero() = default; // Destructor virtual para herencia
    
        // Métodos virtuales puros → Deben ser implementados en las clases derivadas
        virtual Numero* suma(const Numero& otro) const = 0;
        virtual Numero* resta(const Numero& otro) const = 0;
        virtual Numero* multiplicacion(const Numero& otro) const = 0;
        virtual std::string toString() const = 0;
};

#endif