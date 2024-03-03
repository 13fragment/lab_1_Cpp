#include <iostream>
#include <cstdlib> 
#include <ctime>  
#include <chrono>  

using namespace std;

template <typename T>
void fill(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 1000; // Генерация случайных чисел от 0 до 999
    }
}

template <typename T>
void output(T* arr, int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void bubbleSort(T* arr, int size) {
    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }

    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "time of implementation of BubleSort: " << duration.count() << "micro sec" << endl;
}

template <typename T>
int division(T* arr, int low, int high) {
    int index = low + rand() % (high - low + 1);
    swap(arr[index], arr[high]);

    T pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

template <typename T>
void quickSort(T* arr, int low, int high) {

    if (low < high) {
        int index = division(arr, low, high);
        quickSort(arr, low, index - 1);
        quickSort(arr, index + 1, high);
    }

}

template <typename T>
void selectionSort(T* arr, int size) {
    auto start_time = chrono::high_resolution_clock::now();

    for (int i = 0; i < size - 1; i++) {
        int minInd = i;

        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minInd]) {
                minInd = j;
            }
        }
        if (minInd != i) {
            swap(arr[i], arr[minInd]);
        }
    }
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);

    cout << "time of implementation pf SelectionSort: " << duration.count() << " micro sec" << endl;

}


int main() {
    srand(time(0)); 

    // Bubble sort
    cout << "Bubble sort" << endl;
    int sizeBubble;
    cout << "Enter size of the array: ";
    cin >> sizeBubble;

    int* massivBubble = new int[sizeBubble];
    fill(massivBubble, sizeBubble);
    cout << "Original array: ";
    output(massivBubble, sizeBubble);

    bubbleSort(massivBubble, sizeBubble);
    cout << "Sorted array: ";
    output(massivBubble, sizeBubble);
    cout << endl;

    delete[] massivBubble;

    // Quick Sort
    cout << "QuickSort" << endl;
    int sizeQuick;
    cout << "Enter the size of the array: ";
    cin >> sizeQuick;

    int* massivQuick = new int[sizeQuick];
    fill(massivQuick, sizeQuick);
    cout << "Original array: ";
    output(massivQuick, sizeQuick);

    auto start_time = chrono::high_resolution_clock::now();
    quickSort(massivQuick, 0, sizeQuick - 1);
    auto end_time = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(end_time - start_time);
    cout << "time of implementation of QuickSort: " << duration.count() << " micro sec" << endl;
    cout << "Sorted array: ";
    output(massivQuick, sizeQuick);
    cout << endl;

    delete[] massivQuick;

    // Selection Sort
    cout << "SelectionSort" << endl;
    int sizeSelection;
    cout << "Enter the size of the array: ";
    cin >> sizeSelection;

    int* massivSelection = new int[sizeSelection];
    fill(massivSelection, sizeSelection);
    cout << "Original array: ";
    output(massivSelection, sizeSelection);

    selectionSort(massivSelection, sizeSelection);
    cout << "Sorted array: ";
    output(massivSelection, sizeSelection);

    delete[] massivSelection;

    return 0;
}