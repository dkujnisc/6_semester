enum stil {MonatAlsZahl, MonatAlsText};

class ClDatum
   {
private:
   int tag;
   int monat;
   int jahr;
   enum stil stil;
   char text[64];
public:
   ClDatum () { tag=monat=jahr=0; stil=MonatAlsZahl; }
   ClDatum (int itag, int imonat, int ijahr) ;
   ClDatum (int itag, char *cmonat, int ijahr) ;
   ~ClDatum () { return ;}
   char *astext(void);
   int asnumber(void);
   } ;
