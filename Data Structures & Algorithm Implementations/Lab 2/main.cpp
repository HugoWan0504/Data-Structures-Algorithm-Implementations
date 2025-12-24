#include <iostream>
#include "IntList.h"
using namespace std;

int main(){
    cout << "Begin testing." << endl << endl;
    int test;
    cout << "Enter test number: " << endl;
    cin >> test;
    cout << endl << endl;
    if (test == 1){
        //Testing push_front function
        cout << "list1 constructor called" << endl;
        IntList list1;
        cout << "pushfront 1" << endl;
        list1.push_front(1);
        cout << "pushfront 2" << endl;
        list1.push_front(2);
        cout << "pushfront 3" << endl;
        list1.push_front(3);
        cout << "list1: " << list1 << endl;

        //Testing pop_front function
        cout << "popf" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "popf" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
        cout << "popf" << endl;
        list1.pop_front();
        cout << "list1: " << list1 << endl;
    }
    if (test == 1) {
        //Testing ~IntList function
        cout << "list1 destructor called" << endl;
    }

    if (test == 2) {
       cout << "list2 constructor called" << endl;
       IntList list2;

       //Testing push_back function
       cout << "pushback 1" << endl;
       list2.push_back(1);
       cout << "pushback 2" << endl;
       list2.push_back(2);
       cout << "pushback 3" << endl;
       list2.push_back(3);
       cout << "list2: " << list2 << endl;

       //reset to empty list
       cout << "popb" << endl;
       list2.pop_back();
       cout << "list2: " << list2 << endl;
       cout << "popb" << endl;
       list2.pop_back();
       cout << "list2: " << list2 << endl;
       cout << "popb" << endl;
       list2.pop_back();
       cout << "list2: " << list2 << endl;
    }
    if (test == 2) {
       cout << "list2 destructor called" << endl;
    }
    
    //Testing empty() function)
    if (test == 3){
        cout << "list3 constructor called" << endl;
        IntList list3;
        bool result = list3.empty();
        //list3 an empty list, result should return true
        if (result == true){
            cout << "List3 is an empty list." << endl;
        }
        else{
            cout << "List3 is NOT an empty list." << endl;
        }

        //add one element, result should return false
        cout << "pushback 1" << endl;
        list3.push_back(1);
        result = list3.empty();
        if (result == true){
            cout << "List3 is an empty list." << endl;
        }
        else{
            cout << "List3 is NOT an empty list." << endl;
        }

        //remove the only element, result should return true
        cout << "pop" << endl;
        list3.pop_front();
        result = list3.empty();
        if (result == true){
            cout << "List3 is an empty list." << endl;
        }
        else{
            cout << "List3 is NOT an empty list." << endl;
        }
    }
    if (test == 3) {
       cout << "list3 destructor called" << endl;
    }

    if (test == 4){
        cout << "list4 constructor called" << endl;
        IntList list4;

        //Testing push_back function
        cout << "pushback 1" << endl;
        list4.push_back(1);
        cout << "pushback 2" << endl;
        list4.push_back(2);
        cout << "pushback 3" << endl;
        list4.push_back(3);
        cout << "list4: " << list4 << endl;

        //Testing printReverse function
        cout << "List 4's reverse list: ";
        list4.printReverse();
    }
    if (test == 4) {
       cout << endl << "list4 destructor called" << endl;
    }

    cout << endl << "End Testing." << endl;

    return 0;
}