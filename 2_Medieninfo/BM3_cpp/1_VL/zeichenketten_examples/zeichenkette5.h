#include <string.h>

class ClZeichenkette
   {
private:
   char *text;
   int laenge;
   void verbinde ( const ClZeichenkette &zk1, const ClZeichenkette &zk2 );
   void ladeZk ( istream &eingabe);

public:
   ClZeichenkette() { text=NULL; laenge=0; }
   ClZeichenkette(const char *anfangswert);
   char *kette() { return text; }
   int anzahl() { return laenge; }
   friend ostream & operator << (ostream &ausgabe, ClZeichenkette &zk)
      {
      ausgabe << zk.text;
      return ausgabe;
      }
   friend istream & operator >> (istream &eingabe, ClZeichenkette &zk)
      {
      zk.ladeZk(eingabe);
      return eingabe;
      }
   ClZeichenkette operator+ (const ClZeichenkette & zk2)
      {
      ClZeichenkette neuzk;
      neuzk.verbinde(*this, zk2);
      return neuzk;
      }
   } ;