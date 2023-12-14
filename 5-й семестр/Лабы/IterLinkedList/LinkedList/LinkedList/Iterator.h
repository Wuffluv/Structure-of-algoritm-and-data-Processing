//@author Rychkov R.V.
#pragma once
#include <iostream>


template <typename T>
class AbstractIterator {
public:
    virtual T& operator*() = 0; //возвращает ссылку на текущий элемент итератора
    virtual AbstractIterator<T>& operator++() = 0; //передвигает итератор на следующий элемент (префиксный инкремент)
    virtual AbstractIterator<T>& operator++(int) = 0; // передвигает итератор на следующий элемент и возвращает старое значение (постфиксный инкремент)
    virtual bool operator==(const AbstractIterator<T>& other) = 0; // сравнивает два итератора на равенство
    virtual bool operator!=(const AbstractIterator<T>& other) = 0; // сравнивает два итератора на неравенство
    virtual ~AbstractIterator() {} // деструктор

   
};