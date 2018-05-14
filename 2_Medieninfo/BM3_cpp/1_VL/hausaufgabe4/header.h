#ifndef HEADER_H
#define HEADER_H

using namespace std;

class ClWaehrung
   {
protected:
    // da int nur ca 32000 stellen hat, könnten nur höchstens 32000 pfennig in der waehrung sein
    // 134 taler wuerden schon den rahmen sprengen
   long w=0;

public:
   // quelle: https://en.wikibooks.org/wiki/C%2B%2B_Programming/Classes/Abstract_Classes
   // quelle: https://stackoverflow.com/questions/2391679/why-do-we-need-virtual-functions-in-c
   // abstrakte klasse, da alles virtual ist
   // dient lediglich als mutterklasse
   long asnumber() {
       return w;
   }
   virtual string asGulden();
   virtual string asTaler();
};

class ClTaler : public ClWaehrung
   {
public:
   ClTaler();
   ClTaler (long taler, long silbergroschen, long pfennige);
   ~ClTaler () {
       return;
   }
   string asGulden();
   string asTaler();

   friend ostream & operator << (ostream &ausgabe, ClTaler &tali){
      ausgabe << tali.asTaler();
      return ausgabe;
   }
   friend istream & operator >> (istream &eingabe, ClTaler &tali){
      return eingabe;
   }
   ClTaler operator+ (const ClTaler & tali){
      return ClTaler(0,0,w+tali.w);
   }
};

class ClGulden : public ClWaehrung
   {
public:
   ClGulden();
   ClGulden (long gulden, long kreuzer, long pfennige);
   ~ClGulden () {
       return;
   }
   string asGulden();
   string asTaler();


friend ostream & operator << (ostream &ausgabe, ClGulden &guldy){
   ausgabe << guldy.asGulden();
   return ausgabe;
}
friend istream & operator >> (istream &eingabe, ClGulden &guldy){
   return eingabe;
}
ClGulden operator+ (const ClGulden & guldy){
   return ClGulden(0,0,w+guldy.w);
}
};

#endif // HEADER_H
