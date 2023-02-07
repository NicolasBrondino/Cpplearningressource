#include <iostream>
#include <memory>

using namespace std;


/*                                - std:move, and move semantics -
- What is moving ?

Let's imagine that we have class that generate a very large object, in matter of memory size.
We have instanciated one of these object. We are applying the design patern "singleton", which means
that we have designed our class so only one object can be instanciated, righly because the size of this
object could be a problem. Let's say it takes most of our workstation memory.
You are in a situation where you need to take control of this object and modify it, but there is a unique
pointer already on it, and you can't make copies of this object.
This is one of many examples of the uses of std:move. Instead of making a copy then deleting the source,
std:move takes care of switching ownership between pointers. No copy is made, thus avoiding a very costly
operation.
An object too big is just one case scenario, but as a good programming practice there are a lot of cases
where avoiding an unecessary copy leads to time and size optimization of our process.

std:move is already implemented for standard data structures.

For your own classes, it is possible to implement your own move operation, as an overload of the move operator.
&& means rValue or "temp object".

*/

// a mockup class used in the examples below.
class robot{
private:
    int parts;
public:
    robot(int p){
        cout << "creating robot." << endl;
        parts = p;
    }
    ~robot(){cout << "destroying robot." << endl;}
    shout(){cout <<" robot says: I have "<<parts<<" parts."<<endl;}


};

int main(){

    /// 1 - using move from the STL to move ownership of an object between 2 unique pointers, without making a copy.
    {
        // creating object using unique pointer.
        unique_ptr<robot> myPtr(new robot(5));
        myPtr->shout();
        unique_ptr<robot> myPtr2 = move(myPtr);
        myPtr2->shout();
        //myPtr->shout();//error,myPtr, the first pointer, has been freed. Object is accessed through myPtr2.
        cout << "going out of scope, releasing our last unique pointer and object." << endl << endl;
    }


}
