#include <iostream>
using namespace std;
#include "zk2.h"

ClZeichenKette::ClZeichenKette(
        int                            reserviere)
{
    laenge=reserviere;
    text=new char[laenge+1];
    *text='\0';
}

ClZeichenKette::ClZeichenKette(void)
{
    laenge=0;
    text=NULL;
}

ClZeichenKette::~ClZeichenKette()
{
    cout << "Destruct: " << (int)(size_t)text << " = " << text << endl;
    if (text!=NULL) delete text;
}

ClZeichenKette ClZeichenKette::operator+(
        const ClZeichenKette                    &zk)
{
    ClZeichenKette *p;
    p = new ClZeichenKette(laenge+zk.laenge);

    strcpy(p->text,text);
    strcat(p->text,zk.text);

    return *p;
}
