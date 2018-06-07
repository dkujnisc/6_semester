#include <iostream>
using namespace std;
#include "waehrung3.h"

int main()
{
char kommando[10];
ClWaehrung betrag;

for(;;)
    {
    cout << "Waehlen Sie eine Aktivitaet:" << endl <<
            " g - Betrag in Gulden eingeben" << endl <<
            " t - Betrag in Talern eingeben" << endl <<
            " * - Programm beenden" << endl;
    cin.getline(kommando,9,'\n');
    switch(kommando[0])
       {
    case 'g':
       cout << "Bitte geben Sie einen Betrag in Gulden ein: ";
       betrag.ladeGulden(cin);

       cout << "Soll der Betrag in Gulden oder in Talern ausgegeben werden (g oder t)? ";
       cin.getline(kommando,9,'\n');
       if(kommando[0]=='g')
         {
         cout << "Sie haben " << betrag.asGulden() << " eingegeben." << endl;
         break;
         }
       if(kommando[0]=='t')
         {
         cout << "Sie haben " << betrag.asTaler() << " eingegeben." << endl;       
         break;
         }
       cout << "Das Kommando " << kommando << " verstehe ich nicht!" << endl;      
       break;

    case 't':
       cout << "Bitte geben Sie einen Betrag in Talern ein: ";
       betrag.ladeTaler(cin);
       cout << "Soll der Betrag in Talern oder in Gulden ausgegeben werden (t oder g)? ";
       cin.getline(kommando,9,'\n');
       if(kommando[0]=='t')
         {
         cout << "Sie haben " << betrag.asTaler() << " eingegeben." << endl;
         break;
         }
       if(kommando[0]=='g')
         {
         cout << "Sie haben " << betrag.asGulden() << " eingegeben." << endl;  
         break;
         }     
       cout << "Das Kommando " << kommando << " verstehe ich nicht!" << endl;   
       break;

    case '*':
       return 0;

    default:
       cout << "Das Kommando " << kommando << " verstehe ich nicht!" << endl;
       break;
       }
    } 
{
	                        /* bitte ignorieren; nur bis zu Ihrer Anmeldung notwendig */
	                        int x;
				                                                cin >> x;
}

}
