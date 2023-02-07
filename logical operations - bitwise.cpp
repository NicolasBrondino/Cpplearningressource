#include <iostream>
#include <bitset>// A great to to visualize binary number in readable form. Use bitset<8>(val) to limit zeros.
using namespace std;

/* Here are the basic logic operations in code form.
Complex operations are usually a combination of those simpler operations. */

int main() {
    // a = 5(00000101), b = 9(00001001)
    int a = 5, b = 9;

    // binary AND: The result is 00000001
    cout << "a = " << a << ":" << bitset<8>(a) << "," << " b = " << b << ":" << bitset<8>(b) << endl;
    cout << "a & b = " << (a & b) << ":" << bitset<8>(a & b) << endl << endl;

    // binary OR: The result is 00001101
    cout << "a | b = " << (a | b) << ":" << bitset<8>(a | b) << endl << endl;

    // binary EXCLUSIVE OR: The result is 00001100
    cout << "a ^ b = " << (a ^ b) << ":" << bitset<8>(a ^ b) << endl << endl;

    // binary NOT: The result is 11111010
    cout << "~a = " << (~a) << ":" << bitset<8>(~a) << endl << endl;

    // binary SHIFT LEFT: The result is 00010010
    cout << "b << 1" << " = " << (b << 1) << ":" << bitset<8>(b << 1) << endl << endl;

    // binary SHIFT RIGHT: The result is 00000100
    cout << "b >> 1 " << "= " << (b >> 1) << ":" << bitset<8>(b >> 1) << endl << endl;

    // make a series of 0 or 1:
    cout << bitset<8>(0) << endl;
    cout << bitset<8>(~0) << endl;

    // make a mask at bit 5:
    cout << bitset<8>(~(1<<4)) << endl;
    return 0;
}
