// @author Rychkov R.V.
#pragma once

// ���������� ������ TreeNode ��� ������������� ���� ��������� ������

class TreeNode {
public:
    int value;           // ��������, ���������� � ����
    TreeNode* left;  // ��������� �� ������ �������
    TreeNode* right; // ��������� �� ������� �������

    // ����������� ���� ��������� ������
    TreeNode(int value);
};

// ���������� ������ Tree ��� ������������� ��������� ������

class Tree {
public:
    // ����������� ������ BinaryTree
    Tree();

    // ���������� ������ BinaryTree
    ~Tree();

    // ����� ��� ���������� �������� � �������� ������
    void add(int value);

    // ����� ��� ������ ��������� ��������� ������ � ������� LNR (in-order)
    void printInOrder();

    // ����� ��� ������ ��������� ��������� ������ � ������� NLR (pre-order)
    void printPreOrder();

    // ����� ��� ������ ��������� ��������� ������ � ������� LRN (post-order)
    void printPostOrder();
    
    //����� �������� ������ � ��������� ���� ����� ������
    TreeNode* getRoot() {
        return root;
    }

private:
    TreeNode* root; // ��������� �� ������ ��������� ������

    // ����������� ������� ��� �������� ���� ����� ��������� ������
    void destroyTree(TreeNode* node);

    // ����������� ������� ��� ���������� �������� � �������� ������
    void add(TreeNode*& node, int value);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� LNR (in-order)
    void printInOrder(TreeNode* node);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� NLR (pre-order)
    void printPreOrder(TreeNode* node);

    // ����������� ������� ��� ������ ��������� ��������� ������ � ������� LRN (post-order)
    void printPostOrder(TreeNode* node);

    // ����������� ������� ��� �������� ���� � ������
    int countNodes(TreeNode* root);
};
