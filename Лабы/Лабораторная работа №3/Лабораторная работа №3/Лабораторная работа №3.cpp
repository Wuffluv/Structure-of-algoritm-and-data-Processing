#include <iostream>
#include <fstream>
#include <chrono> // библиотека для измерения времени выполнения программы

using namespace std;

const int MAX_SIZE = 10000; // максимальный размер массива

// Функция для вычисления произведения элементов массива с помощью рекурсии
double multiply_recursive(double arr[], int n) {
    if (n == 0) { // базовый случай: массив пустой
        return 1.0; // произведение равно 1
    }
    else {
        return arr[n - 1] * multiply_recursive(arr, n - 1); // рекурсивный вызов функции с уменьшением размера массива
    }
}

// Функция для вычисления произведения элементов массива с помощью итерации
double multiply_iterative(double arr[], int n) {
    double prod = 1.0; // начальное значение произведения
    for (int i = 0; i < n; i++) {
        prod *= arr[i]; // умножение текущего элемента на произведение предыдущих
    }
    return prod;
}

int main() {
    setlocale(LC_ALL, "Russian");
    double arr[MAX_SIZE]; // объявление массива
    int n; // размер массива
    cout << "Введите размер массива (не более " << MAX_SIZE << "): ";
    cin >> n; // чтение размера массива с консоли

    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10 + 1; // случайное число от 1 до 10
    }


    // измерение времени выполнения рекурсивной функции
    auto start_recursive = chrono::high_resolution_clock::now(); // начальное время
    double result_recursive = multiply_recursive(arr, n); // вызов рекурсивной функции
    auto end_recursive = chrono::high_resolution_clock::now(); // конечное время
    double time_recursive = chrono::duration_cast<chrono::microseconds>(end_recursive - start_recursive).count(); // время выполнения в микросекундах

    // измерение времени выполнения итеративной функции
    auto start_iterative = chrono::high_resolution_clock::now(); // начальное время
    double result_iterative = multiply_iterative(arr, n); // вызов итеративной функции
    auto end_iterative = chrono::high_resolution_clock::now(); // конечное время
    double time_iterative = chrono::duration_cast<chrono::microseconds>(end_iterative - start_iterative).count(); // время выполнения в микросекундах

    // вывод результатов в текстовый файл
    ofstream out("result.txt");
    out << "Результаты вычислений:" << endl;
    out << "Рекурсивная функция: " << result_recursive << endl;
    out << "Итеративная функция: " << result_iterative << endl;
    out << "Время выполнения рекурсивной функции: " << time_recursive << " микросекунд" << endl;
    out << "Время выполнения итеративной функции: " << time_iterative << " микросекунд" << endl;
    out.close(); // закрытие файла
    cout << "Результаты вычислений сохранены в файле result.txt" << endl;
    return 0;
}