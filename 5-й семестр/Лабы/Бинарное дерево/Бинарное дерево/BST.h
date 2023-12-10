// @author Rychkov R.V.

#pragma once
#include "ClassTreenode.h"

template <typename T>
class BinarySearchTree : public Tree<T> {
public:
    // ����������� ������ BinarySearchTree
    BinarySearchTree();

    // ����������
    ~BinarySearchTree();

    // ����� ��� ���������� �������� � �������� ������ ������
    void insert(T value);

    // ����� ��� ������ �������� � �������� ������ ������
    bool search(T value);

    // ����� ��� �������� �������� �� ��������� ������ ������
    void remove(T value);


private:
    // ����������� ������� ��� �������� ���� ����� ������
    template <typename T>
    void deleteTree(TreeNode<T>* root);
};


