//@author Rychkov R.V.
#pragma once
#include <iostream>
#include "Iterator.h"

template <typename T>
class Node {
public:
	T data; //ƒанные хран€щиес€ в узле
	Node* next; //указатель на след. узел в списке
	Node* prev; //укзаатель на пред. узел в списке

	//конструктор
	Node(int data) {
		this->data = data; //активаци€ данных узла
		next = nullptr; //инициализируем указатель след. узел
		prev = nullptr; //инициализируем указатель пред. узел
	}
};

//определение класса св€занного списка
template <typename T>
class LinkedList {
private:
	Node<T>* head; // ”казатель на голову списка
	Node<T>* tail; // ”казатель на хвост списка
public:
	LinkedList() {
		head = nullptr; //указатель на голову
		tail = nullptr; //указатель на хвост
	}

	// ¬ставка нового элемента в начало списка
	void insertHead(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//≈сли список пустой, то новый узел становитс€ головой и хвостом
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head; // ”становка св€зи с текущей головой
			head-> = newNode; // ”становка обратной св€зи с новым узлом
			head = newNode; // ќбновление указател€ на голову
		}
	}


	// ¬ставка нового элемента в конец списка
	void insert(const T& data) {
		Node<T> newNode = new Node<t>(data);
		//≈сли список пустой, то новый узел становитс€ головой и хвостом
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			// ѕрив€зка нового узла к текущему хвосту
			tail->next = newNode;
			// ”становка обратной св€зи с предыдущим узлом
			newNode->tail;
			// ќбновление указател€ на хвост
			tail = newNode;
		}
	}

	// ¬ставка нового элемента после указанного значени€
	void insertAfter(int DataAfter, const T& data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* newNode = head;

		while (current != nullptr) {
			if (current->data == DataAfter) {
				if (current == tail) {
					tail = newNode; /// обновл€ем хвост списка, если вставл€ем после хвостового узла
				}
				newNode->prev = current; //”становка обратной св€зи с предыдущим узлом
				newNode->next = current->next; //установка св€зи со следующим узлом
				if (current->next != nullptr) {
					current->next->prev = newNode; //”становка обратной св€зи дл€ следующего узла
				}
				current->next = newNode; //становка св€зи дл€ текущего узла
				return
			}
			current = current->next;
		}

	}

	// ¬ывод элементов списка
	void print() {
		Node<T>* current = head;
		while (current != nullptr) {
			//¬ыводим данные текущего узла
			cout << current->data << " ";
			//ѕереходим к след. узлу
			current = current->next;
		}
		cout << endl;
	}
	// ѕоиск элемента по значению
	Node<T>* search(const T& data) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == data) {
				//¬озвращаем узел, если найден эелемнт
				return current;
			}
			current = current->next;
		}
		//≈сли элемент не найден, то возвращаем Nullptr
		return nullptr;
	}

};