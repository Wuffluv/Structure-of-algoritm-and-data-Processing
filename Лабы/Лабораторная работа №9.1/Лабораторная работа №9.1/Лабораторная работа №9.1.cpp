#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

const int SIZE = 50;          // Количество случайных чисел
const int BUNKER_SIZE = 10;   // Размер сортировочных бункеров

// Функция для распределения чисел по очередям
void Distribute(int L[], queue<int> digitQueue[], int descriptor)
{
    for (int i = 0; i < SIZE; i++)
    {
        int digit;
        if (descriptor == 1)  // Проход 1 - сортировка по единицам
            digit = L[i] % 10;
        else if (descriptor == 2)  // Проход 2 - сортировка по десяткам
            digit = L[i] / 10;

        digitQueue[digit].push(L[i]);  // Распределение числа в соответствующую очередь
    }
}

// Функция для сбора чисел из очередей
void Collect(int L[], queue<int> digitQueue[])
{
    int index = 0;
    for (int digit = 0; digit < BUNKER_SIZE; digit++)
    {
        while (!digitQueue[digit].empty())
        {
            L[index] = digitQueue[digit].front();  // Извлечение числа из очереди
            digitQueue[digit].pop();  // Удаление числа из очереди
            index++;
        }
    }
}

// Функция для печати чисел
void Print(int L[])
{
    for (int i = 0; i < SIZE; i++)
    {
        cout.width(5);
        cout << L[i];  // Вывод числа
        if ((i + 1) % 10 == 0)
            cout << endl;  // Переход на новую строку каждые 10 чисел
    }
}

int main()
{
    srand(time(0));  // Инициализация генератора случайных чисел

    int L[SIZE];  // Массив для хранения чисел
    queue<int> digitQueue[BUNKER_SIZE];  // Массив очередей

    // Заполнение массива случайными числами
    for (int i = 0; i < SIZE; i++)
    {
        L[i] = rand() % 100;  // Генерация случайного числа из двух цифр
    }

    // Проход 1 - сортировка по единицам
    Distribute(L, digitQueue, 1);  // Распределение чисел по очередям по единицам
    Collect(L, digitQueue);  // Сбор чисел из очередей

    // Проход 2 - сортировка по десяткам
    Distribute(L, digitQueue, 2);  // Распределение чисел по очередям по десяткам
    Collect(L, digitQueue);  // Сбор чисел из очередей

    // Печать отсортированного списка чисел
    Print(L);

    return 0;
}
