#ifndef ENTERO_H
#define ENTERO_H

#include "numero.h"
#include <iostream>

class Entero : public Numero {

    private:
        int valor;

    public:
        Entero(int v) : valor(v) {}
        
        Numero* suma(const Numero& otro) const override {
            const Entero* e = dynamic_cast<const Entero*>(&otro);
            return new Entero(valor + e->valor);
        }

        Numero* resta(const Numero& otro) const override {
            const Entero& e = dynamic_cast<const Entero&>(otro);
            return new Entero(valor - e.valor);
        }
    
        Numero* multiplicacion(const Numero& otro) const override {
            const Entero& e = dynamic_cast<const Entero&>(otro);
            return new Entero(valor * e.valor);
        }
    
        std::string toString() const override {
            return std::to_string(valor);
        }
};

#endif