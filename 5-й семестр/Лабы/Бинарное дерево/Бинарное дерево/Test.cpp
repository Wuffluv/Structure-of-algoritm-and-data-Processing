#include <iostream>
#include "ClassTreeNode.h"
#include <gtest/gtest.h>

using namespace std;

// Тест для функции подсчета узлов
TEST(TreeTest, CountNodesTest) {
    Tree tree;
    EXPECT_EQ(0, countNodes(tree.getRoot())); // Проверяем пустое дерево

    // Добавляем элементы в дерево
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    EXPECT_EQ(6, countNodes(tree.getRoot())); // Проверяем корректное подсчет узлов в дереве
}

// Тест для функции определения глубины дерева
TEST(TreeTest, DepthTest) {
    Tree tree;
    EXPECT_EQ(0, height(tree.getRoot())); // Проверяем глубину пустого дерева

    // Добавляем элементы в дерево
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    EXPECT_EQ(3, height(tree.getRoot())); // Проверяем корректное определение глубины дерева
}

// Тест для функции удаления дерева
TEST(TreeTest, DestroyTreeTest) {
    Tree tree;
    // Добавляем элементы в дерево
    tree.add(10);
    tree.add(5);
    tree.add(15);
    tree.add(2);
    tree.add(7);
    tree.add(12);

    tree.destroyTree(tree.getRoot());
    EXPECT_EQ(nullptr, tree.getRoot()); // Проверяем, что дерево удалено
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
