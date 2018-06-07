#include <vector>

using namespace std;

enum status {undefiniert, bereit};

class ClWTabelle
   {
private:
   char **waehrungen;
   char **symbol;
   int *wert;
   int *waehrung;
   enum status status;
   int jetzt;
   int jetzigeW;
   vector<string> waehrungenxxx;
   vector<string> symbolxxx;
   vector<int> wertxxx;
public:
   ClWTabelle() { symbol=NULL; wert=NULL; waehrung=NULL; status=undefiniert;}
   ~ClWTabelle() { return; }
   void oeffnen(char *);
   enum status zustand(void) { return status;}
   char *erstesSymbol(void) {jetzt=0;return symbol[0];}
   char *naechstesSymbol(void) {if (symbol[jetzt]!=NULL) jetzt++;
                               return strdup(symbolxxx[jetzt].c_str());}

   //int holeWert(void) {return wert[jetzt];}
   int holeWert(void) {return wertxxx[jetzt];}
   int holeWaehrung(void) {return waehrung[jetzt];}
   //char *zeigeWaehrung(void) {return waehrungen[waehrung[jetzt]];}
   char *zeigeWaehrung(void) {return strdup(waehrungenxxx[waehrung[jetzt]].c_str());}
   char *ersteWaehrung(void) {jetzigeW=0;return waehrungen[0];}
   char *naechsteWaehrung(void) {if (waehrungen[jetzigeW]!=NULL) jetzigeW++;
                                return waehrungen[jetzigeW];}
   int holeWCode(void) {return jetzigeW;}
   char *holeWText(int code) {return waehrungen[code];}
   } ;
