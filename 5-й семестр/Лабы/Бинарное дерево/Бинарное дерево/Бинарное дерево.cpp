﻿// @author Rychkov R.V.
#include <iostream>
#include "ClassTreeNode.h"

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

// Реализация деструктора для бинарного дерева
template <typename T>
Tree<T>::~Tree() {
    destroyTree(root); // При удалении объекта дерева также удаляется само дерево
}

// Рекурсивная функция для удаления дерева
template <typename T>
void Tree<T>::destroyTree(TreeNode<T>* node) {
    if (node) {
        destroyTree(node->left); // Удаляем левое поддерево
        destroyTree(node->right); // Удаляем правое поддерево
        delete node; // Удаляем узел
    }
}

// Публичный метод для добавления элемента в дерево
template <typename T>
void Tree<T>::add(T value) {
    add(root, value);
}

// Рекурсивная функция для добавления элемента в дерево
template <typename T>
void Tree<T>::add(TreeNode<T>*& node, T value) {
    if (node == nullptr) {
        node = new TreeNode<T>(value); // Если узел пустой, создаем новый узел с заданным значением
    }
    else if (value < node->value) {
        add(node->left, value); // Если значение меньше текущего узла, рекурсивно добавляем в левое поддерево
    }
    else {
        add(node->right, value); // Иначе рекурсивно добавляем в правое поддерево
    }
}

// Публичный метод для вывода дерева в порядке LNR (in-order)
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

// Публичный метод для вывода дерева в порядке NLR (pre-order)
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

// Публичный метод для вывода дерева в порядке LRN (post-order)
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

int main() {
    setlocale(LC_ALL, "RUS");
    Tree<int> tree;

    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);
    tree.add(17);

    cout << "LNR: ";
    tree.printInOrder(); // Выводим дерево в порядке вставки

    cout << "NLR: ";
    tree.printPreOrder(); // Выводим дерево в порядке префикса

    cout << "LRN: ";
    tree.printPostOrder(); // Выводим дерево в порядке постфикса

    // Подсчитываем количество узлов в дереве
    int nodeCount = tree.countNodes(tree.getRoot());

    // Выводим результат количества узлов в дереве
    cout << "Количество узлов в дереве: " << nodeCount << endl;

    // Выводим глубину дерева
    cout << "Глубина дерева: " << tree.height(tree.getRoot()) << endl;

    cout << "Структура дерева NLR " << endl;
    tree.printTree(); // Печатаем структуру дерева

    return 0;
}