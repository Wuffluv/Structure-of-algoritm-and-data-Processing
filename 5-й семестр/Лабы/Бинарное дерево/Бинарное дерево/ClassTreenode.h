// @author Rychkov R.V.
#pragma once

// ���������� ������ TreeNode ��� ������������� ���� ��������� ������
//todo: ������� ����� ��������� 
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

    // ����� ��� ������ ��������� ������
    void printTree();

private:
    //todo: ��������� ������� ������ � ����� ��� ������
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

    // ����������� ������� ��� �������� ����� � ������
    int countNodes(TreeNode* root);

    // ����������� ������� ��� ���������� ������ ������
    int height(TreeNode* root);

    // ����������� ������� ��� ������ ������ � ������� LNR
    void printTree(TreeNode* node, int depth);
};
