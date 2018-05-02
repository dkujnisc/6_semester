#include <string.h>

class ClZeichenkette
   {
private:
    // pointer definiert, zeigt auf nix
   char *text;
   int laenge;
   void verbinde ( const ClZeichenkette &zk1, const ClZeichenkette &zk2 );
   void ladeZk ( istream &eingabe);

public:
   ClZeichenkette() {
       text=NULL;
       laenge=0;
   }
   // speicherfreigabe
   ~ClZeichenkette() {
       delete text;
   }

  /* ClZeichenkette(ClZeichenkette *vorlage){
       laenge = vorlage->laenge;
       text = new char[laenge];
       text = vorlage->text;
   }*/

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
   ClZeichenkette & operator= (const ClZeichenkette & zk2)
      {
       if (this!= & zk2){
           laenge = zk2.laenge;
           try {
               text = new char[laenge+1];
           }
           catch (out_of_range) {
               cout << "not good" << endl;
           }

           text = zk2.text;
       }
       return *this;
      }
   } ;
