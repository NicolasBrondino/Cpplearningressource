#include <iostream>
#include <thread>
using namespace std;

/* multithread via std::thread requires a compatible C++ compiler. If compilation fails, use Microsoft VCC. It's free. */

// a very simple function that prints number from 1 to 99 in the console.
void countTo99(int startAt) {
    for (int i = 1 + startAt; i <= 99 + startAt; i++) {
        cout << i << ",";
    }
    cout << "end.";
}

int main()
{
    /// multithread with join : finish all join threads before continuing main.
    std::cout << "\n";
    std::thread thread1(countTo99, 100);// The "hundreds" will be used as a visual cue here,
    std::thread thread2(countTo99, 200);// example: 2xx = thread2 is working.
    std::thread thread3(countTo99, 300);//Run this program multiple times. The order in which
    std::thread thread4(countTo99, 400);// the threads run should differ.
    thread1.join();
    thread2.join();
    thread3.join();
    thread4.join();
    std::cout << endl << "all threads finished working." << endl << endl;

    /// multithread with detach : lauching the thread in parallel to main.
    std::thread(countTo99, 1000).detach();//thread5 calls will be over 1001-1100.
    //meanwhile, running some random stuff in main.
    // I now run a lot of stuff in main, because thread5 will be interrupted if main is finished before.
    for (int i = 0; i <= 5; i++)
        countTo99(0); // main calls will be 1-100.
    cout << endl << endl;



} //reminder that if main finishes before a detached thread, the detached thread(s) will be interrupted.
