#pragma once
#include <iostream>
#include<fstream>
#include <cstring>
#include<cstring>
#include <sstream>
#include "LinkedList.h"

using namespace std;

class UserManager
{
private:
    LinkedList<User> list;
    Treap<string, User*> tree;
public:
    void storeUser(string username, string name, string email) {
        User user(username, name, email);
        list.add(user);
    }

    bool loadUsersFromFile(string fileName)
    {
        string username, name, email;
        fstream file(fileName, ios::in);
        if (!file) return 0;
        file.seekg(0, ios::beg);
        while (!file.eof()) {
            getline(file, username, ',');
            getline(file, name, ',');
            getline(file, email, '\n');
            storeUser(username, name, email);
            file.peek();
        }
        file.close();
        return 1;
    }

    bool loadUsersRelationFromFile(string fileName)
    {
        string username1, username2;
        fstream file(fileName, ios::in);
        if (!file) return 0;
        file.seekg(0, ios::beg);
        while (!file.eof()) {
            getline(file, username1, ',');
            getline(file, username2, '\n');
            username2 = username2.substr(1, username2.size());
            storeFriends(username1, username2);
            storeFriends(username2, username1);
            file.peek();
        }
        file.close();
        return 1;
    }

    void storeFriends(string username1, string username2) {
        User* user1 = list.search(username1);
        User* user2 = list.search(username2);
        user1->addFrindsTree(username2, user2);
    }


    void searchByUsername(string username, User* user) {
        User* user1 = user->findFrinds(username);
        if (user1 == NULL) {
            cout << "Not found \n";
        }
        else
            cout << *user1 <<endl;
    }

    void addNewFriend(string username, User* user) {
        User* user1 = user->findFrinds(username);
        if (user1 == NULL) {
            User* user2 = list.search(username);
            user->addFrindsTree(username, user2);
            user2->addFrindsTree(user->getUsername(), user);
            cout << "You are now Friends" << endl;
        }
        else {
            cout << "You are already Friends" << endl;
        }
    }

    void removeFriend(string username, User* user) {
        User* user1 = user->findFrinds(username);
        if (user1 == NULL) {
            //do nothing
        }
        else {
            user->removeFriend(username, user1);
            user1->removeFriend(user->getUsername(), user);
            cout << "Done" << endl;
        }
    }

    void peopleYouMayKnow(User* user) {
        int c = 0;
        Node<User>* node = list.head;
        for (int i = 0; i < list.size(); i++) {
            if (user->findFrinds(node->data.getUsername()) == NULL && c < 5) {
                User* u = list.search(node->data.getUsername());
                if (user->getUsername() == u->getUsername())
                {
                    node = node->next; continue;
                }
                cout << u->getUsername() << "," << u->getName() << endl;
                c++;
                node = node->next;
            }
            else
                node = node->next;
        }
    }

    void listAllFriends(User* user) {
        Node<User>* node = list.head;
        for (int i = 0; i < list.size(); i++) {
            if (user->findFrinds(node->data.getUsername()) != NULL) {
                User* u = list.search(node->data.getUsername());
                cout << u->getUsername() << "," << u->getName() << endl;
                node = node->next;
            }
            else
                node = node->next;
        }
    }
    User* getUser(string username) {
        return list.search(username);
    }
    void display() {
        list.display();
    }
};
