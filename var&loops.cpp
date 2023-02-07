using namespace std;
#include <string>
#include <iostream>

/// - A very basic introduction to loops, variables, and a few important keywords in C++ -


/* this is a global variable. It's declared outside of a scope. It's not considered good practice
to use global variables in C++, as everything must be properly encapsulated*. This can however be
of use in C.
*: encapsulation is an OOP(object oriented) concept. Check out dedicaced sections about that. */
int bananas = 12;


int main(){

{ // this is a scope.
    /* variables declared  during a scope will be deallocated when the scope ends.
    In C and C++, always everything is always coded within a function (or method),
    and those always have a starting and finishing scope.  */
} // this is the end of a scope.


/// a few basic variables

// stores whole numbers
int apples = 5;
apples++;// add one to the variable.
// stores a single character
char letter = 'a';
// stores a floating number
float percentage = 93.6;
// stores a chain of characters. Remember to #include <string>.
string word = "Hello reader";
// true or false
bool doorOpen = true;
// const declaration makes this variable constant.
const int pears = 12; // you must declare its value on initialization.
// variables that can't be negative
unsigned int peaches = 2;
bananas = bananas + 12; // adding 12 more apples. 24 in total.

{
    int strawberries = 2;
} // The strawberries variable is deallocated at the end of this scope.

// write a message to the console. don't forget to #include <iostream>
cout << "Hello." << endl;

/// conditions
// if condition
if (apples > 4)
    cout << "I have more than 4 apples."<< endl;
// multiple condition with AND (&&), OR (||)
if ((apples > 5 && pears > 1) ||  (apples > 1 && pears > 5))
    cout << "I will make a pie with a lot of apples and a pear, or a pie with a lot of pears and an apple."<< endl;
// condition loop while
while (apples > 0)
{
    cout << "eating one apple,"<< endl;
    apples--;
}
apples = 5;
// variant of while
do {
    cout << "eating another apple,"<< endl;
    apples--;
} while (apples > 0); // the difference is that the condition is checked at the end of the loop
// range loop, with a starting and finishing position.
for (int i = 5; i != 9; i++) // loop from 5 to 9, 4 times
{
    cout << "eating a peach,"<< peaches << " remaining"<< endl << endl;;
    peaches--; // peaches is unsigned, so when it's decremented under 0 it becomes int's max value.
}

/// behavior at the end of loops. Compare the small differences :
// The condition must be read as "The loop continues as long as i not equal to 100.
// if CONDITION, CONTINUE / if NOT CONDITION, BREAK.
// When i reaches 100, the loop breaks, so the last cout is 99.
for (int i = 1; i != 100; i++)// 1 to 99
    cout << i << ",";
cout << endl << endl;
for (int i = 1; i < 100; i++)// 1 to 99
    cout << i << ",";
cout << endl << endl;
for (int i = 1; i <= 100; i++)// 1 to 100
    cout << i << ",";
cout << endl << endl;
for (unsigned int i = 100; i > 0; i--)// 100 to 1
    cout << i << ",";
cout << endl << endl;
/*for (unsigned int i = 100; i >= 0; i--)// infinite. Put in comments to not saturate console.
    cout << i << ",";*/


}// the program terminates at the end of main().

