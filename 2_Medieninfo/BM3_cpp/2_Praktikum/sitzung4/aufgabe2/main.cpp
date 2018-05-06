#include <iostream>

using namespace std;

class ClFriend {
private:
    int x;
public:
    void setX(int input) {
        x = input;
    }
    friend int getX(ClFriend &input);
    int getXNoFriend();
};

int getX(ClFriend &input) {
    return input.x;
}

int ClFriend::getXNoFriend() {
    return x;
}

int main()
{
    ClFriend clFriend;
    clFriend.setX(5);
    cout << "x: " << getX(clFriend) << endl;
    return 0;
}
