#include <iostream>
using namespace std;

// A basic recursive example. if sum = 5, final return will be 5 + 4 + 3 + 2 + 1.
int sumValues(int sum){
if (sum == 1)
    return 1;
return sum + sumValues(sum - 1); // adding incremental result to its own call.
}

/* tail recursivity :
The deeper a typical recursive call, the larger the size of the stack.
Optimizing your recursive function by implementing tail recursivity allows to never saturate the stack.
This is done by passing the temp result as a parameter.
While tail recursivity is compatible with C++, it doesn't work in python, and with some javascript compilers.
*/

// Same function, but with tail recursivity.
int sumValuesTail(int maxSum, int currentSum = 0) {
    if (maxSum == 0) {
        return currentSum;
    } else {
        return sumValuesTail(maxSum - 1, currentSum + maxSum); // There are no computations outside its own call.
    }
}

int main(){
int testValue = 5;
// our example, without tail recursion. sum of numbers between 1 and 5.
cout << "sum of numbers between 1 and " << testValue << " : " << sumValues(testValue) << endl << endl;
// second function with similar result, this time with tail recursion.
cout << "sum of numbers between 1 and " << testValue << " : " << sumValuesTail(testValue) << endl << endl;

}
