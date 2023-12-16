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

template <typename T>
class LinkedList {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	LinkedList() {
		head = nullptr; //�������������� ������
		tail = nullptr; //�������������� �����
	}

	void insertHead(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//���� ������ ������, �� ����� ���� ���������� ������� � �������
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head; //����� ��������� �� ������
			head-> = newNode;
			head = newNode; //������ ���������� ����� �����
		}
	}

};