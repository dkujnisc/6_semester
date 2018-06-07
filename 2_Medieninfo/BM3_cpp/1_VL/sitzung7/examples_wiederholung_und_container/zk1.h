#include <string.h>

class ClZeichenKette {
public:
   ClZeichenKette();
   ClZeichenKette(int reserviere);
   ~ClZeichenKette();
   ClZeichenKette operator+(const ClZeichenKette &zk);
   friend ostream &operator<< (ostream &ausgabe, ClZeichenKette & zk)
      {
      ausgabe << zk.text;
      return ausgabe;
      }
   friend istream & operator >> (istream &eingabe, ClZeichenKette & zk)
      {
      char puffer[1024];

      eingabe >> puffer;
      if (zk.text!=NULL) delete zk.text;
      zk.laenge=strlen(puffer);
      zk.text=new char[zk.laenge+1];  
      strcpy(zk.text,puffer);
      return eingabe;
      }
private:
   int laenge;
   char *text;
};
