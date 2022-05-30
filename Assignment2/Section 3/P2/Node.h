#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
#include <iostream>
using namespace std;

template <class T>
class Node
{
private:
    T value;
    int height;
    Node *rightChildNode;
    Node *leftChildNode;

public:
    int getNodeHeight(Node *n);
    int getNodeBlncFact(Node *n);
    int getMax(int h1, int h2);
    int returnCurrentHeight(Node *n);

    Node *rotateRight(Node *n);
    Node *rotateLeft(Node *n);

    Node *addNode(Node *n, T v);
    Node *removeNode(Node *n, T v);

    void displayInOrder(Node *n);
    void displayPreOrder(Node *n);
    void displayPostOrder(Node *n);
};
#endif // NODE_H_INCLUDED

template <class T>
int Node<T>::returnCurrentHeight(Node *node)
{
    if (node != NULL)
    {
        return node->height;
    }
    else
    {
        return 0;
    }
}
template <class T>
int Node<T>::getNodeHeight(Node *node)
{
    if (node == NULL)
    {
        return 0;
    }
    int leftHeight = returnCurrentHeight(node -> leftChildNode);
    int rightHeight = returnCurrentHeight(node->rightChildNode);
    node->height = 1 + (getMax(leftHeight , rightHeight));
    return node->height;
}

template <class T>
int Node<T>::getNodeBlncFact(Node *node)
{
    int leftHeight = returnCurrentHeight(node -> leftChildNode);
    int rightHeight = returnCurrentHeight(node->rightChildNode);

    int nodeBlncFact = leftHeight - rightHeight;
    return nodeBlncFact;
}

template <class T>
int Node<T>::getMax(int h1, int h2)
{
    if (h1 > h2)
    {
        return h1;
    }
    else
    {
        return h2;
    }
}

template <class T>
Node<T>* Node<T>::rotateRight(Node<T> *node)
{
    //Get the left child node and its right child node.
    //Create a new node (leftNode) and make (node) its right child and create the link between them.
    Node<T>* leftNode = node -> leftChildNode;
    Node<T>* leftNodeRightChild = leftNode -> rightChildNode;

    leftNode -> rightChildNode = node;
    node -> leftChildNode = leftNodeRightChild;
    //Update Height of leftNode and node
    node -> height = getNodeHeight(node);
    leftNode -> height = getNodeHeight(leftNode);
    return leftNode;
}

template <class T>
Node<T>* Node<T>::rotateLeft(Node<T> *node)
{
    //Get the right child node and its left child node.
    //Create a new node (rightNode) and make (node) its left child and create the link between them.
    Node<T>* rightNode = node -> rightChildNode;
    Node<T>* rightNodeLeftChild = rightNode -> leftChildNode;

    rightNode -> leftChildNode = node;
    node -> rightChildNode = rightNodeLeftChild;
    //Update Height of rightNode and node
    node -> height = getNodeHeight(node);
    rightNode -> height = getNodeHeight(rightNode);
    return rightNode;
}

template <class T>
Node<T>* Node<T>::addNode(Node<T> *currNode, T val)
{
    //First find the correct position to add the node
    if (currNode == NULL)
    {
        Node<T>* newNode = new Node();
        newNode -> value = val;
        newNode -> height = 1;
        newNode -> rightChildNode = NULL;
        newNode -> leftChildNode = NULL;
        return newNode;
    }
    //Avoid duplication
    if (currNode -> value == val)
    {
        return currNode;
    }

    //Insert as right child
    if (currNode -> value < val)
    {
        currNode -> rightChildNode = addNode(currNode -> rightChildNode, val);
    }
    //When value less than the current node’s value
    //Insert as left child
    else
    {
        currNode -> leftChildNode = addNode(currNode -> leftChildNode, val);
    }

    //Second update the height and balance factor values to check if the AVL tree is balanced or not
    currNode -> height = getNodeHeight(currNode);
    int currNodeBalance = getNodeBlncFact(currNode);
    Node* rotatedNode;

    //If the AVL tree is unbalanced.
    //Right Right Case --> Single left rotation
    if ((currNodeBalance < -1) && (currNode -> rightChildNode -> value < val))
    {
        rotatedNode = rotateLeft(currNode);
        return rotatedNode;
    }
    //Right Left Case --> Double rotation [single right rotation to the right child then single left rotation to the node]
    else if ((currNodeBalance < -1) && (currNode -> rightChildNode -> value > val))
    {
        currNode -> rightChildNode = rotateRight(currNode -> rightChildNode);
        rotatedNode = rotateLeft(currNode);
        return rotatedNode;
    }

    //Left Left Case --> Single right rotation
    else if ((currNodeBalance > 1) && (currNode -> leftChildNode -> value > val))
    {
        rotatedNode = rotateRight(currNode);
        return rotatedNode;
    }

    //Left Right Case --> Double rotation [single left rotation to the left child then single right rotation to the node]
    else if((currNodeBalance > 1) && (currNode -> leftChildNode -> value < val))
    {
        currNode -> leftChildNode = rotateLeft(currNode -> leftChildNode);
        rotatedNode = rotateRight(currNode);
        return rotatedNode;
    }

    //The AVL is balanced
    else
    {
        return currNode;
    }

}
template <class T>
Node<T>* Node<T>::removeNode(Node<T> *currNode,  T val)
{
    //First Find the node and delete it
    if(currNode == NULL)
    {
        return NULL;
    }

    if(currNode -> value == val)
    {
        Node* tmpNode = currNode;
        //Leaf node
        if ((tmpNode ->leftChildNode == NULL) && (tmpNode ->rightChildNode == NULL))
        {
            return NULL;
        }
        //Node has one right child
        else if((tmpNode ->leftChildNode == NULL) && (tmpNode ->rightChildNode != NULL))
        {
            currNode = currNode -> rightChildNode;
            delete tmpNode;
        }
        //Node has one left child
        else if((tmpNode ->leftChildNode != NULL) && (tmpNode ->rightChildNode == NULL))
        {
            currNode = currNode -> leftChildNode;
            delete tmpNode;
        }
        //Node has two children
        //Get the left most node in right sub-tree(successor) and put it instead of the node(removed)
        else
        {
            Node* leftMostNode = currNode -> rightChildNode;
            while (leftMostNode -> leftChildNode != NULL)
            {
                leftMostNode=leftMostNode -> leftChildNode;
            }
            currNode -> value = leftMostNode -> value;
            currNode -> rightChildNode = removeNode(currNode -> rightChildNode, leftMostNode -> value);
        }
    }
    else if(val > currNode -> value)
    {
        currNode -> rightChildNode = removeNode(currNode -> rightChildNode, val);
    }
    //val < currNode -> value
    else
    {
        currNode -> leftChildNode = removeNode( currNode -> leftChildNode,val);
    }

    //Second update the height and balance factor values to check if the AVL tree is balanced or not
    currNode -> height = getNodeHeight(currNode);
    int currNodeBalance = getNodeBlncFact(currNode);
    Node* rotatedNode;

    //If the AVL tree is unbalanced.
    //Right Right Case --> Single left rotation
    if ((currNodeBalance < -1) && (getNodeBlncFact(currNode->rightChildNode) <= 0))
    {
        rotatedNode = rotateLeft(currNode);
        return rotatedNode;
    }

    //Right Left Case --> Double rotation [single right rotation to the right child then single left rotation to the node]
    if ((currNodeBalance) < -1 && (getNodeBlncFact(currNode->rightChildNode) > 0))
    {
        currNode->rightChildNode = rotateRight(currNode->rightChildNode);
        rotatedNode = rotateLeft(currNode);
        return rotatedNode;
    }

    //Left Left Case --> Single right rotation
    if ((currNodeBalance > 1) && (getNodeBlncFact(currNode->leftChildNode) >= 0))
    {
        rotatedNode = rotateRight(currNode);
        return rotatedNode;
    }

    //Left Right Case --> Double rotation [single left rotation to the left child then single right rotation to the node]
    if ((currNodeBalance > 1) && (getNodeBlncFact(currNode->leftChildNode) < 0))
    {
        currNode -> leftChildNode = rotateLeft(currNode -> leftChildNode);
        rotatedNode = rotateRight(currNode);
        return rotatedNode;
    }

    //The AVL is balanced
    else
    {
        return currNode;
    }

}

//Left Top Right
template <class T>
void Node<T>::displayInOrder(Node<T> *node)
{
    if (node != NULL)
    {
        displayInOrder(node -> leftChildNode);
        cout << node -> value << " ";
        displayInOrder(node -> rightChildNode);
    }
    else
    {
        return;
    }
}

//Top Left Right
template <class T>
void Node<T>::displayPreOrder(Node<T> *node)
{
    if (node != NULL)
    {
        cout << node -> value << " ";
        displayPreOrder(node -> leftChildNode);
        displayPreOrder(node -> rightChildNode);
    }
    else
    {
        return;
    }
}

//Left Right Top
template <class T>
void Node<T>::displayPostOrder(Node<T> *node)
{
    if (node != NULL)
    {
        displayPostOrder(node -> leftChildNode);
        displayPostOrder(node -> rightChildNode);
        cout << node -> value << " ";
    }
    else
    {
        return;
    }
}
