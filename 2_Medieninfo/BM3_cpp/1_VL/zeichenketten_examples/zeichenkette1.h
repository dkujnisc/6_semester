class ClZeichenkette
   {
private:
   char *text;
   int laenge;

public:
   ClZeichenkette() { text=NULL; laenge=0; }
   ClZeichenkette(char *anfangswert);
   char *kette() { return text; }
   int anzahl() { return laenge; }
   void verbinde ( const ClZeichenkette &zk1, const ClZeichenkette &zk2 );
   } ;
