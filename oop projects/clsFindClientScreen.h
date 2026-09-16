#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsFindClientScreen : protected clsScreen
{
private :
    static void _PrintFindClient(clsBankClient& Client)
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
    static void FindClientScreen() {
        string Title = "\tFind Client Screen";
        string AccountNumber = "";
        _DrawScreenHeader(Title);
        cout << "\nPlease Enter Account Number\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\nClient was not found , Enter another Account Number\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient FindClient = clsBankClient::Find(AccountNumber);
        if (!FindClient.IsEmpty()) {
            cout << "Client Found :-)\n";
        }
        else {
            cout << "Client was not Found\n";
        }
        _PrintFindClient(FindClient);
    }
};

