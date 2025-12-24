#include <cmath>
#include <ctime>
#include <iostream>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC / 1000;  //clock per milliseconds
const int NUMBERS_SIZE = 50000;

void Quicksort_midpoint(int numbers[], int i, int k);
void Quicksort_medianOfThree(int numbers[], int i, int k);
void InsertionSort(int numbers[], int numbersSize);
void fillArrays(int arr1[], int arr2[],int arr3[]);
int Partition_midpoint(int[], int, int);
int Partition_medianOfThree(int[], int, int);

int main(){
    int qMidpoint[NUMBERS_SIZE];
    int qMedian[NUMBERS_SIZE];
    int insertion[NUMBERS_SIZE];

    fillArrays(qMidpoint, qMedian, insertion);

    clock_t Start = clock();
    Quicksort_midpoint(qMidpoint, 0, NUMBERS_SIZE - 1);
    clock_t End = clock();
    // converts elapsed time from microseconds to milliseconds.
    int elapsedTime = (End - Start) / CLOCKS_PER_MS;

    cout << "Quicksort (midpoint): " << elapsedTime << "ms" << endl;

    clock_t qMedStart = clock();
    Quicksort_medianOfThree(qMedian, 0, NUMBERS_SIZE - 1);
    clock_t qMedEnd = clock();
    int qMedElapsed = (qMedEnd - qMedStart) / CLOCKS_PER_MS;

    cout << "Quicksort (median of three): " << qMedElapsed << "ms" << endl;

    clock_t insertStart = clock();
    InsertionSort(insertion, NUMBERS_SIZE);
    clock_t insertEnd = clock();
    int insertElapsed = (insertEnd - insertStart) / CLOCKS_PER_MS;

    cout << "Insertion Sort: " << insertElapsed << "ms" << endl;

    return 0;
}


int Partition_midpoint(int[], int, int);
int Partition_medianOfThree(int[], int, int);


    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_midpoint(numbers, i, k);


    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_medianOfThree(numbers, i, k);





int Partition_midpoint(int *numbers, int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    // Pick middle element as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    l = i;
    h = k;

    while (!done)
    {
        // Increment l while numbers[l] < pivot
        while (numbers[l] < pivot)
        {
            ++l;
        }

        // Decrement h while pivot < numbers[h]
        while (pivot < numbers[h])
        {
            --h;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h)
        {
            done = true;
        }
        else
        {
            // Swap numbers[l] and numbers[h],
            // update l and h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}

int Partition_medianOfThree(int *numbers, int i, int k){
    int l = 0;
    int h = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool done = false;

    // Pick median element as pivot
    midpoint = i + (k - i) / 2;

    if (numbers[midpoint] > numbers[i]){
        // right most is median
        if (numbers[midpoint] > numbers[k]){
            pivot = numbers[k];
        }
        // midpoint is median
        else{
            pivot = numbers[midpoint];
        }
    }
    else{
        // right most is median
        if (numbers[i] > numbers[k]){
            pivot = numbers[k];
        }
        // left most is median
        else{
            pivot = numbers[i];
        }
    }

    l = i;
    h = k;

    while (!done){
        // Increment l while numbers[l] < pivot
        while (numbers[l] < pivot){
            ++l;
        }

        // Decrement h while pivot < numbers[h]
        while (pivot < numbers[h]){
            --h;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return h
        if (l >= h){
            done = true;
        }
        else{
            // Swap numbers[l] and numbers[h],
            // update l and h
            temp = numbers[l];
            numbers[l] = numbers[h];
            numbers[h] = temp;

            ++l;
            --h;
        }
    }

    return h;
}


