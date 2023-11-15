// @author Rychkov R.V.
#pragma once


template <typename T>
class TreeNode {
public:
    T value;          // Значение, хранящееся в узле
    TreeNode* left;    // Указатель на левого потомка
    TreeNode* right;   // Указатель на правого потомка

    // Конструктор узла бинарного дерева
    TreeNode(T value);
};

template <typename T>
class Tree {
public:
    // Конструктор класса BinaryTree
    Tree();

    // Деструктор класса BinaryTree
    ~Tree();

    // Метод для добавления элемента в бинарное дерево
    void add(T value);

    // Метод для вывода элементов бинарного дерева в порядке LNR (in-order)
    void printInOrder();

    // Метод для вывода элементов бинарного дерева в порядке NLR (pre-order)
    void printPreOrder();

    // Метод для вывода элементов бинарного дерева в порядке LRN (post-order)
    void printPostOrder();

    // Чтобы получить доступ к корневому узлу извне класса
    TreeNode<T>* getRoot() {
        return root;
    }

    // Метод для печати структуры дерева
    void printTree();

    // Рекурсивная функция для подсчета узлов в дереве
    int countNodes(TreeNode<T>* root);

    // Рекурсивная функция для вычисления высоты дерева
    int height(TreeNode<T>* root);

private:
    TreeNode<T>* root; // Указатель на корень бинарного дерева

    // Рекурсивная функция для удаления всех узлов бинарного дерева
    void destroyTree(TreeNode<T>* node);

    // Рекурсивная функция для добавления элемента в бинарное дерево
    void add(TreeNode<T>*& node, T value);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке LNR (in-order)
    void printInOrder(TreeNode<T>* node);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке NLR (pre-order)
    void printPreOrder(TreeNode<T>* node);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке LRN (post-order)
    void printPostOrder(TreeNode<T>* node);

    // Рекурсивная функция для печати дерева 
    void printTree(TreeNode<T>* node, int depth);
};