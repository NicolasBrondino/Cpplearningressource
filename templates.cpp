#include <iostream>
using namespace std;

 /*Twice the same example, this is a template method designed to multiply a number by 2.
 It is designed to be used on simple number types (int, float, double).*/

// A template class that multiply a number of type "numberType" by 2.
template <typename numberType> numberType multi2A(numberType A){
    return A*2;
}

/* You can use the keywords "typename" or "class", without difference.
Both were kept in the Cpp implementation, both to satisfy user preference. */
template <class numberType> numberType multi2B(numberType A){
    return A*2;
}

// Another template class example, with two input types. Will return the biggest number.
template <class myType> myType getMax(myType a, myType b){
    if (a < b)
        return b;
    else
        return a;
}

int main(){

cout<< "example 1, with both keywords:\n";
cout << multi2A((int) 3) << "\n"; // using the template with an int.
cout << multi2A((float) 2.44) << "\n"; // using the template with a float.
cout << multi2B(4.12) << "\n"; // using the keywords numbertype without any difference.

cout<< "example 2, 2 input types:\n";
int a = 5; int b = 7;
float c = 9.99; float d = 12.99;
cout << getMax (a,b) << "\n"; // using second template with ints.
cout << getMax (c,d) << "\n"; // using second template with floats.

}
