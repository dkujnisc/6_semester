class ClWaehrung
   {
protected:
   int unit;
   char text[64];
public:
   ClWaehrung() { unit=0; *text='\0'; }
   ~ClWaehrung() { return; }
   void ladeGulden(istream &eingabe);
   void ladeTaler(istream &eingabe);
   char *asGulden(void);
   char *asTaler(void);
   } ;
