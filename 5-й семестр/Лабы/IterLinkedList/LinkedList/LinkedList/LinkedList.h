//@author Rychkov R.V.
#pragma once
#include <iostream>
#include "Iterator.h"

template <typename T>
class Node {
public:
	T data; //Данные хранящиеся в узле
	Node* next; //указатель на след. узел в списке
	Node* prev; //укзаатель на пред. узел в списке

	//конструктор
	Node(int data) {
		this->data = data; //активация данных узла
		next = nullptr; //активация указателя след. узла
		prev = nullptr; //активация указателя пред. узла
	}
};