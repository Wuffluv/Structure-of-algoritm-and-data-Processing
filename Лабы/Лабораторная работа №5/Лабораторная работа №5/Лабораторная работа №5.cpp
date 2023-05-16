#include <iostream>
#include <fstream>
using namespace std;

// Функция для вычисления n-ого числа из k-ой строки треугольника Паскаля
int pascal(int n, int k) {
    // Если n равно 0 или k равно n, то число равно 1
    if (n == 0 || k == n) {
        return 1;
    }
    else {
        // Иначе число равно сумме двух чисел из предыдущей строки
        return pascal(n - 1, k - 1) + pascal(n - 1, k);
    }
}

int main() {
    int n;
    ifstream fin("INPUT.TXT"); // Открыть файл для чтения входных данных
    fin >> n; // Считать число N
    fin.close(); // Закрыть файл для чтения входных данных

    ofstream fout("OUTPUT.TXT"); // Открыть файл для записи выходных данных
    for (int i = 0; i < n; i++) { // Перебрать строки треугольника Паскаля
        for (int j = 0; j <= i; j++) { // Перебрать числа в каждой строке
            fout << pascal(i, j) << " "; // Вывести число и пробел
        }
        fout << endl; // Перейти на следующую строку
    }
    fout.close(); // Закрыть файл для записи выходных данных

    return 0;
}
