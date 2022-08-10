//
//  main.cpp
//  Login System
//
//  Created by Ryan Breeden on 8/8/22.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIN()
{
    string username, password, un, pw;
    
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;
    
    ifstream read("details.txt");
    getline(read, un);
    getline(read, pw);
    
    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int choice;
    
    cout << "1. Login\n2. Register\nEnter Selection: ";
    cin >> choice;
    
    if (choice == 1)
    {
        bool status = IsLoggedIN();
        
        if (!status) //If user login is entered incorrectly, status will not be true.
        {
            cout << "False Login, please try again!!\n";
            system("read -p 'Press Enter to continue...' var"); //Prompts user to press enter to continue.
            
            return 0;
        }
        else
        {
            cout << "Successful Login\n";
            system("read -p 'Press Enter to continue...' var"); //Prompts user to press enter to continue.
            
            return 1; //Returning value 1 to continue program.
        }
    }
    else if (choice == 2)
    {
        string username, password;
        
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        
        ofstream file;
        file.open("details.txt");
        file << username << "\n" << password;
        file.close();
        
        main();
    }
}
