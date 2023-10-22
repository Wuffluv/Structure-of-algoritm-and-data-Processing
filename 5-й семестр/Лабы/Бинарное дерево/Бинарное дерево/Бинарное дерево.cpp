#include <iostream>

using namespace std;

//
// Структура узла бинарного дерева
struct Node {
    int value;
    Node* left;
    Node* right;

    // Конструктор узла
    Node(int value) {
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Функция добавления элемента в дерево
Node* add(Node* root, int value) {
    // Если дерево пустое, создаем новый корень
    if (root == nullptr) {
        return new Node(value);
    }

    // Если значение элемента меньше значения текущего узла, добавляем элемент в левое поддерево
    if (value < root->value) {
        root->left = add(root->left, value);
    }
    else {
        // Если значение элемента больше значения текущего узла, добавляем элемент в правое поддерево
        root->right = add(root->right, value);
    }

    return root; // Возвращаем обновленный корень
}

// Функция обхода дерева в порядке LNR
void TreeLNR(Node* root) {
    // Если дерево пустое, ничего не делаем
    if (root == nullptr) {
        return;
    }

    // Обходим левое поддерево
    TreeLNR(root->left);

    // Выводим значение текущего узла
    cout << root->value << " ";

    // Обходим правое поддерево
    TreeLNR(root->right);
}

// Функция обхода дерева в порядке NLR
void TreeNLR(Node* root) {
    // Если дерево пустое, ничего не делаем
    if (root == nullptr) {
        return;
    }

    // Выводим значение текущего узла
    cout << root->value << " ";

    // Обходим левое поддерево
    TreeNLR(root->left);

    // Обходим правое поддерево
    TreeNLR(root->right);
}

// Функция обхода дерева в порядке LRN
void TreeLRN(Node* root) {
    // Если дерево пустое, ничего не делаем
    if (root == nullptr) {
        return;
    }

    // Обходим левое поддерево
    TreeLRN(root->left);

    // Обходим правое поддерево
    TreeLRN(root->right);

    // Выводим значение текущего узла
    cout << root->value << " ";
}

// Основная функция
int main() {
    // Создаем корень дерева с начальным значением
    Node* root = new Node(10);

    // Добавляем элементы в дерево
    add(root, 5);
    add(root, 15);
    add(root, 2);
    add(root, 7);
    add(root, 12);

    // Выводим дерево в порядке вставки
    cout << "LNR: ";
    TreeLNR(root);
    cout << endl;

    // Выводим дерево в порядке префикса
    cout << "NLR: ";
    TreeNLR(root);
    cout << endl;

    // Выводим дерево в порядке постфикса
    cout << "LRN: ";
    TreeLRN(root);
    cout << endl;

    return 0;
}
