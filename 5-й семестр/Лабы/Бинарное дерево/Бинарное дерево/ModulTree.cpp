//@author Rychkov R.V.
#include <iostream>
#include "ClassTreenode.h"
#include <queue>
#include "BST.h"

using namespace std;

// Реализация конструктора для узла бинарного дерева
template <typename T>
TreeNode<T>::TreeNode(T value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}


// Реализация конструктора для бинарного дерева
template <typename T>
Tree<T>::Tree() {
    root = nullptr; // Изначально корень дерева устанавливается как nullptr
}

// Реализация конструктора копирования
template <typename T>
Tree<T>::Tree(const Tree<T>& other) {
    copyTree(root, other.root);
}

// Реализация деструктора для бинарного дерева
template <typename T>
Tree<T>::~Tree() {
    destroyTree(root); // При удалении объекта дерева также удаляется само дерево
}

// Рекурсивная функция для удаления дерева
template <typename T>
void Tree<T>::destroyTree(TreeNode<T>* root) {
    if (root != nullptr) {
        return;

        destroyTree(root->left); 
        destroyTree(root->right); 

        delete root; // Удаление корня 

    }
    root = nullptr;
}

/// Удаление одного узла
template <typename T>
void deleteNode(TreeNode<T>* node) {
    delete node;
}

// метод для добавления элемента в дерево
template <typename T>
void Tree<T>::add(T value) {
    add(root, value);
}

// Рекурсивная функция для добавления элемента в бинарное дерево
template <typename T>
void Tree<T>::add(TreeNode<T>*& node, T value) {
    if (node == nullptr) {
        node = new TreeNode<T>(value); // Если узел пустой, создаем новый узел с заданным значением
    }
    else if (value <= node->value) {
        add(node->left, value); // Если значение меньше или равно текущему узлу, рекурсивно добавляем в левое поддерево
    }
    else {
        add(node->right, value); // Иначе рекурсивно добавляем в правое поддерево
    }
}

// метод для вывода дерева в порядке LNR (in-order)
template <typename T>
void Tree<T>::printInOrder() {
    printInOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке LNR (in-order)
template <typename T>
void Tree<T>::printInOrder(TreeNode<T>* node) {
    if (node) {
        printInOrder(node->left); // Сначала обходим левое поддерево
        cout << node->value << " "; // Затем выводим значение текущего узла
        printInOrder(node->right); // Затем обходим правое поддерево
    }
}

// метод для вывода дерева в порядке NLR (pre-order)
template <typename T>
void Tree<T>::printPreOrder() {
    printPreOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке NLR (pre-order)
template <typename T>
void Tree<T>::printPreOrder(TreeNode<T>* node) {
    if (node) {
        cout << node->value << " "; // Сначала выводим значение текущего узла
        printPreOrder(node->left); // Затем обходим левое поддерево
        printPreOrder(node->right); // Затем обходим правое поддерево
    }
}

// метод для вывода дерева в порядке LRN (post-order)
template <typename T>
void Tree<T>::printPostOrder() {
    printPostOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке LRN (post-order)
template <typename T>
void Tree<T>::printPostOrder(TreeNode<T>* node) {
    if (node) {
        printPostOrder(node->left); // Сначала обходим левое поддерево
        printPostOrder(node->right); // Затем обходим правое поддерево
        cout << node->value << " "; // Затем выводим значение текущего узла
    }
}

// Рекурсивная функция для подсчета узло в дереве
template <typename T>
int Tree<T>::countNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0; // Если дерево пустое, возвращаем 0
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right); // Суммируем
    }
}

// Рекурсивная функция для вычисления высоты дерева
template <typename T>
int Tree<T>::height(TreeNode<T>* root) {
    // Базовый случай, если пустое дерево имеет высоту 0
    if (root == nullptr) {
        return 0;
    }
    // Повторяем для левого и правого поддерева и учитываем максимальную глубину
    return 1 + std::max(height(root->left), height(root->right));
}

// Рекурсивная функция для печати структуры дерева в порядке NLR
template <typename T>
void Tree<T>::printTree(TreeNode<T>* node, int depth) {
    if (node) {
        printTree(node->left, depth + 1); // Обходим левое поддерево
        for (int i = 0; i < depth; i++) {
            cout << "   "; // Отступ для наглядности
        }
        cout << node->value << endl; // Выводим значение текущего узла
        printTree(node->right, depth + 1); // Затем обходим правое поддерево
    }
}

// Метод для печати структуры дерева
template <typename T>
void Tree<T>::printTree() {
    printTree(root, 0);
    cout << endl;
}



// Реализация рекурсивной функции копирования узлов бинарного дерева
template <typename T>
void Tree<T>::copyTree(TreeNode<T>*& destination, const TreeNode<T>* source) {
    if (source) {
        destination = new TreeNode<T>(source->value);//Destination - node
        copyTree(destination->left, source->left);//Работа с узлом с left, корень с left
        copyTree(destination->right, source->right);///Работа с узлом с right, корень с right
        //Порядок NLR
    }
    else {
        destination = nullptr;
    }
}

//Метод для создания копии дерева
template <typename T>
Tree<T> Tree<T>::copy() {
    Tree<T> copiedTree;
    copiedTree.copyTree(copiedTree.root, root);
    return copiedTree;
}

// Метод для получения массива значений узлов дерева в порядке обхода в ширину
template <typename T>
std::vector<T> Tree<T>::toArray() {
    std::vector<T> result;
    if (!root)
        return result; // Если дерево пусто, вернем пустой вектор

    std::queue<TreeNode<T>*> nodeQueue; // Создаем очередь для узлов дерева
    nodeQueue.push(root); // Добавляем корневой узел в очередь

    while (!nodeQueue.empty()) { // Пока очередь не пуста
        TreeNode<T>* current = nodeQueue.front(); // Получаем первый узел в очереди
        nodeQueue.pop(); // Удаляем первый узел из очереди

        result.push_back(current->value); // Добавляем значение текущего узла в массив

        if (current->left)
            nodeQueue.push(current->left); // Если есть левый потомок, добавляем его в очередь

        if (current->right)
            nodeQueue.push(current->right); // Если есть правый потомок, добавляем его в очередь
    }

    return result;
}



// Реализация конструктора класса BST
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : Tree<T>() {}

// Реализация метода для добавления элемента в бинарное дерево поиска
template <typename T>
void BinarySearchTree<T>::insert(T value) {
    this->add(value);
}

// Реализация метода для поиска элемента в бинарном дереве поиска
template <typename T>
bool BinarySearchTree<T>::search(T value) {
    TreeNode<T>* current = this->getRoot(); // Устанавливаем текущий узел в корень дерева
    while (current) { // Пока текущий узел существует
        if (value == current->value) {
            return true; // Если значение текущего узла совпадает с искомым, элемент найден
        }
        else if (value < current->value) {
            current = current->left; // Если искомое значение меньше значения текущего узла, переходим к левому потомку
        }
        else {
            current = current->right; // Если искомое значение больше значения текущего узла, переходим к правому потомку
        }
    }
    return false; // Элемент не найден
}


// Реализация метода для удаления элемента из бинарного дерева поиска
template <typename T>
void BinarySearchTree<T>::remove(T value) {
    // Реализация удаления элемента из бинарного дерева поиска
    
}
