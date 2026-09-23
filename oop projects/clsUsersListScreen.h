#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsScreen.h"
class clsUsersListScreen : protected clsScreen
{
private :
    static void PrintUsers(vector <clsUser> vUsers) {
        for (clsUser& User : vUsers) {
            cout << setw(8) << left << ""
                << "| " << left << setw(12) << User.UserName
                << "| " << left << setw(25) << User.FullName()
                << "| " << left << setw(12) << User.Phone
                << "| " << left << setw(20) << User.Email
                << "| " << left << setw(10) << User.Password
                << "| " << left << setw(12) << User.Permissions
                << endl;
        }
    }
public :
    static void ShowUsersList() {
        vector <clsUser> vUsers = clsUser::GetUsersList();
        string Title = "\t Users List Screen";
        string subtitle = "(" + to_string(vUsers.size()) + ")" + " User(s).";
        _DrawScreenHeader(Title, subtitle);
        UserAndDate();
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;

        cout << setw(8) << left << "" << "| " << left << setw(12) << "UserName";
        cout << "| " << left << setw(25) << "Full Name";
        cout << "| " << left << setw(12) << "Phone";
        cout << "| " << left << setw(20) << "Email";
        cout << "| " << left << setw(10) << "Password";
        cout << "| " << left << setw(12) << "Permissions";
        cout << setw(8) << left << "" << "\n\t_______________________________________________________";
        cout << "______________________________________________\n" << endl;
        PrintUsers(vUsers);
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
    }
};

