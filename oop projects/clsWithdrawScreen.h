#pragma once
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsWithdrawScreen : protected clsScreen
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
    static string _ReadAccountNumber() {
        string AccountNumber = "";
        AccountNumber = clsInputValidate::ReadString();
        return AccountNumber;
    }
public :
    static void ShowWithDrawScreen() {
        string Title = "\t    Withdraw Screen.";
        _DrawScreenHeader(Title);
        string AccountNumber = _ReadAccountNumber();
        while (!clsBankClient::IsClientExist(AccountNumber))
        {
            cout << "\nClient with [" << AccountNumber << "]" << " does not exist.\n";
            AccountNumber = _ReadAccountNumber();
        }
        clsBankClient WithdrawClient = clsBankClient::Find(AccountNumber);
        _PrintClient(WithdrawClient);
        float WithdrawAmount = 0;
        cout << "\nPlease Enter Withdraw Amount ? ";
        WithdrawAmount = clsInputValidate::ReadFlNumber();
        cout << "Are you sure you want to perform this transaction? y/n: ";
        char Answer = 'n';
        cin >> Answer;
        if (Answer == 'y' || Answer == 'Y') {
            if (WithdrawClient.Withdraw(WithdrawAmount)) {
                cout << "Amount Withdrawed Successfully\n";
                cout << "New Balance is = " << WithdrawClient.AccountBalance << endl;
            }
            else {
                cout << "\nCannot Withdraw,Insuffecient Balance!\n";
                cout << "Amount To Withdraw Is : " << WithdrawAmount;
                cout<<"\nYour Balance Is : "<< WithdrawClient.AccountBalance << endl;

            }
        }
    }
};

