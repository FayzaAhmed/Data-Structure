#pragma once
#include <iostream>
using namespace std;
#include "Node.h"
#include "User.h"
template <class T>
class LinkedList
{
public:
public:
    Node<User>* head;
    //default constructor
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(T data) {
        this->data = data;
    }

    void add(T new_data) {
        Node<User>* new_node = new Node<User>();
        new_node->data = new_data;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            return;
        }
        else {
            Node<User>* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
            return;
        }
    }
    T* search(string username) {
        Node<User>* new_node = head;
        while (new_node->data.getUsername() != username)
        {
            new_node = new_node->next;
        }
        if (new_node->data.getUsername() == username)
            return &new_node->data;
        return NULL;
    }

    void display()
    {
        Node<User>* node = new Node<User>();
        node = head;
        while (node != NULL)
        {
            cout << node->data;
            node = node->next;
        }
    }


    int size() {
        int count = 0;
        Node<User>* temp = new Node<User>();
        temp = head;
        while (temp != NULL)
        {
            ++count;
            temp = temp->next;
        }
        return count;
    }

    //destructor
    ~LinkedList()
    {
        Node<User>* ptr = head;
        while (ptr != NULL)
        {
            head = head->next;
            delete ptr;
            ptr = head;
        }
    }
};

