#ifndef COMPLEJO_H
#define COMPLEJO_H

#include "numero.h"
#include <sstream>

class Complejo : public Numero {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    
    std::string toString() const override;
};

#endif
