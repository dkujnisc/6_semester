class ClRomZahl
    {
public:
    void hole() { cin >> roemisch; zuArabien();}
    char *druckbar() { return roemisch; }
    void addiere(ClRomZahl zahl1,ClRomZahl zahl2)
       {
       arabisch=zahl1.arabisch+zahl2.arabisch;
       zuRom();
       }
private:
    char roemisch[20];
    int arabisch;
    void zuArabien();
    void zuRom();
    } ;
