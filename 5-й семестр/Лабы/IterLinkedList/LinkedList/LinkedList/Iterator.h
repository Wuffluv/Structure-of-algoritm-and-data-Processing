//@author Rychkov R.V.
#pragma once
#include <iostream>


template <typename T>
class Iterator {
public:
    virtual T& operator*() = 0; //���������� ������ �� ������� ������� ���������
    virtual Iterator<T>& operator++() = 0; //����������� �������� �� ��������� ������� 
    virtual Iterator<T>& operator++(int) = 0; // ����������� �������� �� ��������� ������� � ���������� ������ �������� 
    virtual bool operator==(const Iterator<T>& other) = 0; // ���������� ��� ��������� �� ���������
    virtual bool operator!=(const Iterator<T>& other) = 0; // ���������� ��� ��������� �� �����������
    virtual ~Iterator() {} // ����������
};