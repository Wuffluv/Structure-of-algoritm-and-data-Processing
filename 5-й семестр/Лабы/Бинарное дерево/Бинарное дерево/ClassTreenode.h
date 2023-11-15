// @author Rychkov R.V.
#pragma once


template <typename T>
class TreeNode {
public:
    T value;          // ��������, ���������� � ����
    TreeNode* left;    // ��������� �� ������ �������
    TreeNode* right;   // ��������� �� ������� �������

    // ����������� ���� ��������� ������
    TreeNode(T value);
};

template <typename T>
class Tree {
public:
    // ����������� ������ BinaryTree
    Tree();

    // ���������� ������ BinaryTree
    ~Tree();

    // ����� ��� ���������� �������� � �������� ������
    void add(T value);

    // ����� ��� ������ ��������� ��������� ������ � ������� LNR (in-order)
    void printInOrder();

    // ����� ��� ������ ��������� ��������� ������ � ������� NLR (pre-order)
    void printPreOrder();

    // ����� ��� ������ ��������� ��������� ������ � ������� LRN (post-order)
    void printPostOrder();

    // ����� �������� ������ � ��������� ���� ����� ������
    TreeNode<T>* getRoot() {
        return root;
    }

    // ����� ��� ������ ��������� ������
    void printTree();

    // ����������� ������� ��� �������� ����� � ������
    int countNodes(TreeNode<T>* root);

    // ����������� ������� ��� ���������� ������ ������
    int height(TreeNode<T>* root);

private:
    TreeNode<T>* root; // ��������� �� ������ ��������� ������

    // ����������� ������� ��� �������� ���� ����� ��������� ������
    void destroyTree(TreeNode<T>* node);

    // ����������� ������� ��� ���������� �������� � �������� ������
    void add(TreeNode<T>*& node, T value);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� LNR (in-order)
    void printInOrder(TreeNode<T>* node);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� NLR (pre-order)
    void printPreOrder(TreeNode<T>* node);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� LRN (post-order)
    void printPostOrder(TreeNode<T>* node);

    // ����������� ������� ��� ������ ������ 
    void printTree(TreeNode<T>* node, int depth);
};