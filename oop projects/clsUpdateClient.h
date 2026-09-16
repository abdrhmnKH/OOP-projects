#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScreen.h"
class clsUpdateClient : protected clsScreen
{
private :
    static void _PrintClient(clsBankClient& Client)
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
    static void ReadClientInfo(clsBankClient& Client)
    {
        cout << "\nEnter FirstName: ";
        Client.FirstName = clsInputValidate::ReadString();

        cout << "\nEnter LastName: ";
        Client.LastName = clsInputValidate::ReadString();

        cout << "\nEnter Email: ";
        Client.Email = clsInputValidate::ReadString();

        cout << "\nEnter Phone: ";
        Client.Phone = clsInputValidate::ReadString();

        cout << "\nEnter PinCode: ";
        Client.PinCode = clsInputValidate::ReadString();

        cout << "\nEnter Account Balance: ";
        Client.AccountBalance = clsInputValidate::ReadFlNumber();
    }
public :
    static void UpdateClient() {
        string Title = "Update Client.";
        _DrawScreenHeader(Title);
        string AccountNumber = "";
        cout << "\n Please Enter Client Account Number\n";
        AccountNumber = clsInputValidate::ReadString();
        while (!clsBankClient::IsClientExist(AccountNumber)) {
            cout << "\n Account Number is not found , choose another one\n";
            AccountNumber = clsInputValidate::ReadString();
        }
        clsBankClient UpdateClient = clsBankClient::Find(AccountNumber);
        UpdateClient.Print();
        cout << "\nUpdate Client Info\n";
        cout << "\n-------------------------------------\n";
        ReadClientInfo(UpdateClient);
        clsBankClient::enSaveResults SaveResults;
        SaveResults = UpdateClient.Save();
        switch (SaveResults) {
            case clsBankClient::enSaveResults::svSucceeded :{
                cout << "\n Account Updated Successfully\n";
                UpdateClient.Print();
                break;
            }
            case clsBankClient::enSaveResults::svFaildEmptyObject: {
                cout << "\n error Account was not saved because it is empty\n";
                break;
            }
        }
    }
};

