#include <iostream>
#include <algorithm>

using namespace std;

class Sorter {
public:
    void mergeSortAlgo(int arr[], int left, int right);
    void quickSort(int arr[], int low, int high);     
    void quickSortM3(int arr[], int low, int high);    

private:
    void merge(int arr[], int left, int right, int mid);
    int partition(int arr[], int low, int high);
    int partitionM3(int arr[], int low, int high);
    int medianOfThree(int arr[], int low, int high);  
};

// ---------------- Merge Sort Implementation ----------------

void Sorter::merge(int arr[], int left, int right, int mid) {
    int lsize = mid - left + 1;
    int rsize = right - mid;

    int* larr = new int[lsize];
    int* rarr = new int[rsize];

    for (int i = 0; i < lsize; i++)
        larr[i] = arr[left + i];

    for (int i = 0; i < rsize; i++)
        rarr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < lsize && j < rsize) {
        if (larr[i] <= rarr[j]) {
            arr[k] = larr[i];
            i++;
        } else {
            arr[k] = rarr[j];
            j++;
        }
        k++;
    }

    while (i < lsize) {
        arr[k] = larr[i];
        i++;
        k++;
    }
    while (j < rsize) {
        arr[k] = rarr[j];
        j++;
        k++;
    }

    
}

void Sorter::mergeSortAlgo(int arr[], int left, int right) {
    if (left >= right)
        return;
    int mid = left + (right - left) / 2;
    mergeSortAlgo(arr, left, mid);
    mergeSortAlgo(arr, mid + 1, right);
    merge(arr, left, right, mid);
}


int Sorter::partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;       

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Sorter::quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}



int Sorter::medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    
    if (arr[mid] < arr[low])
        swap(arr[low], arr[mid]);
    if (arr[high] < arr[low])
        swap(arr[low], arr[high]);
    if (arr[high] < arr[mid])
        swap(arr[mid], arr[high]);

    
    swap(arr[mid], arr[high]);
    return high;
}

int Sorter::partitionM3(int arr[], int low, int high) {
    medianOfThree(arr, low, high); 
    return partition(arr, low, high);
}

void Sorter::quickSortM3(int arr[], int low, int high) {
    if (low < high) {
        int pi = partitionM3(arr, low, high);
        quickSortM3(arr, low, pi - 1);
        quickSortM3(arr, pi + 1, high);
    }
}
