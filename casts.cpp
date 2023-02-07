#include <iostream>
using namespace std;

// this is used in example 5, ignore if you read sequentially.
// here is some function that does nothing important. What matters is that it takes a non const pointer to int.
void someFunction(int* p) {
  cout << *p << endl;
}

int main(){
    /* Casting is usually meant as changing the type of a variable, but there are other casts for other situations.
    In this serie of examples, we'll explore type casting from C to old then modern C++.
    Then we'll check those special casting operations, including dynamic_cast, const_cast, and reinterpret_cast. */

    ///1- Let's have a C style explicit casting example first.

    float someNumber = 5.41;

    cout << "my number cast as int: " << (int) someNumber << endl; // float converted as int, only "5" should remain.

    ///2- Let's see how a C++ 11 explicit casting is done.

    cout << "my number cast as int: " << int(someNumber) << endl; // same effect.

    ///3 - implicit casting :

    int trunkNumber = someNumber; // Since C, some basic data types can be implicitly casted that way.

    ///4 - static_cast is the most modern standard. It will safely throw errors in the incompatibles cases.

    cout << "my number cast as int: " << static_cast<int>(someNumber) << endl; // It is always recommended to use the most modern method.


    ///5- const_cast is used when you want to obtain (handle) control of a const object.
    // important : const_cast do NOT remove constness, instead it removes appareance of constness.

    /* First, let's considerer this constant object. I use a simple int,
    but let's consider that this is a massive object that cannot be copied. */

    const int someConstValue = 10;
    const int* b = &someConstValue;

    /* Second, this function someFunction() expects int*, not const int*. For our
    example, you should consider that this function is provided externally,
    and cannot be modified as well.  */

    //someFunction(someConstValue); // It will throw an error if you use our object someConstValue as a parameter.

    /* So at this stage, we have :
    - our someConstValue object. Because it's massive, we can't just make a non const clone and pass it as a parameter.
    - our external function someFunction(). We can't modify it as well.
    That's where we can use const_cast. */

    int* nonConstPointerToOurObject = const_cast<int*>(&someConstValue);
    // call function successfully without const attribute
    someFunction(nonConstPointerToOurObject);
    cout << someConstValue << endl << endl;

    /* But despite the apparent removal of the const attribute, our original
    object remains const. Trying to modify it via our nonConstPointerToOurObject
    will not work. */



    /// 6 - reinterpret_cast

    /*
    - Used to cast between different pointer types.
    - Does not throw an error if anything goes wrong. In other words, pretty dangerous to use.
     */

    int* someVal = new int(67); // pointer to int, value is 67.
    char* someChar = reinterpret_cast<char*>(someVal); // forcing cast as char* of 67.
    cout << *someVal << endl;
    cout << *someChar << endl << endl; // 67 is interpreted as "C".

    /// 7 - dynamic_cast is used to cast between a class hierarchy.

    /* Dynamic_cast is used to perform checks when casting between members of a class hierarchy.
    It is very important to considerer that dynamic casts are made at run time, and not at compile time.
    it answers the question of whether we can safely assign the address of an object to a pointer of a particular type.*/

    // a mother and a daughter class.
    class Animal {
    public:
        void print()
        {
            cout << "I'm an animal." << endl;
        }
    };

    class Cat : public Animal {
    public :
        void print()
        {
            cout << "I'm a cat." << endl;
        }
    };


    Cat someCat;
    // Let's cast an daughter object into a mother object.
    Animal* someAnimal = dynamic_cast<Animal*>(&someCat);

    // That object is now a mother type object.
    someAnimal->print();


}
