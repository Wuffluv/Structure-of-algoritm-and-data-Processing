#include <iostream>
#include <fstream>

// Класс рациональных чисел
class Rational {
private:
    int numerator;
    int denominator;

public:
    // Конструкторы
    Rational() {
        numerator = 0;
        denominator = 1;
    }

    Rational(int num, int den) {
        numerator = num;
        denominator = den;
    }

    // Геттеры и сеттеры
    int getNumerator() const {
        return numerator;
    }

    void setNumerator(int num) {
        numerator = num;
    }

    int getDenominator() const {
        return denominator;
    }

    void setDenominator(int den) {
        denominator = den;
    }

    // Операции
    Rational operator+(const Rational& other) const {
        int num = numerator * other.denominator + other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational operator-(const Rational& other) const {
        int num = numerator * other.denominator - other.numerator * denominator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational operator*(const Rational& other) const {
        int num = numerator * other.numerator;
        int den = denominator * other.denominator;
        return Rational(num, den);
    }

    Rational operator/(const Rational& other) const {
        int num = numerator * other.denominator;
        int den = denominator * other.numerator;
        return Rational(num, den);
    }

    // Операции ввода и вывода
    friend std::ostream& operator<<(std::ostream& os, const Rational& r) {
        os << r.numerator << "/" << r.denominator;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Rational& r) {
        is >> r.numerator >> r.denominator;
        return is;
    }
};

int main() {
    Rational a(1, 2);
    Rational b(2, 3);
    Rational c = a + b;
    Rational d = a - b;
    Rational e = a * b;
    Rational f = a / b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << c << std::endl;
    std::cout << "a - b = " << d << std::endl;
    std::cout << "a * b = " << e << std::endl;
    std::cout << "a / b = " << f << std::endl;

    std::ofstream outFile;
    outFile.open("output.txt");
    outFile << "a = " << a << std::endl;
    outFile << "b = " << b << std::endl;
    outFile << "a + b = " << c << std::endl;
    outFile << "a - b = " << d << std::endl;
    outFile << "a * b = " << e << std::endl;
    outFile << "a / b = " << f << std::endl;
    outFile.close();

    return 0;
}
