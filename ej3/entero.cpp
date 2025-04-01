#include "entero.h"

Entero::Entero(int v) : valor(v) {}

Numero* Entero::suma(const Numero& otro) const {
    const Entero* e = dynamic_cast<const Entero*>(&otro);
    return new Entero(valor + e->valor);
}

Numero* Entero::resta(const Numero& otro) const {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(valor - e.valor);
}

Numero* Entero::multiplicacion(const Numero& otro) const {
    const Entero& e = dynamic_cast<const Entero&>(otro);
    return new Entero(valor * e.valor);
}

std::string Entero::toString() const {
    return std::to_string(valor);
}
