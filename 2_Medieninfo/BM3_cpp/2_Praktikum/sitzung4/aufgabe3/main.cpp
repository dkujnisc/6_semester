#include <iostream>

using namespace std;

class ClThis {
private:
    int x;
public:
    void setX(int input) {
        this->x = x;
    }
    int getX() {
        return x;
    }

int main()
{
    ClThis clThis;
    clThis.setX(5);
    cout << "x: " << clThis.getX() << endl;

    cout << "Hello bitch!" << endl;
    return 0;
}
