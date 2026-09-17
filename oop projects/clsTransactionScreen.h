#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{
private :
	static short _ReadTransactionMenuOption() {
		cout << "\t\t\t\t\tChoose what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 4);
		return choice;
	}
	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		clsMainScreen::ShowMainMenu();
	}
	static void _ShowDepositScreen() {
		cout << "\nDeposit Screen will be here.\n";
	}
	static void _ShowWithdrawScreen() {
		cout << "\Withdraw Screen will be here.\n";
	}
	static void _ShowTotalBalanceScreen() {
		cout << "\Withdraw Screen will be here.\n";
	}
	enum enTransactionMenuOption {enDeposit=1,enWithdraw=2,enTotalBalances=3,enMainMenu=4};
	static void _PerformMainManuOption(enTransactionMenuOption TransactionOption) {
		switch (TransactionOption) {
		case enTransactionMenuOption::enDeposit: {
			system("cls");
			_ShowDepositScreen();
			break;
		}
		case enTransactionMenuOption::enWithdraw: {
			system("cls");
			_ShowWithdrawScreen();
			break;
		}
		case enTransactionMenuOption::enTotalBalances: {
			system("cls");
			vector <clsBankClient> vClients = clsBankClient::GetClientsList();
			cout<<"\tTotal Balances of Clients = "<<clsBankClient::TotalBalances(vClients);
			break;
		}
		case enTransactionMenuOption::enMainMenu: {
			
		}
		}
	}
public : 
	static void ShowTransactionMenu() {
		string Title = "\tTransaction Screeen\n";
		_DrawScreenHeader(Title);
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tTransaction Menu\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t[1] Deposit.\n";
		cout << setw(37) << left << "" << "\t[2] Withdraw.\n";
		cout << setw(37) << left << "" << "\t[3] Total Balances.\n";
		cout << setw(37) << left << "" << "\t[4] Main Menu.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		_PerformMainManuOption((enTransactionMenuOption)_ReadTransactionMenuOption());
	}
};

