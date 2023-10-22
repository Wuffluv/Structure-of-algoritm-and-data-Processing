// @author Rychkov R.V.
#include <iostream>
#include "ClassTreeNode.h"

using namespace std;

// Реализация конструктора для узла бинарного дерева
TreeNode::TreeNode(int value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}

// Реализация конструктора для бинарного дерева
Tree::Tree() {
    root = nullptr; // Изначально корень дерева устанавливается как nullptr
}

// Реализация деструктора для бинарного дерева
Tree::~Tree() {
    destroyTree(root); // При удалении объекта дерева также удаляется само дерево
}

// Рекурсивная функция для удаления дерева
void Tree::destroyTree(TreeNode* node) {
    if (node) {
        destroyTree(node->left); // Удаляем левое поддерево
        destroyTree(node->right); // Удаляем правое поддерево
        delete node; // Удаляем узел
    }
}

// Публичный метод для добавления элемента в дерево
void Tree::add(int value) {
    add(root, value);
}

// Рекурсивная функция для добавления элемента в дерево
void Tree::add(TreeNode*& node, int value) {
    if (node == nullptr) {
        node = new TreeNode(value); // Если узел пустой, создаем новый узел с заданным значением
    }
    else if (value < node->value) {
        add(node->left, value); // Если значение меньше текущего узла, рекурсивно добавляем в левое поддерево
    }
    else {
        add(node->right, value); // Иначе рекурсивно добавляем в правое поддерево
    }
}

// Публичный метод для вывода дерева в порядке LNR (in-order)
void Tree::printInOrder() {
    printInOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке LNR (in-order)
void Tree::printInOrder(TreeNode* node) {
    if (node) {
        printInOrder(node->left); // Сначала обходим левое поддерево
        cout << node->value << " "; // Затем выводим значение текущего узла
        printInOrder(node->right); // Затем обходим правое поддерево
    }
}

// Публичный метод для вывода дерева в порядке NLR (pre-order)
void Tree::printPreOrder() {
    printPreOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке NLR (pre-order)
void Tree::printPreOrder(TreeNode* node) {
    if (node) {
        cout << node->value << " "; // Сначала выводим значение текущего узла
        printPreOrder(node->left); // Затем обходим левое поддерево
        printPreOrder(node->right); // Затем обходим правое поддерево
    }
}

// Публичный метод для вывода дерева в порядке LRN (post-order)
void Tree::printPostOrder() {
    printPostOrder(root);
    cout << std::endl;
}

// Рекурсивная функция для вывода дерева в порядке LRN (post-order)
void Tree::printPostOrder(TreeNode* node) {
    if (node) {
        printPostOrder(node->left); // Сначала обходим левое поддерево
        printPostOrder(node->right); // Затем обходим правое поддерево
        cout << node->value << " "; // Затем выводим значение текущего узла
    }
}

int main() {
    Tree tree;

    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    cout << "LNR: ";
    tree.printInOrder(); // Выводим дерево в порядке вставки

    cout << "NLR: ";
    tree.printPreOrder(); // Выводим дерево в порядке префикса

    cout << "LRN: ";
    tree.printPostOrder(); // Выводим дерево в порядке постфикса

    return 0;
}
