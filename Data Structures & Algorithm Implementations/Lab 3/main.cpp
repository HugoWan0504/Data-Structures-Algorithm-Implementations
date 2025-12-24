#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

// Passes in an index of type int and a vector of type T (T could be string, double or int). 
//The function returns the index of the min value starting from "index" to the end of the "vector".
template<typename T>
unsigned min_index(const vector<T> &vals, unsigned index){
    unsigned min = index;
    for (unsigned i = index; i < vals.size(); i++){
        if (vals[i] < vals[min]){
            min = i;
        }
    }
    return min;
}

//Passes in a vector of type T and sorts them based on the selection sort method. 
//This function should utilize the min_index function to find the index of the min 
//value in the unsorted portion of the vector.
template<typename T>
void selection_sort(vector<T> &vals){
    unsigned min;
    T temp;
    for (unsigned i = 0; i < vals.size(); ++i){
        min = min_index(vals, i);
        //swap
        temp = vals[min];
        vals[min] = vals[i];
        vals[i] = temp;
    }
}

//Passes in a vector of type T (T could be string, double or int) and an index of type int. 
//The function returns the element located at the index of the vals. 
//You should write up a try catch block in main function so that when the index is 
//out of the range of the vector, the "std::outofrange" exception will be caught by the 
//catch (const std::outofrange& excpt). Once the exception is caught, 
//it should output "out of range exception occured" followed by a new line.
template<typename T>
T getElement(vector<T> vals, int index){
    int vectorSize = vals.size() - 1;
    try{
        if (index > vectorSize){
            throw std::out_of_range("std::outofrange");
        }
    }
    catch (const std::out_of_range& excpt){
        cout << excpt.what() << endl;
        cout << "out of range exception occured" << endl;
    }
    return vals[index];
}

vector<char> createVector(){
    int vecSize = rand() % 26;
    char c = 'a';
    vector<char> vals;
    for(int i = 0; i < vecSize; i++)
    {
        vals.push_back(c);
        c++;
    }
    return vals;
}

int main(){
    
    //Part B
     srand(time(0));
     vector<char> vals = createVector();
     char curChar;
     int index;
     int numOfRuns = 10;
     while(--numOfRuns >= 0){
         cout << "Enter a number: " << endl;
         cin >> index;
         curChar = getElement(vals,index);
         cout << "Element located at " << index << ": is " << curChar << endl;
    }
    return 0;
}