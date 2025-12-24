#include <iostream>
#include "IntList.h"
using namespace std;

//nitializes an empty list with dummy head and dummy tail.
    IntList::IntList(){
        this->head = nullptr;
        this->tail = nullptr;
    }
//Deallocates all remaining dynamically allocated memory (all remaining IntNodes).
    IntList::~IntList(){
        while (!empty()){
            pop_front();
        }
    }
//Inserts a data value (within a new node) at the front end of the list. 
//This must be an O(1) operation.
    void IntList::push_front(int value){
        IntNode* temp = new IntNode(value);
        temp->next = this->head;
        if(this->tail == nullptr){
            this->tail = temp;
            temp->prev = nullptr;
        }
        else{
            temp->prev = this->head->prev;
            this->head->prev = temp;
        }
        this->head = temp;
    }
//Removes the node at the front end of the list (the node after the dummy head). 
//Does nothing if the list is already empty. This must be an O(1) operation.
    void IntList::pop_front(){
        //if 0 element, just exit the function
        if (empty()){
            return;
        }
        IntNode* temp = head;
        head = head->next;
        delete temp;
        //if vector only has one element, then tail == nullptr
        if (head == nullptr){
            tail = nullptr;
        }
    }
//Inserts a data value (within a new node) at the back end of the list. 
//This must be an O(1) operation.
    void IntList::push_back(int value){
        IntNode* newNode = new IntNode(value);
        if (empty()){
            head = newNode;
        }
        else{
            tail->next = newNode;
        }
        tail = newNode;
        return;
    }
//Removes the node at the back end of the list (the node before the dummy tail). 
//Does nothing if the list is already empty. This must be an O(1) operation.
    void IntList::pop_back(){
        IntNode* curTail = tail;
        IntNode* prevTail = head;
        if (empty()){
            return;
        }
        //one element
        else if (head->data == tail->data){
            head = nullptr;
            tail = nullptr;
            delete curTail;
        }
        else{
            while (prevTail->next != tail){
                prevTail = prevTail->next;
            }
            prevTail->next = nullptr;
            tail = prevTail;
            delete curTail;
        }
        return;
    }
//Returns true if the list does not store any data values 
//(it only has dummy head and dummy tail), otherwise returns false.
    bool IntList::empty() const{
        if (head != nullptr){
            return false;
        }
        return true;
    }
//A global friend function that outputs to the stream all of the integer values 
//within the list on a single line, each separated by a space. 
//This function does NOT send to the stream a newline or space at the end.
    ostream & operator<<(ostream &out, const IntList &rhs){
        IntNode * currNode = rhs.head;
        if (rhs.empty()){
            return out;
        }
        else{
            ////output the data of the current node
            out << currNode->data;
            //if the next node is NOT empty
            while (currNode->next != nullptr){
                ////go to the next node
                currNode = currNode->next;
                //output the value of the node w/ a space in between
                out << ' ' << currNode->data;
            }
            return out;
        }
    }
//prints to a single line all of the int values stored in the list in REVERSE order, 
//each separated by a space. This function does NOT output a newline or space at the end.
    void IntList::printReverse() const{
        if (empty()){
            return;
        }
        else{
            IntNode* curTail = tail;
            //Traverse
            while (curTail != nullptr){
                if (curTail->prev != nullptr){
                    cout << curTail->data << " ";
                }
                else{
                    cout << curTail->data;
                }
                curTail = curTail->prev;
            }
            
            return;
        }
        
    }