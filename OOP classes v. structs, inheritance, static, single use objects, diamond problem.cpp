
#include <iostream>
using namespace std;

/* Some OOP examples in this file :
- standard inheritance
- static variables
- classes vs structs
- single use objects
- the diamond problem */

// Let's start with this class hierarchy, a mother class, and 2 daughter classes.
class animal{
private:
    int age;
public:
    animal(){cout << "building animal\n";}
    ~animal(){cout << "destructing animal\n\n";}
protected:
    int legsQty; // A protected variable is accessible from within all objects of the class hierarchy.
};

class dog:  animal{
private:
    /* A static variable:
    Only one int will be allocated for the class and all the objets created from it.
    If this static element were of large size, for example, only one element size
    would be allocated, no matter the number of instanciated objects. The class and
    all instanciated objects share this static variable. */
    static const int numberOfFleas = 55; // I also made it const. All dogs will now have 55 fleas.
public:
    dog(){cout << "building dog\n";}
    ~dog(){cout << "destructing dog\n";}
};

class cat:  animal{
public:
    cat(){cout << "building cat\n";}
    ~cat(){cout << "destructing cat\n";}

};

// A new species inheriting from dog and cat to illustrate our diamond problem.
class dogCat : dog,cat{
    public:
    dogCat(){cout << "building dogCat\n";}
    ~dogCat(){cout << "destructing dogCat\n";}
};

int main(){

    /// 1 - The diamond problem

    /* To illustrate our diamond problem, with have a mother class, "animal". We have two daughter classes of animal, "dog" and "cat".
    And we have that "dogCat" class, which is the daughter of both "dog" and "cat" classes.
    Each constructor is printing an identification message. If we create a dogCat object, this should print :

    building animal
    building dog
    building animal
    building cat
    building dogCat

    The constructor for the mother class, animal, is called twice. This is the diamond problem.
    To solve this, we declare the intermediate classes, dog and cat, virtual. Here are the printed message when creating a dogCat now :

    building animal
    building dog
    building cat
    building dogCat */

    dogCat myWeirdPet;

    cout<< "eeeeeee" << endl;

    /// 2 - class inheritance, function call between class hierarchy
    {
        cout << " animal a" << endl;
        animal a;
        cout << "\n dog d"  << endl;
        dog d;
        cout << "\n cat c"  << endl;
        cat c;
        cout << "\n going out of scope, calling destructors:"  << endl;
    }

    /// 3 - classes vs structs
    /* struct in C are passive data structures, that can only contain variables.
    struct and classes in C++ are active data structures, that can contain both
    variables and methods. There is only one difference in C++ between classes and structs : */

    class dog { // members in classes are by default private.
        int age;
        void bow(){cout<<"bow bow";}
    };

    dog myDog;
    /*myDog.age = 5; //error : dog.age is private
    cout << myDog.age;*/

    struct cat { // members in structs are by default public.
        int age;
        void meow(){cout<<"meow";}
    };
    cat myCat;
    myCat.age = 5;
    cout << myCat.age;

    /// 4 - single use objects
    /* a special case : the mono use object
    A name at the end of the class declaration indicates a mono use object. No class is in fact being created here, just
    a temp object called giraffe. You cannot create more giraffes, but you can use this giraffe. */
    class {
        public:
        int age = 5;
    } giraffe; // One giraffe object, no giraffe class created here.
    cout << giraffe.age;


    /// 5 - friend classes

    /* We have two classes A and B.
    By declaring the B class friend of the A class, the b class can now access private and protected members of the class A,
    even if the B class isn't a member of the class hierarchy. */

}
