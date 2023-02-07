#include <iostream>
#include <vector>
#include <memory>
using namespace std;

/* In this example we explore the different ways we have to
create an object and allocate memory in C++.
- raw static and dynamic memory.
- using smart pointers.
- using copy and move constructors. */

class Dog{
    int *ptrDogData;
    public:
/// 1- Default constructor
    Dog(){
        cout << "Calling Default constructor\n";
        ptrDogData = new int;
    }
/// 2- Copy Constructor
    Dog( const Dog & obj){// copy of object is created
        this->ptrDogData = new int;// Deep copying
        cout << "Calling Copy constructor\n";
    }
/// 3- Move constructor
    Dog ( Dog && obj){
    // It will simply shift the resources, without creating a copy.
        cout << "Calling Move constructor\n";
        this->ptrDogData = obj.ptrDogData;
        obj.ptrDogData = NULL;
    }
/// Destructor
    ~Dog(){
        cout << "Calling Destructor\n";
        delete ptrDogData;
    }
};

int main() {

/// 1 - static and dynamic raw memory.
cout << "static, dynamic raw pointers, and smart pointers:" << endl << endl;

    {
        cout << "dynamic raw pointer on a Dog:" << endl;
        Dog *ptrDog = new Dog();
        cout << "manual call for deletion:"; delete ptrDog;// dynamic raw pointer must be released manually.
        cout << "going out of scope. memory already released.-" << endl;
    }
    cout << endl << endl;

    {
        cout << "static raw pointer on a Dog:" << endl;
        Dog ptrDog = Dog();
        cout << "going out of scope. auto release, pointer + object:" << endl;
    }// Notice that static raw memory is released automatically, it's handled by the system.
    cout << endl << endl;

/// 2 - modern smart pointers.
    {
        cout << "unique_ptr pointer on a Dog:" << endl;
        unique_ptr<Dog> myptrDog(new Dog());
        cout << "going out of scope. auto release, pointer + object:" << endl;
    }
    cout << endl << endl;

    {
        cout << "shared_ptr pointers on a Dog:" << endl;
        shared_ptr<Dog> myptrDog(new Dog());
        shared_ptr<Dog> myptr2Dog = myptrDog; // second pointer on same object
        cout << "going out of scope. auto release, 2 pointers + 1 objet:" << endl;
    }
    cout << endl << endl;

/// 3 - creation of an object with special constructors.
    {
        cout << "use of copy constructor:" << endl;
        Dog *ptrDog = new Dog(); // first dog, dynamic raw
        Dog ptr2Dog = Dog(); // second dog created using copy constructor, = operator
        cout << "going out of scope." << endl;
        delete ptrDog; // We must delete the dynamic raw dog 1 manually.
    }// the second static pointer to second dog handles deletion automatically. static call destructor, delete in it.
    cout << endl << endl;

    {
        cout << "use of move constructor:" << endl;
        vector <Dog> dogContainer;
        dogContainer.push_back(Dog());// Because we used the move constructor, our object was only created once. No copy during the push_back.
        cout << "going out of scope." << endl;
    }

  return 0;
}
