#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsFindUserScreen : protected clsScreen
{
private :
    static void _PrintUser(clsUser& User)
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
        cout << "\nPermissions     : " << User.Permissions;
        cout << "\n___________________\n";
    }
public :
    static void FindUserScreen() {
        string Title = "\tFind User Screen";
        string UserName = "";
        _DrawScreenHeader(Title);
        UserAndDate();
        cout << "\nPlease Enter UserName\n";
        UserName = clsInputValidate::ReadString();
        while (!clsUser::IsUserExist(UserName)) {
            cout << "\User was not found , Enter another UserName\n";
            UserName = clsInputValidate::ReadString();
        }
        clsUser FindUser = clsUser::Find(UserName);
        if (!FindUser.IsEmpty()) {
            cout << "User Found :-)\n";
        }
        else {
            cout << "User was not Found\n";
        }
        _PrintUser(FindUser);
    }
};

