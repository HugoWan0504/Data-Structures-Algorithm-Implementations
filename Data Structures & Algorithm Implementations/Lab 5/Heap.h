#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"
#include <cmath>

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];      // Notice this is an array of PrintJob pointers
  int numItems;  //current number of items in heap

public:
  /*Initializes an empty heap.*/
  Heap();

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void enqueue ( PrintJob* );

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void dequeue ( );

  /*Returns the node with highest priority.*/
  PrintJob* highest ( );

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void print ( );

private:
  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void trickleDown(int);

  //You can include additional private helper functions here
  int parent(int p){
    return (p - 1) / 2;
  }
  int left(int l){
    return 2 * l + 1;
  }
  int right(int r){
    return 2 * r + 2;
  }
  void swap (int i, int j){
    PrintJob *temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
};
#endif