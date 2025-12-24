#include <iostream>
#include "Heap.h"

using namespace std;

//Initializes an empty heap.
  Heap::Heap(){
    numItems = 0;
  }

  /*Inserts a PrintJob to the heap without
  violating max-heap properties.*/
  void Heap::enqueue ( PrintJob* job){
    if(numItems < MAX_HEAP_SIZE){
      if(!numItems){
        arr[numItems] = job;
        numItems++;
      }
      else{
        int x = numItems;
        while ((x > 0) && (arr[(x - 1) / 2]->getPriority() < job->getPriority())){
          arr[x] = arr[(x - 1) / 2];
          x = (x - 1) / 2;
        }
        arr[x] = job;
        numItems++;
      }
    } 
  }

  /*Removes the node with highest priority from the heap. 
  Follow the algorithm on priority-queue slides. */
  void Heap::dequeue ( ){
    if(numItems > 0){
      PrintJob *job = arr[0];
      arr[0] = arr[numItems - 1];
      numItems--;
      delete(job);
      trickleDown(0);
    }
    return;
  }

  /*Returns the node with highest priority.*/
  PrintJob* Heap::highest ( ){
    if(numItems > 0){
      return arr[0];
    }
    return NULL;
  }

  /*Prints the PrintJob with highest priority in the following format:
  Priority: priority, Job Number: jobNum, Number of Pages: numPages
  (Add a new line at the end.)*/
  void Heap::print ( ){
    if(numItems > 0){
      cout << "Priority: " << arr[0]->getPriority();
      cout << ", Job Number: " << arr[0]->getJobNumber();
      cout << ", Number of Pages: " << arr[0]->getPages() << endl;
    }
  }

  /*This function is called by dequeue function
  to move the new root down the heap to the 
  appropriare location.*/
  void Heap::trickleDown(int root ){
    int l = left(root);
    int r = right(root);
    int biggest = root;

    if( l < numItems && arr[l]->getPriority() > arr[biggest]->getPriority()){
      biggest = l;
    }
    if( r < numItems && arr[r]->getPriority() > arr[biggest]->getPriority()){
      biggest = r;
    }
    if(root != biggest){
      swap(root,biggest);
      trickleDown(biggest);
    }
  }
