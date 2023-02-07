
#include <iostream>
using namespace std;

int main(){

    /// examples of : using raw pointer


    /// Example 1 : a simple raw pointer on an int. /////////////////////////////////////////////////////////////////////////////////////////
    {
        // new int pointer allocated, empty
        int *nbSauces = new int();
        // giving that value to memory area
        *nbSauces = 16;
        // showing stored value
        cout << "nb sauces in restaurant:" << *nbSauces << "\n\n";

        // manual pointer deletion, always.
        delete nbSauces; // deleting/freeing pointer and an int
    } // memory (pointer and value, int)not released automatically when going out of scope. check if dynamic memory is freed.

    /// Example 2 : a pointer on an array of ints. /////////////////////////////////////////////////////////////////////////////////////////
    {
        // allocate 10 ints. values are not initialized.
        int *studentAges = new int[10];
        // put a value in the first int.
        studentAges[0] = 15;
        // show values in 10 ints. All but first are gibberish.
        for (int i = 0; i <= 9; i++)
            cout << "age of student:" << studentAges[i] << "\n";
        cout << endl;

        //manual pointer deletion, as always.
        delete []studentAges; // deleting/freeing pointer and 10 ints
    } // memory (pointer and values, 10 ints) not released automatically when going out of scope. check if dynamic memory is freed.

    /// Example 3 : pointer to existing static value /////////////////////////////////////////////////////////////////////////////////////////
    {
        // making a pointer, pointing on a static int.
        int *adrAge = new int();

        int age = 18;
        //Our pointer, which is an adress,  will take a static variable's adress
        adrAge = &age; /// our pointer points to a static variable. No dynamic int allocated.
        // checking pointer, reference, and our original static variable.
        cout << "adress of pointer: " << adrAge
        << ", value in age: " << age
        << ", pointer target this content: " << *adrAge << "\n";
        //changing value in original variable
        age = 99;
        cout << "adress of pointer: " << adrAge
        << ", value in age: " << age
        << ", pointer target this content: " << *adrAge << "\n";

        // manual pointer deletion, always.
        delete adrAge; // deleting pointer. it pointed to a static variable (age). Age is going to be freed automatically.
    } // memory (pointer) not released automatically when going out of scope. check if dynamic memory is freed.
}
