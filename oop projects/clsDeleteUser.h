#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsDeleteUser : protected clsScreen
{
private :
    static void _PrintDeleteUser(clsUser& User)
    {

        cout << "\User Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << User.FirstName;
        cout << "\nLastName    : " << User.LastName;
        cout << "\nFull Name   : " << User.FullName();
        cout << "\nEmail       : " << User.Email;
        cout << "\nPhone       : " << User.Phone;
        cout << "\nUserName : " << User.UserName;
        cout << "\nPassword    : " << User.Password;
        cout << "\nPermissions : " << User.Permissions;
        cout << "\n___________________\n";

    }
public :
    static void DeleteUser() {
        string Title = "\tDelete User Screen.";
        _DrawScreenHeader(Title);
        UserAndDate();
        string UserName = "";
        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName))
        {
            cout << "\nUser Is Not Found, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }
        clsUser DeleteUser = clsUser::Find(UserName);
        _PrintDeleteUser(DeleteUser);
        cout << "\User To Delete\n";
        cout << "Are you sure you want to delete this user? y/n: ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (DeleteUser.Delete()) {
                cout << "\n User Deleted Successfully\n";
                _PrintDeleteUser(DeleteUser);
            }
            else {
                cout << "Error User Was Not Deleted\n";
            }

        }
    }
};

