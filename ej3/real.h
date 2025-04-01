#ifndef REAL_H
#define REAL_H

#include "numero.h"
#include <string>

class Real : public Numero {
private:
    double valor;

public:
    Real(double v);
    
    Numero* suma(const Numero& otro) const override;
    Numero* resta(const Numero& otro) const override;
    Numero* multiplicacion(const Numero& otro) const override;
    
    std::string toString() const override;
};

#endif
