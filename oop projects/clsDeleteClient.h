#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsDeleteClient : protected clsScreen
{
private :
    static void _PrintDeleteClient(clsBankClient & Client)
    {

        cout << "\nClient Card:";
        cout << "\n___________________";
        cout << "\nFirstName   : " << Client.FirstName;
        cout << "\nLastName    : " << Client.LastName;
        cout << "\nFull Name   : " << Client.FullName();
        cout << "\nEmail       : " << Client.Email;
        cout << "\nPhone       : " << Client.Phone;
        cout << "\nAcc. Number : " << Client.AccountNumber();
        cout << "\nPassword    : " << Client.PinCode;
        cout << "\nBalance     : " << Client.AccountBalance;
        cout << "\n___________________\n";

    }
public :
   static void DeleteClient() {
       if (!CheckAccessRights(clsUser::_enPermissions::prDeleteClient)) {
           return;
       }
        string Title = "Delete Client.";
        _DrawScreenHeader(Title);
        string AccountNumber = "";
        cout << "\nPlease Enter Account Number: ";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nAccount Number Is Not Found, Choose another one: ";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
        _PrintDeleteClient(DeleteClient);
        cout << "\nClient To Delete\n";
		cout << "Are you sure you want to delete this client? y/n: ";
		char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (DeleteClient.Delete()) {
                cout << "\n Client Deleted Successfully\n";
                    DeleteClient.Print();
            }
            else {
                cout << "Error Client Was Not Deleted\n";
            }

        }
    }
};

