#include "Kort.h"
#include <iostream>

Kort::Kort(void)
    : v(JOKER), f(OSPECIFISERAD)
{
}

Kort::Kort(Valor valor, Farg farg)
    : v(valor), f(farg)
{
}

Valor Kort::visaValor(void) const
{
    return v;
}

Farg Kort::visaFarg(void) const
{
    return f;
}

Kort& Kort::kortInfo(void)
{
    std::cout << fargTabell[f] << " " << valorTabell[v] << std::endl;
    return *this;
}
