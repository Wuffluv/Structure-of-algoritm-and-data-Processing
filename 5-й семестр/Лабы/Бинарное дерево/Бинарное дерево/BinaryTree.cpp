// @author Rychkov R.V.
#include <iostream>
#include "ModulTree.cpp"


using namespace std;

int main() {
    setlocale(LC_ALL, "RUS");
    Tree<int> tree;

    //todo: функция создания дерева на основе узлов

    tree.add(2);
    tree.add(5);
    tree.add(7);
    tree.add(10);
    tree.add(12);
    tree.add(15);
    tree.add(17);

    cout << "LNR: ";
    tree.printInOrder(); // Выводим дерево в порядке вставки

    cout << "NLR: ";
    tree.printPreOrder(); // Выводим дерево в порядке префикса

    cout << "LRN: ";
    tree.printPostOrder(); // Выводим дерево в порядке постфикса

    // Подсчитываем количество узлов в дереве
    int nodeCount = tree.countNodes(tree.getRoot());

    // Выводим результат количества узлов в дереве
    cout << "Количество узлов в дереве: " << nodeCount << endl;

    // Выводим глубину дерева
    cout << "Глубина дерева: " << tree.height(tree.getRoot()) << endl;

    cout << "Структура дерева NLR " << endl;
    tree.printTree(); // Печатаем структуру дерева

    // Создаем копию дерева
    Tree<int> copiedTree = tree.copy();

    cout << "Копия дерева LNR: ";
    copiedTree.printInOrder();

    // Получаем массив значений узлов дерева в порядке обхода в ширину
    std::vector<int> treeArray = tree.toArray();

    // Выводим обход дерева в ширину
    cout << "В ширину: ";
    for (const auto& value : treeArray) {
        cout << value << " ";
    }
    cout << endl;

    return 0;
}