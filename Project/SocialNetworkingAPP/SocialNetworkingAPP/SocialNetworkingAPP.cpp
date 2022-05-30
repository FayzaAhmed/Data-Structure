#include <iostream>
#include"stdlib.h"
#include <fstream>
#include<string>
#include "UserManager.h"
using namespace std;
int main()
{
	UserManager* app = new UserManager();
	app->loadUsersFromFile("all-users.in");
	app->loadUsersRelationFromFile("all-users-relations.in");

    /* This was for test
    User* user = app->getUser("talaat3000");
    app->addNewFriend("soad91", user);
    app->display();*/

	int choice1, choice2;
    while (true)
    {
        cout << "------------------------------\n";
        cout << "Welcome to our application" << endl;
        cout << "1:Login" << endl;
        cout << "2:Exit" << endl;

        cin >> choice1;

        switch (choice1)
        {
        case 1:
        {
            string username;
            cout << "Enter your username, please : ";
            cin >> username;
            User* user = app->getUser(username);
            cout << "\nWelcome," << username << "! \n";

            do {
                cout << "------------------------------\n";
                cout << "All the features available for you " << endl;
                cout << "1: List all friends" << endl;
                cout << "2: Search by user name" << endl;
                cout << "3: Add friend" << endl;
                cout << "4: Remove friend" << endl;
                cout << "5: People you may know" << endl;
                cout << "6: logout" << endl;

                cin >> choice2;
                
                switch (choice2)
                {
                case 1:
                {
                    app->listAllFriends(user);
                    break;
                }

                case 2:
                {
                    string friendUserName;
                    cout << "Enter the friend's username : ";
                    cin >> friendUserName;
                    app->searchByUsername(friendUserName, user);
                    break;
                }

                case 3:
                {
                    string friendUserName;
                    cout << "Enter your friend's username that you want to add : ";
                    cin >> friendUserName;
                    app->addNewFriend(friendUserName, user);
                    break;
                }

                case 4:
                {
                    string friendUserName;
                    cout << "Enter your friend's name that you want to remove : ";
                    cin >> friendUserName;
                    app->removeFriend(friendUserName, user);
                    break;
                }

                case 5:
                {
                    app->peopleYouMayKnow(user);
                    break;
                }

                case 6:
                {
                    cout << "logged out successfully \n";
                    break;
                }

                default:
                    cout << "please enter a number from 1 to 6" << endl;

                }//end of inner switch 
            } while (choice2 != 6);

            break;
        }

        case 2:
        {
            exit(0);
            break;
        }

        default:
            cout << "please enter 1 or 2" << endl;
   
        }//end of outer switch end

    }

    return 0;
}


