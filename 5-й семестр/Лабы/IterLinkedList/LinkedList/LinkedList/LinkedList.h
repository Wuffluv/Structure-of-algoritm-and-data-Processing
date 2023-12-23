//@author Rychkov R.V.
#pragma once
#include <iostream>
#include "Iterator.h"

template <typename T>
class Node {
public:
	T data; //������ ���������� � ����
	Node* next; //��������� �� ����. ���� � ������
	Node* prev; //��������� �� ����. ���� � ������

	//�����������
	Node(int data) {
		this->data = data; //��������� ������ ����
		next = nullptr; //�������������� ��������� ����. ����
		prev = nullptr; //�������������� ��������� ����. ����
	}
};

//����������� ������ ���������� ������
template <typename T>
class LinkedList {
private:
	Node<T>* head; // ��������� �� ������ ������
	Node<T>* tail; // ��������� �� ����� ������
public:
	LinkedList() {
		head = nullptr; //��������� �� ������
		tail = nullptr; //��������� �� �����
	}

	// ������� ������ �������� � ������ ������
	void insertHead(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//���� ������ ������, �� ����� ���� ���������� ������� � �������
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head; // ��������� ����� � ������� �������
			head-> = newNode; // ��������� �������� ����� � ����� �����
			head = newNode; // ���������� ��������� �� ������
		}
	}


	// ������� ������ �������� � ����� ������
	void insert(const T& data) {
		Node<T> newNode = new Node<t>(data);
		//���� ������ ������, �� ����� ���� ���������� ������� � �������
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			// �������� ������ ���� � �������� ������
			tail->next = newNode;
			// ��������� �������� ����� � ���������� �����
			newNode->tail;
			// ���������� ��������� �� �����
			tail = newNode;
		}
	}

	// ������� ������ �������� ����� ���������� ��������
	void insertAfter(int DataAfter, const T& data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* newNode = head;

		while (current != nullptr) {
			if (current->data == DataAfter) {
				if (current == tail) {
					tail = newNode; /// ��������� ����� ������, ���� ��������� ����� ���������� ����
				}
				newNode->prev = current; //��������� �������� ����� � ���������� �����
				newNode->next = current->next; //��������� ����� �� ��������� �����
				if (current->next != nullptr) {
					current->next->prev = newNode; //��������� �������� ����� ��� ���������� ����
				}
				current->next = newNode; //�������� ����� ��� �������� ����
				return
			}
			current = current->next;
		}

	}

	// ����� ��������� ������
	void print() {
		Node<T>* current = head;
		while (current != nullptr) {
			//������� ������ �������� ����
			cout << current->data << " ";
			//��������� � ����. ����
			current = current->next;
		}
		cout << endl;
	}
	// ����� �������� �� ��������
	Node<T>* search(const T& data) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == data) {
				//���������� ����, ���� ������ �������
				return current;
			}
			current = current->next;
		}
		//���� ������� �� ������, �� ���������� Nullptr
		return nullptr;
	}

};