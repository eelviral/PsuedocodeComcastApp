#include <iostream>

using namespace std;

// Merges two sorted subarrays into a single sorted subarray. (Not one of the
// functions in the psuedocode requirements, but vital to sort() function).
void merge(int arr[], int start, int middle, int end) {
    int leftSize = middle - start + 1;
    int rightSize = end - middle;

    // Allocate memory for temporary arrays
    int* leftTemp = new int[leftSize];
    int* rightTemp = new int[rightSize];

    // Copy data into temp arrays
    for (int i = 0; i < leftSize; i++)
        leftTemp[i] = arr[start + i];
    for (int j = 0; j < rightSize; j++)
        rightTemp[j] = arr[middle + 1 + j];

    // Merge the temporary arrays back into the main array
    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (leftTemp[i] <= rightTemp[j]) {
            arr[k++] = leftTemp[i++];
        }
        else {
            arr[k++] = rightTemp[j++];
        }
    }

    // Copy any remaining elements from the left temporary array
    while (i < leftSize) {
        arr[k++] = leftTemp[i++];
    }

    // Copy any remaining elements from the right temporary array
    while (j < rightSize) {
        arr[k++] = rightTemp[j++];
    }

    // Free the memory allocations
    delete[] leftTemp;
    delete[] rightTemp;
}

// Sorts an array using the merge sort algorithm.
void sort(int arr[], int left, int right) {
    if (left >= right) {
        return; // Returns recursively
    }
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);         // sort left half recursively
    sort(arr, mid + 1, right);    // sort right half recursively
    merge(arr, left, mid, right); // merge left and right halves
}

// Sorts an array and finds its median value.
int sortAndFindMedian(int arr[], int size) {
    sort(arr, 0, size - 1); // sort the array

    // Find the median
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2;
    }
    else {
        return arr[size / 2];
    }
}

int main() {
    int arrSize;
    cout << "Enter the number of elements: ";
    cin >> arrSize;

    // Dynamically allocate the array
    int* numbers = new int[arrSize];

    // Ask user to enter numbers separated by ENTER
    cout << "Enter " << arrSize << " integers:" << endl;
    for (int i = 0; i < arrSize; i++) {
        cin >> numbers[i];
    }

    // Display the given array
    cout << "Given array is \n";
    for (int i = 0; i < arrSize; i++) {
        cout << numbers[i] << " ";
    }
    cout << "\n";

    int median = sortAndFindMedian(numbers, arrSize);
    cout << "The median of \"numbers\": " << median << endl;

    return 0;
}
