#include <iostream>

using namespace std;
class Person {
    bool likesDiamonds;

public: 
    virtual void type() {
        cout << "Person ";
    }
    void status() {
        type();
        if (likesDiamonds) {
            cout << "likes";
        } else {
            cout << "dislikes";
        }
        cout << " diamonds" << endl;
    }
    Person(bool l) {
        likesDiamonds = l;
    }
};

class Programmer : virtual public Person {
    public:
        Programmer():
            Person(false)
            {
            }
        virtual void type() {
            cout << "Programmer ";
        }
};

class PseudoProgrammer : virtual public Programmer {

public:
    PseudoProgrammer():
        Programmer(),
        Person(true)
    {
        //likesDiamonds = true;
    }
    void type() {
        cout << "Pseudo Programmer ";
    }
};

int main() {
    Person p(true);
    p.status();

    Programmer pr;
    pr.status();

    PseudoProgrammer psp;
    psp.status();

    pr = psp;
    pr.status();
}


