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

int Partition_midpoint(int numbers[], int i, int k);
int Partition_medianOfThree(int *numbers, int i, int k);

int main(){
    int midpoint[NUMBERS_SIZE];
    int median[NUMBERS_SIZE];
    int insertion[NUMBERS_SIZE];

    fillArrays(midpoint, median, insertion);

    clock_t midStart = clock();
    Quicksort_midpoint(midpoint, 0, NUMBERS_SIZE - 1);
    clock_t midEnd = clock();
    // converts elapsed time from microseconds to milliseconds.
    int elapsedTimeMid = (midEnd - midStart) / CLOCKS_PER_MS;

    cout << "Quicksort (midpoint): " << elapsedTimeMid << "ms" << endl;

    clock_t medStart = clock();
    Quicksort_medianOfThree(median, 0, NUMBERS_SIZE - 1);
    clock_t medEnd = clock();
    // converts elapsed time from microseconds to milliseconds.
    int elapsedTimeMed = (medEnd - medStart) / CLOCKS_PER_MS;

    cout << "Quicksort (median of three): " << elapsedTimeMed << "ms" << endl;

    clock_t inStart = clock();
    InsertionSort(insertion, NUMBERS_SIZE);
    clock_t inEnd = clock();
    // converts elapsed time from microseconds to milliseconds.
    int elapsedTimeIn = (inEnd - inStart) / CLOCKS_PER_MS;

    cout << "Insertion Sort: " << elapsedTimeIn << "ms" << endl;

    return 0;
}

void Quicksort_midpoint(int numbers[], int i, int k){
    int j = 0;

    // Base case - If there are 1 or zero elements to sort
    // partition is already sorted
    if (i >= k){
        return;
    }
    
    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_midpoint(numbers, i, k);

    // Recursively sort low partition (i to j)
    // high partition (j + 1 to k)
    Quicksort_midpoint(numbers, i, j);
    Quicksort_midpoint(numbers, j + 1, k);
}

void Quicksort_medianOfThree(int numbers[], int i, int k){
    int j = 0;

    // Base case - If there are 1 or zero elements to sort
    // partition is already sorted
    if (i >= k){
        return;
    }

    // Partition the data within the array. Value j returned
    // from partitioning is location of last element in low partition.
    j = Partition_medianOfThree(numbers, i, k);

    // Recursively sort low partition (i to j) and
    // high partition (j + 1 to k)
    Quicksort_medianOfThree(numbers, i, j);
    Quicksort_medianOfThree(numbers, j + 1, k);
}

void InsertionSort(int numbers[], int numbersSize){
    for (int i = 1; i < numbersSize; i++){
        for (int j = i; j > 0; j--){
            if (numbers[j] < numbers[j - 1]){
                int temp = numbers[j];
                numbers[j] = numbers[j - 1];
                numbers[j - 1] = temp;
            }
        }
    }
}

int genRandInt(int low, int high){
    return low + rand() % (high - low + 1);
}

void fillArrays(int arr1[], int arr2[],int arr3[]){
    for (int i = 0; i < NUMBERS_SIZE; ++i){
        arr1[i] = genRandInt(0, NUMBERS_SIZE);
        arr2[i] = arr1[i];
        arr3[i] = arr1[i];
    }
}



int Partition_midpoint(int *numbers, int i, int k){
    int low = 0;
    int high = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool finish = false;

    // Pick middle as pivot
    midpoint = i + (k - i) / 2;
    pivot = numbers[midpoint];

    low = i;
    high = k;

    while (!finish){
        // Increment low point while numbers[low] < pivot
        while (numbers[low] < pivot){
            low++;
        }

        // Decrement high point while pivot < numbers[high]
        while (pivot < numbers[high]){
            high--;
        }

        // If there are zero or one elements remaining
        // all numbers are partitioned. Return high.
        if (low >= high){
            finish = true;
        }
        else{
            // Swap numbers[low] and numbers[high]
            // update low and high
            temp = numbers[low];
            numbers[low] = numbers[high];
            numbers[high] = temp;

            low++;
            high--;
        }
    }

    return high;
}

int Partition_medianOfThree(int *numbers, int i, int k){
    int low = 0;
    int high = 0;
    int midpoint = 0;
    int pivot = 0;
    int temp = 0;
    bool finish = false;

    // Pick median as pivot
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

    low = i;
    high = k;

    while (!finish){
        // Increment low while numbers[low] < pivot
        while (numbers[low] < pivot){
            low++;
        }

        // Decrement high while pivot < numbers[high]
        while (pivot < numbers[high]){
            high--;
        }

        // If there are zero or one elements remaining,
        // all numbers are partitioned. Return high.
        if (low >= high){
            finish = true;
        }
        else{
            // Swap numbers[low] and numbers[high],
            // update low and high
            temp = numbers[low];
            numbers[low] = numbers[high];
            numbers[high] = temp;

            low++;
            high--;
        }
    }

    return high;
}


