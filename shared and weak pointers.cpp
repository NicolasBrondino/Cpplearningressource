#include <iostream>
#include <memory>
using namespace std;

/* shared pointers.
- multiple pointers can point to one object.
- each pointer releases when out of scope.
- when the last pointer is released, the object itself is released. */

/* Weak pointers are impleted in a similar way as shared pointers,
but they cannot take ownership of the object. They are observation
pointers only. Not demonstrated here. */


// some example class.
class car{
private:
    int maxSpeed;
public:
    car(int mSpeed){
        maxSpeed = mSpeed;
        cout << "creating car.\n";
    }
    ~car(){
        cout << "\ndestructing car.\n";
    }
    showSpeed(){
        cout << "max speed:" << maxSpeed;
    }
};


int main(){

    /// example 1 - shared pointers on an int
    {
        shared_ptr<int> shared1(new int(42));
        shared_ptr<int> shared2 = shared1;
        cout << "content from both shared pointers, targeting same area of memory:"
        << *shared1 << " " << *shared2 << "\n";
    } // reaching end of scope: releasing one shared to int pointer, then another, and when last one is released, releasing the int.
    cout << endl << endl;


    /// example 2 - shared pointers on an object.
    {
        shared_ptr<car> sharedCar(new car(227));
        shared_ptr<car> sharedCar2 = sharedCar; // we now have two shared pointers, pointing on one object.
        cout << "max speed of object read from first pointer:";
        sharedCar->showSpeed();
        cout << "\nmax speed of object read from second pointer:";
        sharedCar2->showSpeed();
        cout<<endl;
        cout << "end of scope, releasing memory. No message for the shared int, however for the shared car:";



        /* A word about the destruction of the shared pointers :
        - When each shared pointer reaches out of scope, it is released. (here, 2 shared_pointers.)
        - There is a counter in the shared_pointer implementation that allows it to keep track of how many shared_pointers
        are currently owning that object.
        - When the last shared_pointer is released, the object itself is released.
        (So in that particular case, when reaching "out of scope", one shared pointer will be released, then another,
        then the car object itself.) */

    } // "out of scope"
    cout << endl << endl;

}
