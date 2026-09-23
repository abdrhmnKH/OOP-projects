#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsAddNewUser : protected clsScreen
{
private :
    static enum _enPermissions {
        prShowClientsList = 1, prAddNewClient = 2,
        prDeleteClient = 4,
        prUpdateClient = 8,
        prFindClient = 16,
        prTransaction = 32,
        prManageUsers = 64
    };
    static void ReadUserInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter Password: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissions();
    }
    static void _PrintUser(clsUser& User)
    {

        cout << "\nClient Card:";
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
    bool _HasPermission(clsUser& User, _enPermissions Permission) {
        return ((User.Permissions & Permission) == Permission);
    }
    static int _ReadPermissions() {
        int permissions = 0;
        char answer = 'n';
        cout << "\nDo you want to give full access? y/n?";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            return -1;
        }
        cout << "\nDo you want to give access to : \n";
        cout << "\nShow Client List? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prShowClientsList;
        }
        cout << "\nAdd New Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prAddNewClient;
        }
        cout << "\nDelete Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prDeleteClient;
        }
        cout << "\nUpdate Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prUpdateClient;
        }
        cout << "\nFind Client? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prFindClient;
        }
        cout << "\nTransactions? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prTransaction;
        }
        cout << "\nManage Users? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prManageUsers;
        }
        return permissions;
    }
public :
    static void AddNewUser()
    {
        string Title = "Add New User.";
        _DrawScreenHeader(Title);
        UserAndDate();
        string UserName = "";

        cout << "\nPlease Enter UserName: ";
        UserName = clsInputValidate::ReadString();
        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nAccount Number Is Already Used, Choose another one: ";
            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);


        ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch (SaveResult)
        {
        case  clsUser::enSaveResults::svSucceeded:
        {
            cout << "\User Addeded Successfully :-)\n";
           _PrintUser(NewUser);
            break;
        }
        case clsUser::enSaveResults::svFaildEmptyObject:
        {
            cout << "\nError User was not saved because it's Empty";
            break;

        }
        case clsUser::enSaveResults::svFaildAccountNumberExists:
        {
            cout << "\nError User was not saved because UserName is used!\n";
            break;
        }
        }
    }
};

