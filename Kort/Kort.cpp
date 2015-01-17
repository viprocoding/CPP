#include "Kort.h"
#include <iostream>
#include <algorithm>    // for_each, random_shuffle
#include <iterator>
#include <stdexcept>    // range_error

///////////////////////////// Kort /////////////////////////////////////////////

/** Default konstruktor
 */
Kort::Kort(void)
    : kortInformation(JOKER, OSPECIFISERAD)
{
}

/** Konstruktor
 */
Kort::Kort(const std::pair<Valor, Farg>& kort)
    : kortInformation(kort)
{
}

/** Tillgång till kortets information
 */
const std::pair<Valor, Farg>& Kort::visaKort(void) const
{
    return kortInformation;
}

/** Ändra kortets information
 */
Kort& Kort::angeKort(const std::pair<Valor, Farg>& kort)
{
    kortInformation = kort;
    return *this;
}

/** Skriv ut kortinformation
 */
Kort& Kort::kortInfo(void)
{
    std::cout << fargTabell[kortInformation.second] << " "
              << valorTabell[kortInformation.first] << std::endl;
    return *this;
}

///////////////////////////// Kortlek /////////////////////////////////////////

/** (Default) konstruktur
 */
Kortlek::Kortlek(size_t antKort)
    : kortlek(antKort)
{
    //kortlek.resize(antKort);
    Valor v = ESS;
    Farg  f = HJARTER;
    
    std::for_each(kortlek.begin(), kortlek.end(), [&v, &f](Kort& k)
    {
        // skapa kort
        k.angeKort(std::pair<Valor, Farg>(v, f));

        // flytta fram valör och färg
        if ((v = Valor( (v + 1) % (VALOR - 1)) ) == 0)
             f = Farg( (f + 1) % (FARG - 1) );
    });
}

/** Skriver ut alla kort
 */
Kortlek& Kortlek::skriv(void)
{
    std::for_each(kortlek.begin(), kortlek.end(), [](Kort k) { k.kortInfo(); });
    return *this;
}

/** Skriver ut kort på position
 */
Kortlek& Kortlek::skriv(size_t index)
{
    if (index >= kortlek.size())
        throw std::range_error("Kortlek::skriv");

    kortlek[index].kortInfo();
    return *this;
}

/** Blanda kortlek
 */
Kortlek& Kortlek::blanda(void)
{
    std::random_shuffle(kortlek.begin(), kortlek.end());
    return *this;
}

/** Ta bort kort på position
 */
Kortlek& Kortlek::taBort(size_t index)
{
    if (index >= kortlek.size())
        throw std::range_error("Kortlek::skriv");

    kortlek.erase(kortlek.begin() + index);
    return *this;
}

/** Tillgång till kortinformation
 */
std::pair<Valor, Farg> Kortlek::visaKort(size_t index)
{
    if (index >= kortlek.size())
        throw std::range_error("Kortlek::skriv");

    return kortlek[index].visaKort();
}
