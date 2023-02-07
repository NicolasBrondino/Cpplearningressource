
#include <iostream>
using namespace std;

/* 2 simple examples about class hierarchy, use of virtual, and the concept of interface. */

/// example 1: class hierarchy and virtual ///////////////////////////////////////////////////////////////////////////////////////////////
// a simple example, fruit is the mother class, banana and strawberry are the daughter classes.
class fruit{
private:
    int seeds;
public:
    fruit(){cout << "construct fruit\n";}
    ~fruit(){cout << "deconstruct fruit\n";}
    shout(){cout << "I'm a fruit.\n";}
    //virtual doFruitThing() = 0;
    };

class banana : public virtual fruit{
public:
    shout(){cout << "I'm a banana.\n";} // The daughter function is going to be called.
};

class strawberry : public virtual fruit{
public:
    //Shout() isn't implemented here, the mother function is going to be called.
};

/// example 2: pure virtual class, or interface. //////////////////////////////////////////////////////////////////////////////////////
class vehicle{ // This class has many names : abstract class. interface. pure virtual.
public:
    virtual void vehicleNoise() = 0; // This method is virtual in the mother class,
};

class car: public vehicle{
public:
    void vehicleNoise(){cout << "I'm a car.\n";} // so it must be implemented in the daughter class.
};

int main(){

    /// example 1 : just some calls between class hierarchy members.
    {
        // creating mother object, daughter 1, daughter 2
        fruit F;
        banana B;
        strawberry S;
        // whose function is going to be called ?
        F.shout();
        B.shout();
        S.shout();
    }
    cout << endl << "end of example 1." << endl << endl;

    /// example 2 : interface mother class (all methods are virtual and must be implemented in a daughter class)
    {
        //vehicle v; // You should not instanciate an interface class.
        //v.vehicleNoise(); // Won't work, as this method isn't implemented in the mother class.
        car C;
        C.vehicleNoise(); // implemented in the daughter class.
        cout << "End of program. going out of scope, deconstructing.\n";
    }
    cout << endl << "end of example 2." << endl << endl;

}
