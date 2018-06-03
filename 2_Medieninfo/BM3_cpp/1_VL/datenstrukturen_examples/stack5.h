struct satom
    {
    char *inhalt;
    struct satom *naechstes;
    } ;

class ClStack 
    {
private:
    struct satom *start;
public:
    ClStack();
    ~ClStack();
    void push(char *zkette);
    char *pop(void);
    int empty();
    } ;
