#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

// Шаблонная функция поиска по ключу в динамическом массиве
template <typename T>
int search(T* arr, int size, T key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
            return i;
    }
    return -1; // Если элемент не найден
}


int main()
{
    
    setlocale(LC_ALL, "Russian");
    // Тестирование на малых массивах
    int intArr[] = { 1, 2, 3, 4, 5 };
    int intSize = sizeof(intArr) / sizeof(int); // Размер массива
    int intKey = 3;
    int intIndex = search(intArr, intSize, intKey);
    cout << "Индекс элемента " << intKey << " в массиве: " << intIndex << endl;

    double doubleArr[] = { 1.1, 2.2, 3.3, 4.4, 5.5 };
    int doubleSize = sizeof(doubleArr) / sizeof(double);
    double doubleKey = 4.4;
    int doubleIndex = search(doubleArr, doubleSize, doubleKey);
    cout << "Индекс элемента " << doubleKey << " в массиве: " << doubleIndex << endl;

    // Тестирование на массивах, заполненных случайными числами
    const int arrSize = 500;
    int intRand[arrSize];
    double doubleRand[arrSize];

    // Заполнение массивов случайными числами
    srand(time(NULL));
    for (int i = 0; i < arrSize; i++)
    {
        intRand[i] = rand() % 100;
        doubleRand[i] = (double)(rand() % 100) / 10;
    }

    // Поиск элемента по ключу в массивах
    int intRandKey = intRand[rand() % arrSize];
    double doubleRandKey = doubleRand[rand() % arrSize];

    clock_t start = clock(); // Запуск таймера
    int intRandIndex = search(intRand, arrSize, intRandKey);
    double doubleRandIndex = search(doubleRand, arrSize, doubleRandKey);
    clock_t end = clock(); // Остановка таймера

    // Вывод результатов

    cout << "Индекс элемента " << intRandKey << " в массиве intRand: " << intRandIndex << endl;
    cout << "Индекс элемента " << doubleRandKey << " в массиве doubleRand: " << doubleRandIndex << endl;
    cout << "Время выполнения функций: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
    cout << "Массив intArr: ";
    for (int i = 0; i < intSize; i++)
    {
        cout << intArr[i] << " ";
    }
    cout << endl;

    cout << "Массив doubleArr: ";
    for (int i = 0; i < doubleSize; i++)
    {
        cout << doubleArr[i] << " ";
    }
    cout << endl;

    cout << "Массив intRand: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << intRand[i] << " ";
    }
    cout << endl;

    cout << "Массив doubleRand: ";
    for (int i = 0; i < arrSize; i++)
    {
        cout << doubleRand[i] << " ";
    }
    cout << endl;

    // Запись результатов в файл
    ofstream fout("result.txt");
    fout << "Результаты тестирования функции поиска по ключу в динамических массивах" << endl;
    fout << "Индекс элемента " << intKey << " в массиве intArr: " << intIndex << endl;
    fout << "Индекс элемента " << doubleKey << " в массиве doubleArr: " << doubleIndex << endl;
    fout << "Индекс элемента " << intRandKey << " в массиве intRand: " << intRandIndex << endl;
    fout << "Индекс элемента " << doubleRandKey << " в массиве doubleRand: " << doubleRandIndex << endl;
    fout << "Время выполнения функций: " << (double)(end - start) / CLOCKS_PER_SEC << " секунд" << endl;
    fout.close(); 
    return 0;
}
