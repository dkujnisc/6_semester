class ClRomZahl
    {
public:
    ClRomZahl() { arabisch=0; zuRom(); }
    ClRomZahl( int start) { arabisch=start; zuRom(); }
    char *druckbar() { return roemisch; }
    ClRomZahl operator+ (const ClRomZahl & zahl2)
       {
       return ClRomZahl(arabisch+zahl2.arabisch);
       }
    ClRomZahl operator+ (const int zahl2)
       {
       return ClRomZahl(arabisch+zahl2);
       }
    friend int operator+ (const int &azahl,const  ClRomZahl &rzahl)
       {
       return azahl + rzahl.arabisch;
       }
    ClRomZahl& operator= (const int zahl)
       {
       arabisch=zahl;
       zuRom();
       return *this;
       }
    const ClRomZahl& operator++ () // Präfix (i.e.: vor der "Verwendung")
       {
       arabisch++;
       zuRom();
       return *this;
       }
    const ClRomZahl operator++ (int) // Postfix (i.e.: nach der "Verwendung")
       {
       ClRomZahl kopie(*this);
       arabisch++;
       zuRom();
       return kopie;
       }
    friend ostream & operator << (ostream &ausgabe, ClRomZahl &zahl)
       {
       ausgabe << zahl.roemisch;
       return ausgabe;
       }
    friend istream & operator >> (istream &eingabe, ClRomZahl &zahl)
       {
       eingabe >> zahl.roemisch;
       zahl.zuArabien();
       return eingabe;
       } 
private:
    char roemisch[20];
    int arabisch;
    void zuArabien();
    void zuRom();
    } ;
