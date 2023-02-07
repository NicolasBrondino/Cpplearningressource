#include <iostream>
using namespace std;

/* Exceptions are used to try and detect errors in your code. They are one of many debug techniques.
 They should be used carefully, as they can slow down the code, and make it bloated to read.
 Other code testing techniques include break and debug, test units (For example, googleTest), paired programming,
 and manual team testing. In production, it is common to have your code read and tested by
 some or all of your team members. */

// this function will try to divide by 0. We are going to catch that error.
void testError1(){
    try{
        int test = 0;
        for (int i = -100; i <= 100; i++){
            // checking for errors cases, throwing if error case found
            if (i == 0)
                throw ("error, div by 0");

            // rest of the code, normal operation
            cout << i << " ";
            int j = test / i;
        }
    }catch(const char* msg){// catching errors if any
    cout << msg;
    }
}


int main(){

testError1();

/* In this simple example, a const char* msg is thrown. It is possible to create your
own class of errors by inheriting from std::exception or std::runtime_error. */


}
