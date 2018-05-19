enum waehrung {keine, gulden, taler};

class ClWaehrung
   {
protected:
   int unit;
   char text[64];
   enum waehrung waehrung;
public:
   ClWaehrung() { unit=0; *text='\0'; waehrung=keine; }
   ~ClWaehrung() { return; }
   void ladeBetrag(istream &eingabe);
   char *asGulden(void);
   char *asTaler(void);
   char *asIs(void);
   friend istream & operator >> (istream &eingabe, ClWaehrung &betrag)
      {
      betrag.ladeBetrag(eingabe);
      return eingabe;
      }
   int wert(void) {return unit; }   
   } ;
