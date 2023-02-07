#include <iostream>
#include <vector>
#include <list>
using namespace std;


/* This file demonstrates usage for the two most common STL containers, vectors and lists.
While they can be used in a similar fashion ,they are implemted completely differently.
At the end of the file, I explain in what cases you should use one, or another. */

int main(){

    /// 1 -  vectors, most basic usage

    vector<int>v1;
    v1.push_back(5);//manual insertion.
    v1.push_back(7);
    v1.push_back(12);
    for (int i = 0; i < v1.size();i++)//display with manually declared iterator.
        cout << v1.at(i) << ",";
    cout << endl << "end vector 1." << endl << endl;

    vector<float>v2 = {5.33,4.5,8.89}; // init with multiple values.
    cout << v2.size(); // current vector size.
    v2.pop_back(); // remove last element.
    for (auto& iter : v2) // display with auto iterator.
        cout << iter << ",";
    cout << endl << "end vector 2." << endl << endl;

    vector<int>v3 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int>::iterator someIt= v3.begin()+4;//create an iterator with specific position that it not the beginning of the vector.
    v3.insert(someIt,5,9); //multiple insertion of 5 X 9 (9,9,9,9,9 or 5 times 9)
    for (auto iter = v3.begin();iter != v3.end(); iter++)
        cout << *iter <<";";
    cout << endl << "end vector 3." << endl <<  endl;

    /// 2 - lists, same basic usage. Note that this is basically the same code. STL containers are normalized.

    list<int>l1;
    l1.push_back(5);//manual insertion.
    l1.push_back(7);
    l1.push_back(12);
    for (int iter : l1)//display with manually declared iterator.
        cout << iter << ",";
    cout << endl << "end list 1." << endl << endl;

    vector<float>l2 = {5.33,4.5,8.89}; // init with multiple values.
    cout << l2.size(); // current list size.
    l2.pop_back(); // remove last element.
    for (auto& iter : l2) // display with auto iterator.
        cout << iter << ",";

    cout << endl << "end list 2." << endl << endl;

    vector<int>l3 = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
    vector<int>::iterator listIterator= l3.begin()+4;//create an iterator with specific position that it not the beginning of the vector.
    l3.insert(listIterator,5,9); //multiple insertion of 5 X 9 (9,9,9,9,9 or 5 times 9)
    for (auto iter = l3.begin();iter != l3.end(); iter++)
        cout << *iter <<";";
    cout << endl << "end vector 3." << endl <<  endl;


    /// 3 - vectors vs lists : so when should I use one, or another ?
        /*
        Because of each container's implementation :

        - Insertion and deletion of an element is slow in a vector, and much faster in than in a list.
        - Random access of an element is possible in a vector, and impossible in a list.
         -vectors have access to useful tools like sort, unlike lists.

        In other terms, if you need random access/ don't plan to read the container non sequentially, use a vector.
        If if don't need random access, select based on speed depending on your need.
        */
}
