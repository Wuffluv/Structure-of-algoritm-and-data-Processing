//@author Rychkov R.V.
#include <iostream>
#include "ClassTreenode.h"
#include <queue>
#include "BST.h"

using namespace std;

// ���������� ������������ ��� ���� ��������� ������
template <typename T>
TreeNode<T>::TreeNode(T value) {
    this->value = value;
    this->left = nullptr;
    this->right = nullptr;
}


// ���������� ������������ ��� ��������� ������
template <typename T>
Tree<T>::Tree() {
    root = nullptr; // ���������� ������ ������ ��������������� ��� nullptr
}

// ���������� ������������ �����������
template <typename T>
Tree<T>::Tree(const Tree<T>& other) {
    copyTree(root, other.root);
}

// ���������� ����������� ��� ��������� ������
template <typename T>
Tree<T>::~Tree() {
    destroyTree(root); // ��� �������� ������� ������ ����� ��������� ���� ������
}

// ����������� ������� ��� �������� ������
template <typename T>
void Tree<T>::destroyTree(TreeNode<T>* root) {
    if (root != nullptr) {
        return;

        destroyTree(root->left); 
        destroyTree(root->right); 

        delete root; // �������� ����� 

    }
    root = nullptr;
}

/// �������� ������ ����
template <typename T>
void deleteNode(TreeNode<T>* node) {
    delete node;
}

// ����� ��� ���������� �������� � ������
template <typename T>
void Tree<T>::add(T value) {
    add(root, value);
}

// ����������� ������� ��� ���������� �������� � �������� ������
template <typename T>
void Tree<T>::add(TreeNode<T>*& node, T value) {
    if (node == nullptr) {
        node = new TreeNode<T>(value); // ���� ���� ������, ������� ����� ���� � �������� ���������
    }
    else if (value <= node->value) {
        add(node->left, value); // ���� �������� ������ ��� ����� �������� ����, ���������� ��������� � ����� ���������
    }
    else {
        add(node->right, value); // ����� ���������� ��������� � ������ ���������
    }
}

// ����� ��� ������ ������ � ������� LNR (in-order)
template <typename T>
void Tree<T>::printInOrder() {
    printInOrder(root);
    cout << std::endl;
}

// ����������� ������� ��� ������ ������ � ������� LNR (in-order)
template <typename T>
void Tree<T>::printInOrder(TreeNode<T>* node) {
    if (node) {
        printInOrder(node->left); // ������� ������� ����� ���������
        cout << node->value << " "; // ����� ������� �������� �������� ����
        printInOrder(node->right); // ����� ������� ������ ���������
    }
}

// ����� ��� ������ ������ � ������� NLR (pre-order)
template <typename T>
void Tree<T>::printPreOrder() {
    printPreOrder(root);
    cout << std::endl;
}

// ����������� ������� ��� ������ ������ � ������� NLR (pre-order)
template <typename T>
void Tree<T>::printPreOrder(TreeNode<T>* node) {
    if (node) {
        cout << node->value << " "; // ������� ������� �������� �������� ����
        printPreOrder(node->left); // ����� ������� ����� ���������
        printPreOrder(node->right); // ����� ������� ������ ���������
    }
}

// ����� ��� ������ ������ � ������� LRN (post-order)
template <typename T>
void Tree<T>::printPostOrder() {
    printPostOrder(root);
    cout << std::endl;
}

// ����������� ������� ��� ������ ������ � ������� LRN (post-order)
template <typename T>
void Tree<T>::printPostOrder(TreeNode<T>* node) {
    if (node) {
        printPostOrder(node->left); // ������� ������� ����� ���������
        printPostOrder(node->right); // ����� ������� ������ ���������
        cout << node->value << " "; // ����� ������� �������� �������� ����
    }
}

// ����������� ������� ��� �������� ���� � ������
template <typename T>
int Tree<T>::countNodes(TreeNode<T>* root) {
    if (root == nullptr) {
        return 0; // ���� ������ ������, ���������� 0
    }
    else {
        return 1 + countNodes(root->left) + countNodes(root->right); // ���������
    }
}

// ����������� ������� ��� ���������� ������ ������
template <typename T>
int Tree<T>::height(TreeNode<T>* root) {
    // ������� ������, ���� ������ ������ ����� ������ 0
    if (root == nullptr) {
        return 0;
    }
    // ��������� ��� ������ � ������� ��������� � ��������� ������������ �������
    return 1 + std::max(height(root->left), height(root->right));
}

// ����������� ������� ��� ������ ��������� ������ � ������� NLR
template <typename T>
void Tree<T>::printTree(TreeNode<T>* node, int depth) {
    if (node) {
        printTree(node->left, depth + 1); // ������� ����� ���������
        for (int i = 0; i < depth; i++) {
            cout << "   "; // ������ ��� �����������
        }
        cout << node->value << endl; // ������� �������� �������� ����
        printTree(node->right, depth + 1); // ����� ������� ������ ���������
    }
}

// ����� ��� ������ ��������� ������
template <typename T>
void Tree<T>::printTree() {
    printTree(root, 0);
    cout << endl;
}



// ���������� ����������� ������� ����������� ����� ��������� ������
template <typename T>
void Tree<T>::copyTree(TreeNode<T>*& destination, const TreeNode<T>* source) {
    if (source) {
        destination = new TreeNode<T>(source->value);//Destination - node
        copyTree(destination->left, source->left);//������ � ����� � left, ������ � left
        copyTree(destination->right, source->right);///������ � ����� � right, ������ � right
        //������� NLR
    }
    else {
        destination = nullptr;
    }
}

//����� ��� �������� ����� ������
template <typename T>
Tree<T> Tree<T>::copy() {
    Tree<T> copiedTree;
    copiedTree.copyTree(copiedTree.root, root);
    return copiedTree;
}

// ����� ��� ��������� ������� �������� ����� ������ � ������� ������ � ������
template <typename T>
std::vector<T> Tree<T>::toArray() {
    std::vector<T> result;
    if (!root)
        return result; // ���� ������ �����, ������ ������ ������

    std::queue<TreeNode<T>*> nodeQueue; // ������� ������� ��� ����� ������
    nodeQueue.push(root); // ��������� �������� ���� � �������

    while (!nodeQueue.empty()) { // ���� ������� �� �����
        TreeNode<T>* current = nodeQueue.front(); // �������� ������ ���� � �������
        nodeQueue.pop(); // ������� ������ ���� �� �������

        result.push_back(current->value); // ��������� �������� �������� ���� � ������

        if (current->left)
            nodeQueue.push(current->left); // ���� ���� ����� �������, ��������� ��� � �������

        if (current->right)
            nodeQueue.push(current->right); // ���� ���� ������ �������, ��������� ��� � �������
    }

    return result;
}



// ���������� ������������ ������ BST
template <typename T>
BinarySearchTree<T>::BinarySearchTree() : Tree<T>() {}

// ���������� ������ ��� ���������� �������� � �������� ������ ������
template <typename T>
void BinarySearchTree<T>::insert(T value) {
    this->add(value);
}

// ���������� ������ ��� ������ �������� � �������� ������ ������
template <typename T>
bool BinarySearchTree<T>::search(T value) {
    TreeNode<T>* current = this->getRoot(); // ������������� ������� ���� � ������ ������
    while (current) { // ���� ������� ���� ����������
        if (value == current->value) {
            return true; // ���� �������� �������� ���� ��������� � �������, ������� ������
        }
        else if (value < current->value) {
            current = current->left; // ���� ������� �������� ������ �������� �������� ����, ��������� � ������ �������
        }
        else {
            current = current->right; // ���� ������� �������� ������ �������� �������� ����, ��������� � ������� �������
        }
    }
    return false; // ������� �� ������
}


// ���������� ������ ��� �������� �������� �� ��������� ������ ������
template <typename T>
void BinarySearchTree<T>::remove(T value) {
    // ���������� �������� �������� �� ��������� ������ ������
    
}
