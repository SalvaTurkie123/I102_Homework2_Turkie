#ifndef COMPLEJO_H
#define COMPLEJO_H

#include "numero.h"
#include <sstream>

class Complejo : public Numero {
private:
    double real;
    double imaginario;

public:
    Complejo(double r, double i) : real(r), imaginario(i) {}

    Numero* suma(const Numero& otro) const override {
        const Complejo& c = dynamic_cast<const Complejo&>(otro);
        return new Complejo(real + c.real, imaginario + c.imaginario);
    }

    Numero* resta(const Numero& otro) const override {
        const Complejo& c = dynamic_cast<const Complejo&>(otro);
        return new Complejo(real - c.real, imaginario - c.imaginario);
    }

    Numero* multiplicacion(const Numero& otro) const override {
        const Complejo& c = dynamic_cast<const Complejo&>(otro);
        return new Complejo(real * c.real - imaginario * c.imaginario,
                            real * c.imaginario + imaginario * c.real);
    }

    std::string toString() const override {
        std::ostringstream ss;
        ss << real << " + " << imaginario << "i";
        return ss.str();
    }
};

#endif
