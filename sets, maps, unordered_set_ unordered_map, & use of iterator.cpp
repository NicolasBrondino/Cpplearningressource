#include <iostream>
#include <string>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
using namespace std;


/* this file example is about other common STL containers, map, set, unordered_map, and unordered_set. */



int main() {


/// part 1 - ordered maps and sets.

map<string,int> myDict = {{"Georges",23},{"Manual",27},{"Bob",42},{"Edward",36},{"Allison",43}};

// version with auto iterator
for (auto in= myDict.begin(); in != myDict.end(); in++)
    cout << in->first << ":" << in->second << " ";
cout << endl;

// version with manual declaration of iterator
map<string,int>::iterator in;
for (in= myDict.begin(); in != myDict.end(); in++)
    cout << in->first << ":" << in->second << " ";
cout << endl;

/// part 2 - Usage of ordered and unordered versions.

    // sets and unordered sets are collections of elements of one type.
    //sets are binary trees with log n and unordered are hash tables with 1 to log n complexity.
    set<int> mySet = { 97,98,98,99 };
    // unordered_set are mostly used because usually faster. sets take less memory.
    unordered_set<int> myUnordSet = { 97,98,98,99 };
    map<string, int> myMap = { {"A",23}, {"B",17}, {"C",38}, {"D",99} };
    unordered_map<string, int> myUnordMap = { {"A",23}, {"B",17}, {"C",38}, {"D",99} };


    for (auto& it : mySet)
        cout << it << ",";
    cout << endl << endl;

    for (auto& it : myUnordSet)
        cout << it << ",";
    cout << endl << endl;

    for (auto& it : myMap)
        cout << it.first << ":" << it.second << ",";
    cout << endl << endl;

    for (auto& it : myUnordMap)
        cout << it.first << ":" << it.second << ",";
    cout << endl << endl;

    // this works on maps, but not unordered maps. not checked on set,
    // memorize auto& it instead which works everywhere.
    map<string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++)
        cout << it->first << ":" << it->second << ",";
    cout << endl << endl;

    /// 3 - A quick word about when to use what

    /*

    - Sets are for one type of data only.
    - Maps are by definition a "dictionary" container, linking a type to another type ("Robert",27) if we want a tuple list of names + ages.
    - Ordered and unordered depends on your design. If you search the container, take an ordered version.
    - Unordered versions are faster to write, ordered versions take up more memory space.

    and now more details about their implementation :


    binary search trees vvv
    [set] and [map] : ordered, (O(n)->slower at use than unordered), use less memory than unordered.
    if you need an ordered container or need to use less memory.

    [Unordered set and map]: not sorted, O(1 to n)-> faster than ordered, use more memory.
    if you need a hash table, need faster access, or don't care about the fact that it's ordered.


    */


}
