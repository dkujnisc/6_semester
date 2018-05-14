class ClDatum
   {
protected:
   int tag;
   int monat;
   int jahr;
   char text[64];
public:
   ClDatum () { tag=monat=jahr=0; }
   ClDatum (int itag, int monat, int ijahr) ;
   ~ClDatum () { return ;}
   int asnumber(void);
   } ;

class ClNDatum : public ClDatum
   {
private:
   int nmonat;
public:
   ClNDatum();
   ClNDatum (int itag, int imonat, int ijahr) ;
   ~ClNDatum () { return ;}
   char *astext(void);
   } ;

class ClZDatum : public ClDatum
   {
private:
  char zmonat[64];
public:
   ClZDatum();
   ClZDatum (int itag, char *cmonat, int ijahr) ;
   ~ClZDatum () { return ;}
   char *astext(void);
   } ;

