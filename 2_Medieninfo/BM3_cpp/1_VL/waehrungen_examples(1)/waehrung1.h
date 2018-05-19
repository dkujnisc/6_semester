class ClWaehrungGulden
   {
private:
   int fl;
   int x;
   int d;
   char textg[64];
   int t;
   int sgr;
   int pf;
   char textt[64];   
   void ladeGulden (istream &eingabe);
public:
   ClWaehrungGulden() { fl=x=d=t=sgr=pf=0; }
   ClWaehrungGulden(int ifl, int ix, int id) ;
   ~ClWaehrungGulden() { return; }
   char *asGulden(void);
   char *asTaler(void);
   friend istream & operator >> (istream &eingabe, ClWaehrungGulden &gulden)
      {
      gulden.ladeGulden(eingabe);
      return eingabe;
      }   
   } ;

class ClWaehrungTaler
   {
private:
   int t;
   int sgr;
   int pf;
   char textt[64]; 
   int fl;
   int x;
   int d;
   char textg[64];
   void ladeTaler ( istream &eingabe);
public:
   ClWaehrungTaler() { t=sgr=pf=fl=x=d=0; }
   ClWaehrungTaler(int it, int isgr, int ipf) ;
   ~ClWaehrungTaler() { return; }
   char *asTaler(void);
   char *asGulden(void);
   friend istream & operator >> (istream &eingabe, ClWaehrungTaler &taler)
      {
      taler.ladeTaler(eingabe);
      return eingabe;
      }   
   } ;
