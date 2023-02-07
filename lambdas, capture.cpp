#include <iostream>
using namespace std;

int main(){

// Lambdas, and conditional operator. I'm demonstrating these together as I like to see both as "micro functions".

///1- the conditional operator
int a = 5; int b = 10;
cout << "smallest of two ints is:" << (a<b?a:b) << endl << endl; //(ifConditionTrue?Dothis:ElseDOThat)

///2- simple lambdas, no capture

//making talking lambda
auto hi = []() {cout << "Hello!" << endl;};
// call lambda function
hi();
// making lambda which adds 2 numbers
auto sum = [](int a, int b){return a + b;}; /// important: output must be auto.
// call sum lambda function
cout << " 3 + 5 = " << sum(3,5)<< endl << endl;


///3- lambda with capture : [] grab parameters, &, =

// Lambdas are "isolated" from the scope they are written in. They cannot access variables in that scope.
int apples = 25;
//auto how_many_apples = [](int p = apples){cout << "I have " << apples << " apples.";};//impossible to use that local variable.

// Capture allows usage of local variables.
auto how_many_apples = [apples](){cout << "I have " << apples << " apples." << endl;};// read the variale successfully.
how_many_apples();

//Now let's say I want to modify my variable, not just read it. Let's call it by reference.
auto eat_one_apple = [&apples](){apples--;cout << "I have " << apples << " apples left." << endl;};
eat_one_apple();

// you can insert multiple parameters with the capture brackets : [apples,&pears,clementines,&bananas]
// However, there is a way to simply add all variables from the scope in the capture.

int pears = 10;
int clementines = 14;
int bananas = 16;

// The = will include all local variables, by value (non modifiable).
auto how_many_fruits = [=](){cout << "I have " << apples + pears + clementines + bananas << " fruits." << endl;};
how_many_fruits();

// the & will include all local variables, by reference (modifiable inside the lambda).
auto eat_a_lot_of_fruits = [&](){apples -= 3; clementines -=6; bananas -= 7;
                                 cout << "I have " << apples + pears + clementines + bananas << " fruits." << endl;};
eat_a_lot_of_fruits();


}
