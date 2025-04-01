#include "complejo.h"

Complejo::Complejo(double r, double i) : real(r), imaginario(i) {}

Numero* Complejo::suma(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(real + c.real, imaginario + c.imaginario);
}

Numero* Complejo::resta(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(real - c.real, imaginario - c.imaginario);
}

Numero* Complejo::multiplicacion(const Numero& otro) const {
    const Complejo& c = dynamic_cast<const Complejo&>(otro);
    return new Complejo(real * c.real - imaginario * c.imaginario,
                        real * c.imaginario + imaginario * c.real);
}

std::string Complejo::toString() const {
    std::ostringstream ss;
    ss << real << " + " << imaginario << "i";
    return ss.str();
}
