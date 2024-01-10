#include <iostream>
#include <vector>

void print_array(int* arr, int array_size);
void print_vector(std::vector<int>& vector, int vector_size);
void print(std::vector<int>& vector);

void selection_Sort(int* arr, int array_size);

void insertion_Sort(int* arr, int array_size);

void merge_Sort(std::vector<int>& vector, int vector_size);
void merge_Step(std::vector<int>& vector, int start, int end);
void merge(std::vector<int>& vector, int start1, int end1, int start2, int end2);

void quick_Sort(int* array, int array_size);
void quick_Sort_Step(int* array, int array_size, int start, int end);
int partition(int* array, int array_size, int start, int end);

int main() {
    const int array_size = 9;
    int array[array_size] = {1984, 17, 42, 1337, 4, 14, 19, 15, 10};
    std::vector<int> vector = {1984, 17, 42, 1337, 4, 14, 19, 15, 10};
    std::cout << "Unsorted:" << std::endl;
    print_array(array, array_size);
    //print_vector(vector, vector.size());
    //merge_Sort(vector, vector.size());
    quick_Sort(array, array_size);
    std::cout << "Sorted:" << std::endl;
    print_array(array, array_size);
    //print_vector(vector, vector.size());
    return 0;
}

void print_array(int* arr, int array_size) {
    std::cout << "[" << arr[0] << ", ";
    for (int i = 1; i < array_size-1; i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << arr[array_size-1] << "]" << std::endl;
}

void print_vector(std::vector<int>& vector, int vector_size) {
    std::cout << "[" << vector[0] << ", ";
    for (int i = 1; i < vector_size-1; i++) {
        std::cout << vector[i] << ", ";
    }
    std::cout << vector[vector_size-1] << "]" << std::endl;
}

void print(std::vector<int>& vector) {
    for (int i = 0; i < vector.size(); i++) {
        std::cout << vector[i] << ", "; 
    }
    std::cout << std::endl;
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

//Merge Sort Algorithm
//Natural:      No
//Stable:       Yes
//In-Place:     No
//Best Case:    nlog(n)
//Average Case: nlog(n)
//Worst Case:   nlog(n)
void merge_Sort(std::vector<int>& vector, int vector_size) {
    merge_Step(vector, 0, vector_size - 1);
}

void merge_Step(std::vector<int>& vector, int start, int end) {
    if (end == start) {
        return;
    }
    int mid = (start + end) / 2;
    merge_Step(vector, start, mid);
    merge_Step(vector, mid+1, end);
    merge(vector, start, mid, mid+1, end);
}

void merge(std::vector<int>& vector, int start1, int end1, int start2, int end2) {
    std::vector<int> temp;
    int i = start1;
    int j = start2;

    while ((i <= end1) && (j <= end2)) {
        if (vector[i] <= vector[j]) {
            temp.push_back(vector[i++]);
        }
        else {
            temp.push_back(vector[j++]);
        }
    }
    while (i <= end1) {
        temp.push_back(vector[i++]);
    }
    while (j <= end2) {
        temp.push_back(vector[j++]);
    }
    for (unsigned int i = 0; i < temp.size(); i++) {
        vector[start1 + i] = temp[i];
    }
}

//Quick Sort Algorithm
//Natural:      No
//Stable:       No
//In-Place:     Yes
//Best Case:    nlog(n)
//Average Case: nlog(n)
//Worst Case:   n^2
void quick_Sort(int* array, int array_size) {
    quick_Sort_Step(array, array_size, 0, array_size - 1);
}

void quick_Sort_Step(int* array, int array_size, int start, int end) {
     if (start < end) {
        int p = partition(array, array_size, start, end);
        quick_Sort_Step(array, array_size, start, p-1);
        quick_Sort_Step(array, array_size, p+1, end);
     }
}

int partition(int* array, int array_size, int start, int end) {
    int pivot = array[start];
    int i = start; 
    int j = end + 1;
    while (i < j) {
        do { i++; } while ((array[i] < pivot) && (i < end));
        do { j--; } while ((pivot < array[j]) && (j > start));
        if (i < j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    array[start] = array[j];
    array[j] = pivot;
    return j;
}