class ClWaehrung
   {
protected:
   int fl;
   int x;
   int d;
   char textg[64];
   int t;
   int sgr;
   int pf;
   char textt[64];   
public:
   ClWaehrung() { fl=x=d=t=sgr=pf=0; } 
   ClWaehrung(int ifl, int ix, int id) ;
   ~ClWaehrung() { return; }
   char *asGulden(void);
   char *asTaler(void);
   } ;

class ClWaehrungGulden : public ClWaehrung
   {
private:
   void ladeGulden (istream &eingabe);
public:
   ClWaehrungGulden();
   ClWaehrungGulden(int ifl, int ix, int id) ;
   ~ClWaehrungGulden() { return; }
   friend istream & operator >> (istream &eingabe, ClWaehrungGulden &gulden)
      {
      gulden.ladeGulden(eingabe);
      return eingabe;
      }   
   } ;

class ClWaehrungTaler : public ClWaehrung
   {
private:
   void ladeTaler ( istream &eingabe);
public:
   ClWaehrungTaler() { t=sgr=pf=fl=x=d=0; }
   ClWaehrungTaler(int it, int isgr, int ipf) ;
   ~ClWaehrungTaler() { return; }
   friend istream & operator >> (istream &eingabe, ClWaehrungTaler &taler)
      {
      taler.ladeTaler(eingabe);
      return eingabe;
      }   
   } ;
