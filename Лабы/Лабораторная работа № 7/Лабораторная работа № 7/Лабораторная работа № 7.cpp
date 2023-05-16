#include <iostream>
#include <chrono>

using namespace std::chrono;

// Шаблонная функция для обмена двух элементов
template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// Шаблонная функция для сортировки пузырьком
template<typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// Шаблонная функция для сортировки выбором
template<typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

// Шаблонная функция для сортировки вставками
template<typename T>
void insertionSort(T arr[], int n)
{
    for (int i = 1; i < n; i++) {
        T key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// Функция для генерации случайных массивов заданного размера
int* generateRandomArray(int n)
{
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }
    return arr;
}

// Функция для тестирования работы функций сортировки
void testSortFunctions()
{
    int arr1[] = { 5, 2, 1, 6, 8 };
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, n1);
    std::cout << "Bubble sort: ";
    for (int i = 0; i < n1; i++) {
        std::cout << arr1[i] << " ";
    }
    std::cout << std::endl;

    int arr2[] = { 5, 2, 1, 6, 8 };
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    selectionSort(arr2, n2);
    std::cout << "Selection sort: ";
    for (int i = 0; i < n2; i++) {
        std::cout << arr2[i] << " ";
    }
    std::cout << std::endl;

    int arr3[] = { 5, 2, 1, 6, 8 };
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    insertionSort(arr3, n3);
    std::cout << "Insertion sort: ";
    for (int i = 0; i < n3; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;
}
