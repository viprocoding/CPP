#ifndef KORT_H
#define KORT_H

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

enum Farg {
    HJARTER,
    RUTER,
    SPADER,
    KLOVER,
    OSPECIFISERAD,
    FARG,
};

class Kort
{
public:

    /** Default konstruktor
     */
    Kort(void);

    /** Konstruktur
     *
     * @param valor     Korests valör.
     * @param farg      Kortest färg.
     */
    Kort(Valor valor, Farg farg);

    /** Använd kompilatorns default versioner:
     */
    Kort(const Kort&)            = default;
    Kort(Kort&&)                 = default;
    ~Kort(void)                  = default;
    Kort& operator=(const Kort&) = default;
    Kort& operator=(Kort&&)      = default;

    /** Tillgång till kortets valör.
     *
     * @return      Kortets valör.
     */
    Valor visaValor(void) const;

    /** Tillgång till kortets färg.
     *
     * @return      Korets färg
     */
    Farg visaFarg(void) const;

    /** Skriv ut kortinformation
     * 
     * @return      Referens till det här objektet.
     */
    Kort& kortInfo(void);


private:
    
    /** Kortets valör
     */
    Valor v;
    
    /** Kortets färg
     */
    Farg f; 

    /** Tabell för utskrift av färg.
     */
    const char* fargTabell[50] = {
        "Hjärter",
        "Ruter",
        "Spader",
        "Klöver",
        ""
    };

    /** Tabell för utskrift av valör.
     */
    const char* valorTabell[50] = {
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

#endif // KORT_H
