#include <iostream>
#include <memory>
using namespace std;

/* unique pointers.
- The most common modern pointer, default replacement for raw pointers.
- Can only point to one object.
- automatic memory release at the end of the scope.
- ownership of the object can be transmitted to another unique pointer using std::move.
  The first unique pointer will lose ownership of the object.*/

// a pretend class with basic functions.
class fruit{
private:
    unsigned int seeds;
public:
    fruit(int s){
        seeds = s;
        cout << "created fruit with:" << s << " seeds." << endl;
    }
    ~fruit(){cout << "destroying fruit." << endl;}
    showSeeds(){cout << "seed quantity:" << seeds <<endl;}
};

int main(){

/// example 1 : unique pointer on an int.
{
    unique_ptr<int> myPtr(new int());
    *myPtr = 6;
    cout <<  "value in the memory: " << *myPtr << endl << endl;
} // automatic deletion of myPtr at the end of scope.

/// example 2 : unique pointer on an object.
{ //This is just used to demo destruction when out of scope.
    unique_ptr<fruit> uniq1(new fruit(46));
    uniq1->showSeeds();
    // giving control to another unique pointer with move
    unique_ptr<fruit> uniq2 = std::move(uniq1); // this renders the uniq1 pointer null, now uniq2, a new unique pointer, points to our memory area.
    uniq2->showSeeds();
    //uniq1->showSeeds(); //this will give an error message, because uniq1 is now null.
    cout << "going out of scope."
         << " automatic release of memory for our memory held by uniq2, as well as the uniq2 pointer." << endl << endl;
}


/// In comparison, dynamic raw memory must be deleted manually.
{
    fruit *b = new fruit(46);//notice that fruit is created (see console),
    // but fruit isn't released automaically,
    delete b; // So memory must be deleted manually with delete.
}

}
