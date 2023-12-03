#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Dynamically allocate temp arrays
    int* Left = new int[n1];
    int* Right = new int[n2];

    // Copy data to temp arrays Left[] and Right[]
    for (int i = 0; i < n1; i++)
        Left[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        Right[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (Left[i] <= Right[j]) {
            arr[k++] = Left[i++];
        }
        else {
            arr[k++] = Right[j++];
        }
    }

    // Copy the remaining elements of Left[], if there are any
    while (i < n1) {
        arr[k++] = Left[i++];
    }

    // Copy the remaining elements of Right[], if there are any
    while (j < n2) {
        arr[k++] = Right[j++];
    }

    // Deallocate the memory used for Left and Right
    delete[] Left;
    delete[] Right;
}

void sort(int arr[], int left, int right) {
    if (left >= right) {
        return; // Returns recursively
    }
    int mid = left + (right - left) / 2;
    sort(arr, left, mid);
    sort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}

double sortAndFindMedian(int arr[], int size) {
    sort(arr, 0, size - 1); // Sorting the array

    // Finding the median
    if (size % 2 == 0) {
        return (arr[size / 2 - 1] + arr[size / 2]) / 2.0;
    }
    else {
        return arr[size / 2];
    }
}

int main() {
    int numbers[] = { 6, 5, 10, 3, 9, 4, 1, 7, 2, 8};
    double median = sortAndFindMedian(numbers, 10);
    cout << "The median of \"numbers\": " << median << std::endl;

    return 0;
}
