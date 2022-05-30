#pragma once
#include <iostream>
using namespace std;
template<class T, class V>
class Treap
{
    class Node {
    public:
        Node* left, * right;
        T key;
        V value;
        int priority;

        Node(T k, V v)
        {
            key = k;
            value = v;
            priority = rand() % 100;
            left = right = NULL;
        }

        friend void printInOrder(Treap<T, V>::Node* root) {
            if (root) {
                printInOrder(root->left);
                cout << root->key << endl;
                printInOrder(root->right);
            }
        }

        friend ostream& operator<<(ostream& os, Treap<T, V>::Node* root) {
            printInOrder(root);
            return os;
        }
    };

private:
    Node* root;

    Node* right_rotate(Node* node)
    {
        Node* mid_node = node->left;
        Node* temporary = mid_node->right;

        mid_node->right = node;
        node->left = temporary;

        return mid_node;
    }

    Node* left_rotate(Node* node)
    {
        Node* mid_node = node->right;
        Node* temporary = mid_node->left;

        mid_node->left = node;
        node->right = temporary;

        return mid_node;
    }

    Node* insert(Node* r, T k, V v) {
        // If root is NULL, create a new node and return it
        if (r == NULL) {
            Node* temp = new Node(k, v);
            return temp;
        }

        // If key is smaller than root
        if (k <= r->key)
        {
            // Insert in left subtree
            r->left = insert(r->left, k, v);

            // Fix Heap property if it is violated
            if (r->left->priority > r->priority)
                r = right_rotate(r);
        }
        else  // If key is greater
        {
            // Insert in right subtree
            r->right = insert(r->right, k, v);

            // Fix Heap property if it is violated
            if (r->right->priority > r->priority)
                r = left_rotate(r);
        }
        return r;
    }

    Node* remove(Node* r, T k, V v) {
        // If root is NULL, create a new node and return it
        if (r == NULL) {
            return NULL;
        }

        // If key is smaller than root
        if (k < r->key) {
            // remove in left subtree
            r->left = remove(r->left, k, v);
        }
        else if (k > r->key) // If key is greater
        {
            // remove in right subtree
            r->right = remove(r->right, k, v);
        }
        else {
            // node has no child
            if (r->left == NULL && r->right == NULL) {
                delete r;
                r = NULL;
            }
            // node has two child
            else if (r->left && r->right) {
                if (r->right->priority > r->left->priority) {
                    r = left_rotate(r);
                    r->left = remove(r->left, k, v);
                }
                else {
                    r = right_rotate(r);
                    r->right = remove(r->right, k, v);
                }
            }
            // node has one child
            else {
                // choose a child node
                Node* child = (r->left) ? r->left : r->right;
                Node* curr = r;

                r = child;

                delete curr;
            }
        }
        return r;
    }

    V find(Node* r, T k) {
        // Base Cases: root is null or key is present at root
        if (r == NULL)
            return 0;

        else if (r->key == k)
            return r->value;

        // Key is greater than root's key
        if (r->key < k)
            return find(r->right, k);

        // Key is smaller than root's key
        return find(r->left, k);
    }

public:
    Treap() {
        root = NULL;
    }
    void insert(T k, V v) {
        root = this->insert(root, k, v);
    }
    V find(T k) {
        return this->find(root, k);
    }
    void remove(T k, V v) {
        root = remove(root, k, v);
    }
    friend ostream& operator<<(ostream& out, Treap<T, V> tree) {
        out << tree.root;
        return out;
    }
};
