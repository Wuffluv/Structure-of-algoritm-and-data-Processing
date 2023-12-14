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
		next = nullptr; //��������� ��������� ����. ����
		prev = nullptr; //��������� ��������� ����. ����
	}
};