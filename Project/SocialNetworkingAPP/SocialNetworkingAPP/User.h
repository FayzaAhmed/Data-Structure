#pragma once
#include <iostream>
#include"Treap.h"
using namespace std;
class User
{
private:
    string username, name, email;
    Treap<string, User*> friendTree; //friendsBST
public:
    User() {
        username = "";
        name = "";
        email = "";
    }
    User(string username, string name, string email) {
        this->username = username;
        this->name = name;
        this->email = email;

    }

    void setUsername(string username) {
        this->username = username;
    }
    string getUsername() {
        return username;
    }

    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }

    void setEmail(string email) {
        this->email = email;
    }
    string getEmail() {
        return email;
    }

    void addFrindsTree(string username, User* user) {
        this->friendTree.insert(username, user);
    }

    User* findFrinds(string username) {
        return this->friendTree.find(username);
    }

    void removeFriend(string username, User* user) {
        this->friendTree.remove(username, user);
    }

    User& operator = (User& obj) {
        username = obj.username;
        name = obj.name;
        email = obj.email;
        return *this;
    }

    friend ostream& operator<<(ostream& os, const User& obj)
    {
        os << obj.username << ',' << obj.name << ',' << obj.email << endl;
        return os;
    }
};
