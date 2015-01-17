#ifndef KORT_H
#define KORT_H

// Bibliotek
#include <vector>       // vector
#include <cstddef>      // size_t
#include <utility>      // pair

/** Datatyp för kortvalör.
 */
enum Valor {
    ESS,
    TVA,
    TRE,
    FYRA,
    FEM,
    SEX,
    SJU,
    ATTA,
    NIO,
    TIO,
    KNACKT,
    DAM,
    KUNG,
    JOKER,
    VALOR,
};

/** Datatyp för kortfärg.
 */
enum Farg {
    HJARTER,
    RUTER,
    SPADER,
    KLOVER,
    OSPECIFISERAD,
    FARG,
};


/**** Övrig klassinformation
 *
 *  -- Kortinformation som anges på parform anges med ordning (Valor, Farg).
 */
class Kort {
public:

    /**** Default konstruktor
     * Skapar en Joker som saknar färg.
     */
    Kort(void);

    /**** Konstruktur
     *
     * @param kort      Ett par med kortinformation.
     */
    Kort(const std::pair<Valor, Farg>&  kort);

    /**** Använd kompilatorns default versioner:
     */
    Kort(const Kort&)            = default;
    Kort(Kort&&)                 = default;
    ~Kort(void)                  = default;
    Kort& operator=(const Kort&) = default;
    Kort& operator=(Kort&&)      = default;

    /**** Tillgång till kortets information
     *
     * @return          Konstant referens till att par med kortinformation.
     */
    const std::pair<Valor, Farg>& visaKort(void) const;

    /**** Ändra kortets information
     *
     * @param kort      Ett par med ny kortinformation.
     * @return          Referens till det här objektet.
     */
    Kort& angeKort(const std::pair<Valor, Farg>& kort);

    /**** Skriv ut kortinformation
     * 
     * @return      Referens till det här objektet.
     */
    Kort& kortInfo(void);

private:
    
    /** Kortinformation
     */
    std::pair<Valor, Farg> kortInformation;

    /** Tabell för utskrift av färg.
     * -- Borde deklareras static
     */
    const char* fargTabell[FARG] = {
        "Hjärter",
        "Ruter",
        "Spader",
        "Klöver",
        ""
    };

    /** Tabell för utskrift av valör.
     * -- Borde deklareras static
     */
    const char* valorTabell[VALOR] = {
        "Ess",
        "2",
        "3",
        "4",
        "5",
        "6",
        "7",
        "8",
        "9",
        "10",
        "Knäckt",
        "Dam",
        "Kung",
        "Joker"
    };
};

class Kortlek {
public:
    
    /**** (Default) konstruktur
     * Korten skapas i ordning ess, två, ..., kung med färg hjärter, ruter,
     * spader, klöver. Processen är cykliskt, dvs. det är tillåtet att skapa
     * kortlekar med fler än 52 kort.
     *
     * @param antKort   Antal kort i kortleken.
     */
    Kortlek(size_t antKort = 52);

    // Använd kompilatorns defaultversioner:
    Kortlek(const Kortlek&)            = default;
    Kortlek(Kortlek&&)                 = default;
    ~Kortlek(void)                     = default;
    Kortlek& operator=(const Kortlek&) = default;
    Kortlek& operator=(Kortlek&&)      = default;

    /**** Skriver ut alla kort
     *
     * @return          Referens till det här objektet.
     */
    Kortlek& skriv(void);

    /**** Skriver ut kort på position
     * Indexering sker från 0.
     *
     * @param index     Index av ett kort i kortleken som ska skrivas ut.
     * @return          Referens till det här objektet.
     * @range_error     Exceptionell händelse genereras om index >= antal kort.
     */
    Kortlek& skriv(size_t index);

    /**** Blanda kortlek
     * Notera att std::srand måste seedas innan korten blandas för att få en
     * annorlunda blanding varje gång funktionen anropas.
     *
     * @return          Referens till det här objektet.
     */
    Kortlek& blanda(void);

    /**** Ta bort kort på position
     * Indexering sker från 0.
     *
     * @param index     Index av ett kort som ska tas bort.
     * @return          Referens till det här objektet.
     *
     * @range_error     Exceptionell händelse genereras om index >= antal kort.
     */
    Kortlek& taBort(size_t index = 0);

    /**** Tillgång till kortinformation
     * Indexering sker från 0.
     *
     * @param index     Index av ett kort som ska undersökas.
     * @return          Ett par (Valor, Farg) med kortets information.
     *
     * @range_error     Exceptionell händelse genreras om index >= antal kort.
     */
    std::pair<Valor, Farg> visaKort(size_t index = 0);

private:
    
    /** Kortleken består intern av vektor med kort
     */
    std::vector<Kort> kortlek;
};

#endif // KORT_H
