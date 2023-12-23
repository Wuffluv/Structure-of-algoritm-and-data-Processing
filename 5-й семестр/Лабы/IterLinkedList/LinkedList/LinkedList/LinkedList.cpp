//@author Rychkov R.V.
#include "LinkedList.h"
#include "Iterator.h"
#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
     
    LinkedList<int> list; // Создание объекта связанного списка

    // Вставка элементов в список
    list.insert(30);
    list.insert(10);
    list.insert(50);
    list.insert(20);
    list.insert(40);

    list.print(); // Вывод элементов списка

    // Поиск элемента в списке
    int search = 30;
    Node<int>* foundNode = list.search(search);
    if (foundNode != nullptr) {
        cout << "Элемент " << search << " найден" << endl;
    }
    else {
        cout << "Элемент " << search << " не найден" << endl;
    }


    // Удаление элемента из списка
    int deleteData = 30;
    list.remove(deleteData);

    list.print();// Вывод элементов списка после удаления

    list.sort(); // Сортировка списка

   
    cout << "Отсортированный список" << endl;
    list.print(); // Вывод отсортированных элементов списка
    
}

