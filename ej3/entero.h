#ifndef ENTERO_H
#define ENTERO_H

#include "numero.h"
#include <string>

class Entero : public Numero {
private:
    int valor;

public:
    Entero(int v);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    
    std::string toString() const override;
};

#endif
