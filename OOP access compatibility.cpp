#include <iostream>
using namespace std;

/* Prerequisite : OOP, class hierarchy. This example file is about special compiler cases:
What happens when have use a mother type pointer pointing on a daughter type object ?
What happens when have use a mother type reference pointing on a daughter type object ?
What happens when have use a mother type pointer pointing on a reference to a daughter type object ?
What happens when we revert all three situations ?
While it's good practice to maintain clarity in your code, some of these cases are accepted
by the compiler. */

// mother class
struct Animal {
    virtual void talk(){cout<<"I am an animal."<< endl;} //mother.talk is virtual
    Animal(){cout<<"creating animal."<<endl;}
    ~Animal(){cout<<"destructing animal."<<endl;}
};
//daughter classes
struct Dog : Animal{
    void talk(){cout<<"I am a dog."<< endl;}
    void uniqueToDog(){cout<<"unique to dog, not present in animal."<< endl;} // unique to dog, not present in animal.
    Dog(){cout<<"creating Dog."<<endl;}
    ~Dog(){cout<<"destructing Dog."<<endl;}
};
struct Cat : Animal {
    void talk(){cout<<"I am a cat."<< endl;}
    void uniqueToDog(){cout<<"unique to dog, not present in animal."<< endl;} // unique to cat, not present in animal.
    Cat(){cout<<"creating Cat."<<endl;}
    ~Cat(){cout<<"destructing Cat."<<endl;}
};
int main(){

    /// 0 -Reminder : Here is a normal class hierarchy, mother and daughter class, use of virtual. This is the standard use.
    {
        Animal animalTest;
        Dog dogTest;
        animalTest.talk(); // "I am an animal."
        dogTest.talk(); // "I am a dog."
    }
    cout << "end of reminder." << endl << endl;

    /// 1 - = operator between mother and daughter object -> trunkation (deletion) of the daughter part of the object.
    /// Note : The reverse operation is rejected by the compiler.
    {
        Dog dog1;
        // We initialize a mother object with the data from a daughter object. Only the "mother" part of the object is kept.
        Animal animal1 = dog1;
        animal1.talk(); // That's an animal.
    }// end of scope : automatic desctruction of object
    cout << "end of example 1. " << endl << endl;

/* a pointer or reference for mother class can point on a daughter type object without constraints or limits. */



    /// 2 : mother type reference, pointing on a daughter type object
    /// note : The reverse situation (daughter type reference pointing on a mother type object) will be rejeted by the compiler.
    {
        Dog dog2;
        Animal& animal2 = dog2; // reference pointing on dog2. equivalent to Dog& animal2 = dog2;
        animal2.talk();// dog2 is speaking (via the animal2 reference).
        //animal2.uniqueToDog(); // this function isn't available in a mother type structure.
    }
    cout << "end of example 2." << endl << endl;


    /// 3 : mother type pointer takes a daughter type reference.
    /// note : The reverse situation (Daughter type pointer takes a mother type reference) will be rejected by the compiler.
    {
        Cat cat1;
        Animal *animal3 = &cat1;//this pointer points cat1. Equivalent to Cat *animal3 = &cat1;
        animal3->talk(); // cat1 speaks (via the pointer animal3).
        //animal3->uniqueToCat(); // That function isn't available in a mother type structure
    } // static pointer, automatic deletion.
    cout << "end of example 3." << endl << endl;




}
