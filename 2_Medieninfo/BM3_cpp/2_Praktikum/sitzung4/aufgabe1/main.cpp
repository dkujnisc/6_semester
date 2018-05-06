#include <iostream>
#include "header1.h"
#include <string>

using namespace std;

class student {
  private:
    string nachname;
    string vorname;
  unsigned
  int
  mat_nr;
  public:
    student()
    // initiating default values into the variables.
    {
      nachname = "";
      vorname = "";
      mat_nr = 0;
    }

    ~student() {
        cout << "Destructor called" << endl;
    }

  // useful if we work with dynamic memory allocation.
  void entryData(string a, string b, unsigned int c) {
    nachname = a;
    vorname = b;
    mat_nr = c;
  }
  void printData() {
    cout << nachname << ", " << vorname << " : " << mat_nr << endl;
  }
};

int main()
{
    student *std1, *std2;
    std1 = new student;
    std2 = new student;
    std1->entryData("Planck","Max",99999);
    std2->entryData("Zuse","Konrad",88888);
    std1->printData();
    std2->printData();
    delete std1; // hier manueller aufruf des destructors
    cout << "finished shit" << endl;
    return 0;
}
