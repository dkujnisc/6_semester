class ClWaehrung
   {
protected:
   int unit;
   char text[64];
   int waehrung;
public:
   ClWaehrung() { unit=0; *text='\0'; waehrung= -1; }
   ~ClWaehrung() { return; }
   void ladeBetrag(istream &eingabe,ClWTabelle &tab);
   char *zeigeWert(ClWTabelle &tab,char *verwende);
   char *zeigeWaehrung(ClWTabelle &tab);
   int wert(void) {return unit; }   
   } ;
