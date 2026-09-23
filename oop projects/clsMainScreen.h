#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsClientListScreen.h"
#include "clsAddNewClient.h"
#include "clsDeleteClient.h"
#include "clsUpdateClient.h"
#include "clsFindClientScreen.h"
#include "clsTransactionScreen.h"
#include "clsManageUsersScreen.h"
#include "clsFindUserScreen.h"
#include "clsShowLoginRegisterScreen.h"
#include "Global.h"
using namespace std;
class clsMainScreen : protected clsScreen
{
private:
	enum enMainMenuOption {
		enListClient = 1, enAddNewClient = 2, enDeleteClient = 3, enUpdateClient = 4, enFindClient = 5, enTransaction = 6, enManageUsers = 7,enLoginRegister=8 ,enLogOut = 9
	};
	static short _ReadMainMenuOption() {
		cout << "\t\t\t\t\tChoose what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 9);
		return choice;
	}
	static  void _GoBackToMainMenu()
	{
		cout << setw(37) << left << "" << "\n\tPress any key to go back to Main Menue...\n";

		system("pause>0");
		ShowMainMenu();
	}
	static void _ShowAllClientsScreen() {
		clsClientListScreen::ShowClientList();
	}
	static void _AddNewClientScreen() {
		clsAddNewClient::AddNewClient();
	}
	static void _DeleteClientScreen() {
		clsDeleteClient::DeleteClient();
	}
	static void _UpdateClientScreen() {
		clsUpdateClient::UpdateClient();
	}
	static void _FindClientScreen() {
		clsFindClientScreen::FindClientScreen();
	}
	static void _TransactionScreen() {
		clsTransactionScreen::ShowTransactionMenu();
	}
	static void _ManageUsersScreen() {
		clsManageUsersScreen::ShowManageUsersInfo();
	}
	static void _LogOut() {
		CurrentUser = clsUser::Find("", "");
	}
	static void _LoginRegister() {
		clsShowLoginRegisterScreen::ShowLoginRegisterList();
	}
	static void _PerformMainManuOption(enMainMenuOption MainMenuOption) {
		switch (MainMenuOption) {
		case enMainMenuOption::enListClient: {
			system("cls");
			_ShowAllClientsScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enAddNewClient: {
			system("cls");
			_AddNewClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enDeleteClient: {
			system("cls");
			_DeleteClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enUpdateClient: {
			system("cls");
			_UpdateClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enFindClient: {
			system("cls");
			_FindClientScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enTransaction: {
			system("cls");
			_TransactionScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enManageUsers: {
			system("cls");
			_ManageUsersScreen();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enLoginRegister: {
			system("cls");
			_LoginRegister();
			_GoBackToMainMenu();
			break;
		}
		case enMainMenuOption::enLogOut: {
			system("cls");
			_LogOut();
			break;
		}
		}
	}
public:
	static void ShowMainMenu() {
		system("cls");
		_DrawScreenHeader("\t\tMain Screen");
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tMain Menu\n";
		cout << setw(37) << left << "" << "========================================================\n";
		UserAndDate();
		cout << setw(37) << left << "" << "--------------------------------------------------------\n";
		cout << setw(37) << left << "" << "\t[1] Show Client List.\n";
		cout << setw(37) << left << "" << "\t[2] Add New Client.\n";
		cout << setw(37) << left << "" << "\t[3] Delete Client.\n";
		cout << setw(37) << left << "" << "\t[4] Update Client Info.\n";
		cout << setw(37) << left << "" << "\t[5] Find Client.\n";
		cout << setw(37) << left << "" << "\t[6] Transaction.\n";
		cout << setw(37) << left << "" << "\t[7] Manage Users.\n";
		cout << setw(37) << left << "" << "\t[8] Login Register.\n";
		cout << setw(37) << left << "" << "\t[9] Logout.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		_PerformMainManuOption((enMainMenuOption)_ReadMainMenuOption());
	}
};