#pragma once
#include <iostream>
#include <iomanip>
#include "clsBankClient.h"
#include "clsScreen.h"
class clsClientListScreen : protected clsScreen
{
private :
    static void PrintClients(vector <clsBankClient> vClients) {
        for (clsBankClient& C : vClients) {
            cout << setw(15) << C.FirstName << setw(15) << C.LastName << setw(25) << C.Email << setw(15) << C.Phone << setw(15) << C.AccountNumber() << setw(15) << C.PinCode << setw(15) << C.AccountBalance << endl;
        }
    }
public :
    static void ShowClientList() {
        vector <clsBankClient> vClients = clsBankClient::GetClientsList();
        string Title = "Clients List Screen";
        string subtitle = "(" + to_string(vClients.size()) + ")" + " Clients.";
        _DrawScreenHeader(Title,subtitle);
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        cout << setw(15) << "FirstName" << setw(15) << "LastName" << setw(25) << "Email" << setw(15) << "Phone" << setw(15) << "Acc. Number" << setw(15) << "PinCode" << setw(15) << "Balance" << endl;
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
        PrintClients(vClients);
        cout << "------------------------------------------------------------------------------------------------------------------------\n";
    }
};

