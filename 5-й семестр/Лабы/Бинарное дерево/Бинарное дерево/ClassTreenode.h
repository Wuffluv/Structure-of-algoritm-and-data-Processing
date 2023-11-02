// @author Rychkov R.V.
#pragma once

// Объявление класса TreeNode для представления узла бинарного дерева
//todo: сделать класс шаблонным 
class TreeNode {
public:
    int value;           // Значение, хранящееся в узле
    TreeNode* left;  // Указатель на левого потомка
    TreeNode* right; // Указатель на правого потомка

    // Конструктор узла бинарного дерева
    TreeNode(int value);
};
    

// Объявление класса Tree для представления бинарного дерева

class Tree {
public:
    // Конструктор класса BinaryTree
    Tree();

    // Деструктор класса BinaryTree
    ~Tree();

    // Метод для добавления элемента в бинарное дерево
    void add(int value);

    // Метод для вывода элементов бинарного дерева в порядке LNR (in-order)
    void printInOrder();

    // Метод для вывода элементов бинарного дерева в порядке NLR (pre-order)
    void printPreOrder();

    // Метод для вывода элементов бинарного дерева в порядке LRN (post-order)
    void printPostOrder();
    
    //Чтобы получить доступ к корневому узлу извне класса
    TreeNode* getRoot() {
        return root;
    }

    // Метод для печати структуры дерева
    void printTree();

private:
    //todo: перевести функции работы с узлом вне класса
    TreeNode* root; // Указатель на корень бинарного дерева

    // Рекурсивная функция для удаления всех узлов бинарного дерева
    void destroyTree(TreeNode* node);

    // Рекурсивная функция для добавления элемента в бинарное дерево
    void add(TreeNode*& node, int value);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке LNR (in-order)
    void printInOrder(TreeNode* node);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке NLR (pre-order)
    void printPreOrder(TreeNode* node);

    // Рекурсивная функция для вывода элементов бинарного дерева в порядке LRN (post-order)
    void printPostOrder(TreeNode* node);

    // Рекурсивная функция для подсчета узлов в дереве
    int countNodes(TreeNode* root);

    // Рекурсивная функция для вычисления высоты дерева
    int height(TreeNode* root);

    // Рекурсивная функция для печати дерева в порядке LNR
    void printTree(TreeNode* node, int depth);
};
