#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsDepositScreen : protected clsScreen
{
private:
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
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        cout << "Please Enter Account Number ? ";
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }
public :
    static void ShowDepositScreen() {
        string Title = "\t    Deposit Screen.";
        _DrawScreenHeader(Title);
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "]" << " does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient DepositClient = clsBankClient::Find(AccountNumber);
        _PrintClient(DepositClient);
        float DepositAmount = 0;
        cout << "\nPlease Enter Deposit Amount ? ";
        DepositAmount = clsInputValidate::ReadFlNumber();
        cout << "Are you sure you want to perform this transaction? y/n: ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            DepositClient.Deposit(DepositAmount);
            cout << "Amount Deposited Successfully\n";
            cout << "New Balance is = " << DepositClient.AccountBalance << endl;
        }
        else {
            cout << "\nOperation was cancelled.\n";
        }
    }
};

