#include <iostream>
using namespace std;
#include "Node.h"
/*
Name: Norhan Abdelkader ALi
ID: 20190600
Group: S4
*/
int main()
{
    Node<int> *node = NULL;

    node = node->addNode(node, 6);
    node = node->addNode(node, 10);
    node = node->addNode(node, 9);
    node = node->addNode(node, 4);
    node = node->addNode(node, 11);
    node = node->addNode(node, 33);
    node = node->addNode(node, 1);
    node = node->addNode(node, 32);

    cout << "Display balanced AVL tree InOrder:\n";
    node->displayInOrder(node);

    cout << "\n===============================\n";
    cout << "Display balanced AVL tree PreOrder:\n";
    node->displayPreOrder(node);

    cout << "\n===============================\n";
    cout << "Display balanced AVL tree PostOrder:\n";
    node->displayPostOrder(node);

    cout << "\n===============================\n";

    node = node->removeNode(node, 9);

    cout << "Display balanced AVL tree InOrder After deletion of 9 node:\n";
    node->displayInOrder(node);

    cout << "\n===============================\n";

}
