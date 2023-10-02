#include<iostream>
using namespace std;

// Function to maintain the max-heap property
void heapify(int arr[], int n, int i){
    int index = i;
    int left = 2 * i;
    int right = 2 * i + 1;

    int largest = index;

    // Compare with left child and update largest if needed
    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }

    // Compare with right child and update largest if needed
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    // If the largest value is not at the current index, swap and continue heapify
    if(index != largest){
        swap(arr[index], arr[largest]);
        index = largest;
    }
}

// Function to build a max-heap from an array
void buildHeap(int arr[], int n){
    for(int i = n / 2; i > 0; i--){
        heapify(arr, n, i);
    }
}

// Function to perform Heap Sort
void heapSort(int arr[], int n){
    while(n != 1){
        // Swap the root (maximum element) with the last element
        swap(arr[1], arr[n--]);
        // Restore max-heap property in the reduced heap
        heapify(arr, n, 1);
    }
}

int main(){

    int n;
    cin >> n;

    int arr[n];

    // Input array elements
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    // Build a max-heap from the input array
    buildHeap(arr, n);

    // Perform Heap Sort to sort the array
    heapSort(arr, n);

    // Print the sorted array
    for(int i = 1; i <= n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
