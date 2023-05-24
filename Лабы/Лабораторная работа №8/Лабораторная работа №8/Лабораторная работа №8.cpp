#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
using namespace std;

/// Переделать в класс СТЕК

// Проверяет, является ли строка палиндромом
bool isPalindrome(const string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        if (str[left] != str[right]) {
            return false;  // Символы не совпадают, строка не палиндром
        }
        left++;
        right--;
    }

    return true;  // Все символы совпали, строка палиндром
}

// Преобразует число из десятичной системы в другую систему счисления
string convertToBase(int number, int base) {
    if (number == 0) {
        return "0";  // Если число равно 0, результат тоже "0"
    }

    string result = "";
    while (number > 0) {
        int remainder = number % base;  // Остаток от деления на новое основание

        // Преобразуем остаток в символ и добавляем в начало результата
        char digit;
        if (remainder < 10) {
            digit = '0' + remainder;  // Цифры 0-9
        }
        else {
            digit = 'A' + remainder - 10;  // Буквы A-Z
        }
        result = digit + result;

        number /= base;  // Деление на новое основание
    }

    return result;
}

// Вычисляет результат постфиксного выражения
int postfixCalculator(const string& expression) {
    stack<int> operands;  // Стек операндов
    for (char ch : expression) {
        if (isdigit(ch)) {
            operands.push(ch - '0');  // Преобразуем символ в число и добавляем в стек
        }
        else {
            int operand2 = operands.top();
            operands.pop();
            int operand1 = operands.top();
            operands.pop();
            switch (ch) {
            case '+':
                operands.push(operand1 + operand2);
                break;
            case '-':
                operands.push(operand1 - operand2);
                break;
            case '*':
                operands.push(operand1 * operand2);
                break;
            case '/':
                operands.push(operand1 / operand2);
                break;
            case '^':
                operands.push(pow(operand1, operand2));
                break;
            default:
                cout << "Недопустимая операция: " << ch << endl;
                return 0;
            }
        }
    }
    return operands.top();  // Результат вычислений
}

int main() {
    setlocale(LC_ALL, "rus");

    ofstream outputFile("output.txt");  // Открытие файла для записи
    if (!outputFile.is_open()) {
        cout << "Ошибка открытия файла." << endl;
        return 1;
    }

    // Проверка палиндрома
    string inputStr;
    cout << "Введите строку: ";
    getline(cin, inputStr);

    if (isPalindrome(inputStr)) {
        outputFile << "Строка является палиндромом." << endl;
    }
    else {
        outputFile << "Строка не является палиндромом." << endl;
    }

    // Преобразование числа в другую систему счисления
    int decimalNumber, base;
    cout << "Введите десятичное число: ";
    cin >> decimalNumber;
    cout << "Введите новое основание: ";
    cin >> base;

    outputFile << "Результат: " << convertToBase(decimalNumber, base) << endl;

    // Постфиксный калькулятор
    cin.ignore();  // Очищаем буфер после предыдущего ввода числа
    string postfixExpression;
    cout << "Введите постфиксное выражение: ";
    getline(cin, postfixExpression);

    outputFile << "Результат вычислений: " << postfixCalculator(postfixExpression) << endl;

    outputFile.close();  // Закрытие файла

    return 0;
}
