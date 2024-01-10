#include <iostream>

void print_array(int* arr, int array_size);
void selection_Sort(int* arr, int array_size);
void insertion_Sort(int* arr, int array_size);
void merge_Sort(int* arr, int array_size);

int main() {
    const int array_size = 9;
    int array[array_size] = {1984, 17, 42, 1337, 4, 14, 19, 15, 10};
    std::cout << "Unsorted:" << std::endl;
    print_array(array, array_size);
    insertion_Sort(array, array_size);
    std::cout << "Sorted:" << std::endl;
    print_array(array, array_size);
    return 0;
}

void print_array(int* arr, int array_size) {
    std::cout << "[" << arr[0] << ", ";
    for (int i = 1; i < array_size-1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[array_size-1] << "]" << std::endl;
}

//Selection Sort Algorithm
//Natural:      No
//Stable:       No
//In-Place:     Yes
//Best Case:    n^2
//Average Case: n^2
//Worst Case:   n^2
void selection_Sort(int* arr, int array_size) {
    for (int i = 0; i < array_size; i++) {
        int min = arr[i];
        int pos = i;
        for (int j = i + 1; j < array_size; j++) {
            if (arr[j] < min) {
                min = arr[j];
                pos = j;
            }
        }
        arr[pos] = arr[i];
        arr[i] = min;
    }
}

//Insertion Sort Algorithm
//Natural:      Yes
//Stable:       Yes
//In-Place:     Yes
//Best Case:    n^2
//Average Case: n^2
//Worst Case:   n^2
void insertion_Sort(int* arr, int array_size) {
    for (int i = 1; i < array_size; i++) {
        //print_array(arr, array_size);
        //std::cout << "i: " << i << std::endl;
        for (int j = i; (j > 0) && (arr[j-1] > arr[j]); j--) {
            //std::cout << "j: " << j << std::endl;
            int temp = arr[j-1];
            //std::cout << "temp: " << temp << std::endl;
            arr[j-1] = arr[j];
            //std::cout << "arr[j-1]: " << arr[j-1] << std::endl;
            arr[j] = temp;
            //std::cout << "arr[j]: " << arr[j] << std::endl;
        }
    }
}

void merge_Sort(int* arr, int array_size) {}