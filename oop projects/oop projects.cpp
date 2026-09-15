#include <iostream>
#include <iomanip>
#include "clsPerson.h"
#include "clsBankClient.h"
#include "clsInputValidate.h"

void ReadClientInfo(clsBankClient& Client)
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
void PrintClients(vector <clsBankClient> vClients) {
    for (clsBankClient& C : vClients) {
        cout << setw(15) << C.FirstName << setw(15) << C.LastName << setw(25) << C.Email << setw(15) << C.Phone << setw(15) << C.AccountNumber() << setw(15) << C.PinCode << setw(15) << C.AccountBalance << endl;
    }
}
void AddNewClient()
{
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }

    clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);


    ReadClientInfo(NewClient);

    clsBankClient::enSaveResults SaveResult;

    SaveResult = NewClient.Save();

    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        NewClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used!\n";
        break;

    }
    }
}
void DeleteClient() {
    string AccountNumber = "";

    cout << "\nPlease Enter Account Number: ";
    AccountNumber = clsInputValidate::ReadString();
    while (!clsBankClient::IsClientExist(AccountNumber))
    {
        cout << "\nAccount Number Is Already Used, Choose another one: ";
        AccountNumber = clsInputValidate::ReadString();
    }
    clsBankClient DeleteClient = clsBankClient::Find(AccountNumber);
    DeleteClient.Print();
    cout << "\nClient To Delete\n";
    clsBankClient::enSaveResults SaveResult;
    SaveResult = DeleteClient.Save();
    switch (SaveResult)
    {
    case  clsBankClient::enSaveResults::svSucceeded:
    {
        cout << "\nAccount Addeded Successfully :-)\n";
        DeleteClient.Print();
        break;
    }
    case clsBankClient::enSaveResults::svFaildEmptyObject:
    {
        cout << "\nError account was not saved because it's Empty";
        break;

    }
    case clsBankClient::enSaveResults::svFaildAccountNumberExists:
    {
        cout << "\nError account was not saved because account number is used!\n";
        break;

    }
    case clsBankClient::enSaveResults::svDelete:
    {
        cout << "\nAccount Deleted Successfully\n";
        break;

    }
    }

}
void ShowClientList() {
    vector <clsBankClient> vClients = clsBankClient::GetClientsList();
    cout << "\t\t\t\t\t\t Client List"<<"("<<vClients.size()<<")"<<"Client"<<endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    cout << setw(15) << "FirstName" << setw(15) << "LastName" << setw(25) << "Email" << setw(15) << "Phone" << setw(15) << "Acc. Number" << setw(15) << "PinCode" << setw(15) << "Balance" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
    PrintClients(vClients);
    cout << "------------------------------------------------------------------------------------------------------------------------\n";
}

int main()
{
    ShowClientList();
    
    system("pause>0");
    return 0;
}