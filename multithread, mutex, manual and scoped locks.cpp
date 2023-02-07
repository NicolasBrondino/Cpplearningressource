#include <iostream>
#include <thread>
#include <mutex>
#include <string>
//Ctrl + J (in visual studio) to call the suggestion menu: try #include<(ctrl+J)>
using namespace std;

/* - multithread via std::thread requires a compatible C++ compiler. If compilation fails, use Microsoft VCC. It's free. 
   - Remember when running multithread examples to test them multiple times, as output may differ. */

// a simple method for example 1 that show odd numbers from 0 to 100
void showOddsUntil(string threadTag) {
    for (int i = 0; i <= 100; i++) {
        if (i % 2 == 0) // I can never remember the difference between even and odd.
            cout << threadTag << i << " ";
    }
    cout << "[" << threadTag <<" has finished working.]";
}

// a global variable that will be used as a lock, in the two last examples.
int globalCount = 0;
mutex myMutex;

// a simple method for example2 that shows increments from 1 to 100. lock is method scoped.
void increaseCount_scopeLock(string tag) {
    lock_guard<mutex>guard(myMutex);// multithread2: scope wise lock
    //myMutex.lock();// multithread3: manual lock to protect globalCount
    for (int i = 1; i <= 100; i++) {
        globalCount++;
        cout << tag << globalCount << " ";
    }
    cout << "[Thread " << tag << " finished 100 increments.]";
    //myMutex.unlock(); // multithread3: manual unlock
}

// variant of previous method, for example 3. lock is manually activated.
void increaseCount_manualLock(string tag) {
    myMutex.lock();
    for (int i = 1; i <= 100; i++) {
        globalCount++;
        cout << tag << globalCount << " ";
    }
    cout << endl << "[Thread " << tag << " finished 100 increments. releasing mutex for another thread.]" << endl;
    myMutex.unlock();
}

int main()
{
    std::cout << "example 1 - 4 threads show odd numbers, without lock." << endl << endl;
    // All of our threads will show odd numbers, while sharing priority.
    // Here we use the letters A B C D to show which thread is currently working.
    std::thread t1(showOddsUntil, "A:");
    std::thread t2(showOddsUntil, "B:");
    std::thread t3(showOddsUntil, "C:");
    std::thread t4(showOddsUntil, "D:");
    t1.join();
    t2.join();
    t3.join();
    t4.join();

    cout << endl << endl << "example 2 - 4 threads with a method scoped lock." << endl << endl;
    // Here, our threads are sharing a lock, placed on a global variable.
    // In that example, each thread is going to increment our global variables a hundred times,
    // given we have 4 threads, the global variable should reach 400 in the end.
    // We can see which thread is currently having control and doing the incrementing,
    // with the letters E F G H.
    thread t5(increaseCount_scopeLock, "E:");
    thread t6(increaseCount_scopeLock, "F:");
    thread t7(increaseCount_scopeLock, "G:");
    thread t8(increaseCount_scopeLock, "H:");
    t5.join();
    t6.join();
    t7.join();
    t8.join();

    globalCount = 0;// reset counter for next example.
    cout << endl << endl << "example 3 - 4 threads with manual on / off locking." << endl << endl;
    thread t9(increaseCount_scopeLock, "I:");
    thread t10(increaseCount_scopeLock, "J:");
    thread t11(increaseCount_scopeLock, "K:");
    thread t12(increaseCount_scopeLock, "L:");
    t9.join();
    t10.join();
    t11.join();
    t12.join();
}

