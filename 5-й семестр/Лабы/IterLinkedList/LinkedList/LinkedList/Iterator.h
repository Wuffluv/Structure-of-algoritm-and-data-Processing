//@author Rychkov R.V.
#pragma once
#include <iostream>


template <typename T>
class Iterator {
public:
    virtual T& operator*() = 0; //возвращает ссылку на текущий элемент итератора
    virtual Iterator<T>& operator++() = 0; //передвигает итератор на следующий элемент 
    virtual Iterator<T>& operator++(int) = 0; // передвигает итератор на следующий элемент и возвращает старое значение 
    virtual bool operator==(const Iterator<T>& other) = 0; // сравнивает два итератора на равенство
    virtual bool operator!=(const Iterator<T>& other) = 0; // сравнивает два итератора на неравенство
    virtual ~Iterator() {} // деструктор
};