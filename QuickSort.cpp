#include <iostream>
#include <vector>

int partition(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Choose the rightmost element as the pivot
    int i = low - 1; // Index of the smaller element

    for (int j = low; j <= high - 1; ++j) {
        if (arr[j] < pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);
    return i + 1; // Return the index of the pivot element
}

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        // Partition the array into two sub-arrays using the pivot element
        int pi = partition(arr, low, high);

        // Recursive call on the left sub-array
        quickSort(arr, low, pi - 1);

        // Recursive call on the right sub-array
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {5, 2, 9, 1, 5, 6};
    int size = arr.size();

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // Perform quick sort
    quickSort(arr, 0, size - 1);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
