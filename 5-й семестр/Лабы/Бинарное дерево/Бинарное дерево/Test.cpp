#include <iostream>
#include "ClassTreeNode.h"
#include <gtest/gtest.h>

using namespace std;

// ���� ��� ������� �������� �����
TEST(TreeTest, CountNodesTest) {
    Tree tree;
    EXPECT_EQ(0, countNodes(tree.getRoot())); // ��������� ������ ������

    // ��������� �������� � ������
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    EXPECT_EQ(6, countNodes(tree.getRoot())); // ��������� ���������� ������� ����� � ������
}

// ���� ��� ������� ����������� ������� ������
TEST(TreeTest, DepthTest) {
    Tree tree;
    EXPECT_EQ(0, height(tree.getRoot())); // ��������� ������� ������� ������

    // ��������� �������� � ������
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    EXPECT_EQ(3, height(tree.getRoot())); // ��������� ���������� ����������� ������� ������
}

// ���� ��� ������� �������� ������
TEST(TreeTest, DestroyTreeTest) {
    Tree tree;
    // ��������� �������� � ������
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    tree.destroyTree(tree.getRoot());
    EXPECT_EQ(nullptr, tree.getRoot()); // ���������, ��� ������ �������
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
