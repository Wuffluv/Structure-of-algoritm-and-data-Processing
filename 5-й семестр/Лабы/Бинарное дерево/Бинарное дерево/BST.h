// @author Rychkov R.V.

#pragma once
#include "ClassTreenode.h"

template <typename T>
class BinarySearchTree : public Tree<T> {
public:
    // Конструктор класса BinarySearchTree
    BinarySearchTree();

    // Деструктор
    ~BinarySearchTree();

    // Метод для добавления элемента в бинарное дерево поиска
    void insert(T value);

    // Метод для поиска элемента в бинарном дереве поиска
    bool search(T value);

    // Метод для удаления элемента из бинарного дерева поиска
    void remove(T value);


private:
    // Рекурсивная функция для удаления всех узлов дерева
    template <typename T>
    void deleteTree(TreeNode<T>* root);
};


