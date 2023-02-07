#include <iostream>
#include <string>
using namespace std;

/* operator overload example. */

// our mockup class, for a fictional water tank.
class tank{
private:
    float capacity;
    float maxCapacity; // water : current / max
    string name;
public:
    tank(float cap,string myName){
        maxCapacity = cap;
        capacity = 0;
        name = myName;
        cout << "creating an empty " << name << ", with a " << maxCapacity << " liters capacity.\n";
    }
    ~tank(){
        cout << "deleting " << name << ".\n";
    }
    showTank(){
        cout << name << " stats: " << capacity << "/" << maxCapacity << " liters.\n";
    }

        /// operator + ////////////////////////////////////////////////////////////
        /* As we overload our + operator for a "water tank", we must think carefully about
        the meaning of "adding" two "water tanks" together. Unlike adding two theorical numbers,
        there are some behaviors that must be decided by the programmer.
        I decide, in this mockup example, that :
        - I will make two overloads, one for adding unsourced water, and another, to fill from another tank.
        - the second tank should be emptied in the first.
        - If there is too much water in the second tank, the first can only be filled to capacity.
        - Depending on the case scenario, none or only a part of the water should remain in the second tank.
        I could implement this in one operator+, but in fact I'm looking for an excuse to show
        a multiple-cases-multiple-examples scenario. */


        // first version
        operator + (float content){

            // check for impossible case : can't insert negative values
            if (content < 0)
                return -1; // error code for negative values.

            // filling the tank, to max capacity if possible.
            if (capacity + content > maxCapacity)
                capacity = maxCapacity;
            else
                capacity = content;

            return 1; // code for operation ok.
        }

        //second version
        operator + (tank &toCollect){
            // filling the tank, to max capacity if possible.
            if (capacity + toCollect.capacity > maxCapacity)
            {
                float temp = capacity;
                capacity = maxCapacity; // fill tank 1 to max
                toCollect.capacity = toCollect.capacity - temp; // removing displaced water from tank 2

            }
            else
            {
                capacity = capacity + toCollect.capacity;
                toCollect.capacity = 0;
            }
            return 1; // code for operation ok.
        }

        /* side note : In a similar fashion, operators -,*,/,=,and &&(move) can be overloaded. */

};

int main(){
/// demo operator +, written to add an int to our tank object.
tank firstTank(50,"tank-A"); // creating a tank with a 50 liters capacity. tank is empty.
firstTank.showTank();
firstTank + 23.4; // adding 23 liters to tank a.
firstTank.showTank();
cout << endl << endl;

/// demo other operator +, written to add a tank object to our tank object.
tank secondTank(12.5,"tank-B"); // an empty 12.5 liters tank
secondTank + 7.5; // adding 7.5 liters to second tank.

firstTank.showTank();
secondTank.showTank();
firstTank + secondTank; // moving tank 2's content to tank 1.
firstTank.showTank();
secondTank.showTank();

cout << endl <<  endl << "going out of scope, deleting objets:\n";
}
