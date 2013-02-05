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
    bool windows_user;
    public:
        Programmer(bool z):
            windows_user(z),
            Person(false)
            {
            }
        virtual void type() {
            cout << "Programmer ";
            if (windows_user) {
                cout << "is a windows user and ";
            }
        }
};

class PseudoProgrammer : virtual public Programmer {
public:
    PseudoProgrammer():
        Programmer(true),
        Person(true)
    {
        //likesDiamonds = true;
    }
    void type() {
        cout << "Pseudo Programmer ";
    }
};

class PHPProgrammer : virtual public Programmer {
public:
    PHPProgrammer():
        Person(true),
        Programmer(true)
    {
        //likesDiamonds = true;
    }
    void type() {
        cout << "PHP Programmer ";
    }
};

int main() {
    Person p(true);
    p.status();

    Programmer pr(false);
    pr.status();

    PseudoProgrammer psp;
    psp.status();

    PHPProgrammer php;
    php.status();

    pr = psp;
    pr.status(); // object slicing

    Programmer* prpointer = new Programmer(false);
    prpointer = &psp;
    prpointer->status();
}

//  Person likes diamonds
//  Programmer dislikes diamonds
//  Pseudo Programmer likes diamonds
//  PHP Programmer likes diamonds
//  Programmer is a windows user likes diamonds
//  Pseudo Programmer likes diamonds
