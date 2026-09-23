#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
#include "clsBankClient.h"
#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsShowTotalBalancesScreen.h"
using namespace std;
class clsTransactionScreen : protected clsScreen
{
private :
	static short _ReadTransactionMenuOption() {
		cout << "\t\t\t\t\tChoose what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 4);
		return choice;
	}
	static void _ShowDepositScreen() {
		clsDepositScreen::ShowDepositScreen();
	}
	static void _ShowWithdrawScreen() {
		clsWithdrawScreen::ShowWithDrawScreen();
	}
	static void _ShowTotalBalanceScreen() {
		clsShowTotalBalancesScreen::ShowTotalBalanceScreen();
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
			_ShowTotalBalanceScreen();
			break;
		}
		case enTransactionMenuOption::enMainMenu: {
			
		}
		}
	}
public : 
	static void ShowTransactionMenu() {
		if (!CheckAccessRights(clsUser::_enPermissions::prTransaction)) {
			return;
		}
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

