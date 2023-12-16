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
		next = nullptr; //инициализируем указатель след. узла
		prev = nullptr; //инициализируем указатель пред. узла
	}
};

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {
		head = nullptr; //инициализируем голову
		tail = nullptr; //инициализируем хвост
	}

	void insertHead(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//Если список пустой, то новый узел становится головой и хвостом
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head; //иначе переходит на голову
			head-> = newNode;
			head = newNode; //Голова становится новым узлом
		}
	}

};