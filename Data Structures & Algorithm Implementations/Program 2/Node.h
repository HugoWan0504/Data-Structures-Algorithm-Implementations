#ifndef _Node_H__
#define _Node_H__

#include <iostream>
#include <string>
using namespace std;

class Node {
    public:
        Node *leftchild;
        Node *rightchild;
        Node();
        Node(int ct, string dt);

    private:
        int count;
        string data;

    public:
        void setdata(string dataSet){
            data = dataSet;
        }
        void setcount(int countSet){
            count = countSet;
        }
        string getdata(){
            return data;
        }
        int getcount(){
            return count;
        }
        void countIncrease(){
            count++;
        }
        void countDecrease(){
            count--;
        }
};

#endif /* _Node_H__ */
