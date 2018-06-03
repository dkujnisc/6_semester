class ClStack 
    {
private:
    char *inhalt;
    ClStack *naechster;
public:
    ClStack() { inhalt=NULL; naechster=NULL; }
    ClStack(char *zkette) { inhalt=new char[strlen(zkette)+1];
                      strcpy(inhalt,zkette);
                      naechster=NULL; }
    ~ClStack() { return; }
    char *hole(void) { return inhalt;}
    ClStack *positioniere(void) { return naechster; }
    void verbinde(ClStack *alt) { naechster=alt; }
    } ;
