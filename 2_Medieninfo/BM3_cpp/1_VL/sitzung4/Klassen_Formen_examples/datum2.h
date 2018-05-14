class ClDatum
   {
private:
   int tag;
   int monat;
   int jahr;
   char text[64];
public:
   ClDatum () { tag=monat=jahr=0; }
   ClDatum (int itag, int imonat, int ijahr) ;
   ClDatum (int itag, char *cmonat, int ijahr) ;
   ~ClDatum () { return ;}
   char *astext(void);
   int asnumber(void);
   } ;
