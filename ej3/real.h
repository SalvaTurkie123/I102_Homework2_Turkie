#ifndef REAL_H
#define REAL_H

#include "numero.h"

class Real : public Numero {
private:
    double valor;

public:
    Real(double v) : valor(v) {}

    Numero* suma(const Numero& otro) const override {
        const Real& r = dynamic_cast<const Real&>(otro);
        return new Real(valor + r.valor);
    }

    Numero* resta(const Numero& otro) const override {
        const Real& r = dynamic_cast<const Real&>(otro);
        return new Real(valor - r.valor);
    }

    Numero* multiplicacion(const Numero& otro) const override {
        const Real& r = dynamic_cast<const Real&>(otro);
        return new Real(valor * r.valor);
    }

    std::string toString() const override {
        return std::to_string(valor);
    }
};

#endif
