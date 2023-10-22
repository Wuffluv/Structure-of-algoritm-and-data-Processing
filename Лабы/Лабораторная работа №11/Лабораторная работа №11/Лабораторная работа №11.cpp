#include <iostream>
#include <fstream>
#include <set>

// Шаблонный класс Node для хранения значения и указателя на следующий узел
template <typename T>
class Node {
public:
    T data;       // Значение узла
    Node* next;   // Указатель на следующий узел

    Node(T value) : data(value), next(nullptr) {}  // Конструктор для инициализации значения и указателя
};

// Класс LinkedList для управления списком узлов
template <typename T>
class LinkedList {
private:
    Node<T>* head;  // Указатель на начало списка

public:
    LinkedList() : head(nullptr) {}  // Конструктор для инициализации пустого списка

    // Метод для добавления нового узла в конец списка
    void addNode(T value) {
        Node<T>* newNode = new Node<T>(value);  // Создаем новый узел
        if (head == nullptr) {
            head = newNode;  // Если список пуст, новый узел становится началом списка
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;  // Переходим к последнему узлу списка
            }
            temp->next = newNode;  // Присоединяем новый узел к концу списка
        }
    }

    // Метод для сортировки списка
    void sortList() {
        if (head == nullptr || head->next == nullptr)
            return;  // Если список пуст или содержит только один узел, сортировка не требуется

        Node<T>* current = head;
        Node<T>* index = nullptr;
        T temp;

        while (current != nullptr) {
            index = current->next;

            while (index != nullptr) {
                if (current->data > index->data) {
                    temp = current->data;
                    current->data = index->data;
                    index->data = temp;
                }

                index = index->next;
            }

            current = current->next;
        }
    }

    // Метод для удаления дубликатов из списка
    void removeDuplicates() {
        if (head == nullptr || head->next == nullptr)
            return;  // Если список пуст или содержит только один узел, удаление дубликатов не требуется

        Node<T>* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->data == current->next->data) {
                Node<T>* temp = current->next;
                current->next = current->next->next;
                delete temp;  // Удаляем узел с дубликатом
            }
            else {
                current = current->next;
            }
        }
    }

    // Метод для вывода значений списка в текстовый файл
    void printToFile(const std::string& filename) {
        std::ofstream outputFile(filename);
        if (!outputFile.is_open()) {
            std::cerr << "Не удалось открыть файл " << filename << " для записи." << std::endl;
            return;
        }

        Node<T>* current = head;
        while (current != nullptr) {
            outputFile << current->data << " ";
            current = current->next;
        }

        outputFile.close();
    }

    // Метод для освобождения памяти, занятой списком
    void deleteList() {
        Node<T>* current = head;
        while (current != nullptr) {
            Node<T>* temp = current;
            current = current->next;
            delete temp;  // Удаляем текущий узел
        }
        head = nullptr;  // Указатель на начало списка обнуляется
    }
};

int main() {
    LinkedList<char> list;// Создаем список из 3 узлов, которые хранят латинские символы
    list.addNode('C');
    list.addNode('A');
    list.addNode('B');

    // Выводим символы в текстовый файл
    list.printToFile("output.txt");

    // Удаляем список
    list.deleteList();

    // Создаем новый список для демонстрации сортировки и удаления дубликатов
    LinkedList<int> list2;
    list2.addNode(3);
    list2.addNode(1);
    list2.addNode(2);
    list2.addNode(1);
    list2.addNode(3);
    list2.addNode(4);

    // Сортируем список
    list2.sortList();

    // Удаляем дубликаты
    list2.removeDuplicates();

    // Удаляем список
    list2.deleteList();

    return 0;
}