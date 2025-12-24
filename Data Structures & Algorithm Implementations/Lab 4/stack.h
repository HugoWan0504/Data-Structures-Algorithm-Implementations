#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class stack{
    public:
        stack(){
            size = 0;
        }

        void push(T val){
            int sz = size;
            if (sz+1 > MAX_SIZE){
                throw overflow_error("Called push on full stack.");
            }
            data[size] = val;
            size++;
        }

        void pop(){
            if (size == 0){
                throw out_of_range("Called pop on empty stack.");
            }
            size--;
        }

        void pop_two(){
            if (size == 0){
                throw out_of_range("Called pop_two on empty stack.");
            }
            else if (size == 1){
                throw out_of_range("Called pop_two on a stack of size 1.");
            }
            size -= 2;
        }

        T top(){
            if (size == 0){
                throw underflow_error("Called top on empty stack.");
            }
            return data[size-1];
        }

        bool empty(){
            if (size == 0){
                return true;
            }
            return false;
        }

    private:
        const int MAX_SIZE = 20;
        T data[20];
        int size;
};

#endif /* _STACK_H_ */
