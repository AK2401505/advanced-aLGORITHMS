#include <iostream> 
#include <algorithm> 
using namespace std; 
 
class SortAnalyser { 
public: 
    void bubbleSort(int arr[], int n, long long& counter) { 
        for (int i = 0; i < n-1; i++) { 
            for (int j = 0; j < n-1-i; j++) { 
                counter++;               // count comparison 
                if (arr[j] > arr[j+1]) 
                    swap(arr[j], arr[j+1]); 
            } 
        } 
    } 
 
    void selectionSort(int arr[], int n, long long& counter) { 
        for (int i = 0; i < n-1; i++) { 
            int min_idx = i; 
            for (int j = i+1; j < n; j++) { 
                counter++;           // count comparison 
                if (arr[j] < arr[min_idx]) 
                    min_idx = j; 
            } 
            swap(arr[min_idx], arr[i]); 
        }
    } 
 
    void insertionSort(int arr[], int n, long long& counter) { 
        for (int i = 1; i < n; i++) { 
            int key = arr[i]; 
            int j = i - 1; 
            while (j >= 0 && arr[j] > key) { 
                counter++;           // count comparison 
                arr[j + 1] = arr[j]; 
                j--; 
            } 
            arr[j + 1] = key; 
        } 
    } 
};