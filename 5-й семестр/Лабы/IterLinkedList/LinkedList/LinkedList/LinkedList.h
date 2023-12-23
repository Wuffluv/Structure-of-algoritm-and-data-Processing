//@author Rychkov R.V.
#pragma once
#include <iostream>
#include "Iterator.h"

using namespace std;

template <typename T>
class Node {
public:
	T data; //Данные хранящиеся в узле
	Node* next; //указатель на след. узел в списке
	Node* prev; //укзаатель на пред. узел в списке

	//конструктор
	Node(int data) {
		this->data = data; //активация данных узла
		next = nullptr; //инициализируем указатель след. узел
		prev = nullptr; //инициализируем указатель пред. узел
	}
};

//определение класса связанного списка
template <typename T>
class LinkedList {
private:
	Node<T>* head; // Указатель на голову списка
	Node<T>* tail; // Указатель на хвост списка
public:
	LinkedList() {
		head = nullptr; //указатель на голову
		tail = nullptr; //указатель на хвост
	}

	// Вставка нового элемента в начало списка
	void insertHead(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//Если список пустой, то новый узел становится головой и хвостом
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			newNode->next = head; // Установка связи с текущей головой
			head->prev = newNode; // Установка обратной связи с новым узлом
			head = newNode; // Обновление указателя на голову
		}
	}


	// Вставка нового элемента в конец списка
	void insert(const T& data) {
		Node<T>* newNode = new Node<T>(data);
		//Если список пустой, то новый узел становится головой и хвостом
		if (head == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			// Привязка нового узла к текущему хвосту
			tail->next = newNode;
			// Установка обратной связи с предыдущим узлом
			newNode->prev = tail;
			// Обновление указателя на хвост
			tail = newNode;
		}
	}

	// Вставка нового элемента после указанного значения
	void insertAfter(int DataAfter, const T& data) {
		Node<T>* newNode = new Node<T>(data);
		Node<T>* current = head;

		while (current != nullptr) {
			if (current->data == DataAfter) {
				if (current == tail) {
					tail = newNode; /// обновляем хвост списка, если вставляем после хвостового узла
				}
				newNode->prev = current; //Установка обратной связи с предыдущим узлом
				newNode->next = current->next; //установка связи со следующим узлом
				if (current->next != nullptr) {
					current->next->prev = newNode; //Установка обратной связи для следующего узла
				}
				current->next = newNode; //становка связи для текущего узла
				return;
			}
			current = current->next;
		}

	}

	// Вывод элементов списка
	void print() {
		Node<T>* current = head;
		while (current != nullptr) {
			//Выводим данные текущего узла
			std::cout << current->data << " ";
			//Переходим к след. узлу
			current = current->next;
		}
		std::cout << std::endl;
	}
	// Поиск элемента по значению
	Node<T>* search(const T& data) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == data) {
				//Возвращаем узел, если найден эелемнт
				return current;
			}
			current = current->next;
		}
		//Если элемент не найден, то возвращаем Nullptr
		return nullptr;
	}
	// Удаление элемента из списка
	void remove(const T& data) {
		Node<T>* current = head;
		while (current != nullptr) {
			if (current->data == data) {
				if (current == head) {
					//Обновляем голову списка, если удаляемый элемент - головной узел
					head = current->next;
				}
				if (current == tail) {
					//Обноялвем хвост списка, если удаляемый элемент - хвостовой узел
					tail = current->prev;
				}
				if (current->prev != nullptr) {
					//Обновляем ссылку на след. элемент для пред. узла
					current->prev->next = current->next;
				}
				if (current->next != nullptr) {
					//Обновляем ссылку на пред. элемент для след. узла
					current->next->prev = current->prev;
				}
				//Удаление узла
				delete current;
				return;
			}
			// Переход к следующему узлу
			current = current->next;
		}
	}

	/// Сортировка выбором
	void sort() {
		Node<T>* current = head;  // Указатель на текущий узел списка
		while (current != nullptr) {
			Node<T>* minNode = current;  // Указатель на узел с минимальным значением
			Node<T>* temp = current;      // Временный указатель для прохода по списку

			// Поиск узла с минимальным значением в оставшейся части списка
			while (temp != nullptr) {
				if (temp->data < minNode->data) {
					minNode = temp;
				}
				temp = temp->next;
			}

			// Если найден узел с минимальным значением, производим обмен значениями
			if (minNode != current) {
				// Обмен значениями узлов
				T tempData = current->data;
				current->data = minNode->data;
				minNode->data = tempData;
			}

			current = current->next;  // Переход к следующему узлу
		}
	}

	template<typename T>
	class Iterator : public Iterator<T> {
	private:
		Node<T>* current;  // Указатель на текущий узел

	public:
		// Конструктор итератора, инициализирующий указатель на переданный узел
		Iterator(Node<T>* node) {
			current = node;
		}

		// Перегруженный оператор разыменования (*), возвращает ссылку на данные текущего узла
		T& operator*() override {
			return current->data;
		}

		// Перегруженный оператор префиксного инкремента (++), перемещает итератор к следующему узлу
		Iterator<T>& operator++() override {
			current = current->next;
			return *this;
		}

		// Перегруженный оператор постфиксного инкремента (a++), возвращает копию текущего состояния итератора,
		// затем перемещает итератор к следующему узлу
		Iterator<T>& operator++(int) override {
			Iterator<T> temp = *this;
			++(*this);
			return temp;
		}

		// Перегруженный оператор сравнения на равенство (==), сравнивает текущие узлы итераторов
		bool operator==(const Iterator<T>& other) override {
			const Iterator* otherIterator = dynamic_cast<const Iterator*>(&other);
			return current == otherIterator->current;
		}

		// Перегруженный оператор сравнения на неравенство (!=), использует оператор сравнения на равенство
		bool operator!=(const Iterator<T>& other) override {
			return !(*this == other);
		}
	};

	Iterator<T> begin() {
		// Возвращает итератор, указывающий на начало списка
		return Iterator<T>(head);
	}

	Iterator<T> end() {
		// Возвращает итератор, указывающий на конец списка (nullptr)
		return Iterator<T>(nullptr);
	}


};