#pragma once
#include <iostream>
#include <iomanip>
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsUpdateUserScreen : protected clsScreen
{
private :
    static enum _enPermissions {
        prShowClientsList = 1, prAddNewClient = 2,
        prDeleteClient = 4,
        prUpdateClient = 8,
        prFindClient = 16,
        prTransaction = 32,
        prManageUsers = 64,
        prShowLoginRegister=128
    };
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
        cout << "\Show Login Register ? y/n? ";
        cin >> answer;
        if (answer == 'y' || answer == 'Y') {
            permissions |= _enPermissions::prShowLoginRegister;
        }
        return permissions;
    }
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
    static void ReadClientInfo(clsUser& User)
    {
        cout << "\nEnter FirstName: ";
        User.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        User.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        User.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        User.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        User.Password = clsInputValidate::ReadString();

        cout << "\nEnter Permissions: ";
        User.Permissions = _ReadPermissions();
    }
    public:
        static void UpdateUser() {
            string Title = "\nUpdate User Screen.";
            _DrawScreenHeader(Title);
            UserAndDate();
            string UserName = "";
            cout << "\n Please Enter User UserName\n";
            UserName = clsInputValidate::ReadString();
            while (!clsUser::IsUserExist(UserName)) {
                cout << "\n UserName is not found , choose another one\n";
                UserName = clsInputValidate::ReadString();
            }
            clsUser UpdateClient = clsUser::Find(UserName);
            _PrintUser(UpdateClient);
            cout << "\nUpdate User Info\n";
            cout << "\n-------------------------------------\n";
            ReadClientInfo(UpdateClient);
            clsUser::enSaveResults SaveResults;
            SaveResults = UpdateClient.Save();
            switch (SaveResults) {
            case clsUser::enSaveResults::svSucceeded: {
                cout << "\n User Updated Successfully\n";
                UpdateClient.Print();
                break;
            }
            case clsUser::enSaveResults::svFaildEmptyObject: {
                cout << "\n error User was not saved because it is empty\n";
                break;
            }
            }
        }
};

