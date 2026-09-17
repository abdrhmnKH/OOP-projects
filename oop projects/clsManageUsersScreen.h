#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsMainScreen.h"
class clsManageUsersScreen : protected clsScreen
{
private :
	static short _ReadUsersMenuOption() {
		cout << "\t\t\t\t\tChoose what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
	static void _ShowListUsersScreen() {
		cout << "\nShow List Users Screen will be here\n";
	}
	static void _AddNewUserScreen() {
		cout << "\nAdd New User Screen will be here\n";
	}
	static void _DeleteUserScreen() {
		cout << "\nDelete User Screen will be here\n";
	}
	static void _UpdateUserScreen() {
		cout << "\nUpdate User Screen will be here\n";
	}
	static void _FindUserScreen() {
		cout << "\nFind User Screen will be here\n";
	}
	static void _MainMenuUserScreen() {
		cout << "\nMain Menu Screen will be here\n";
	}
	enum enManageUsersScreenOption { enListUsers = 1, enAddNewUser = 2, enDeleteUser = 3, enUpdateUser = 4 ,enFindUser=5,enMainMenu=6};
	static void _PerformMainManuOption(enManageUsersScreenOption ManageUsersOption) {
		switch (ManageUsersOption) {
		case enManageUsersScreenOption::enListUsers: {
			system("cls");
			_ShowListUsersScreen();
			break;
		}
		case enManageUsersScreenOption::enAddNewUser: {
			system("cls");
			_AddNewUserScreen();
			break;
		}
		case enManageUsersScreenOption::enDeleteUser: {
			system("cls");
			_DeleteUserScreen();
			break;
		}
		case enManageUsersScreenOption::enUpdateUser: {
			system("cls");
			_UpdateUserScreen();
			break;
		}
		case enManageUsersScreenOption::enFindUser: {
			system("cls");
			_FindUserScreen();
			break;
		}
		case enManageUsersScreenOption::enMainMenu: {
			system("cls");
			_MainMenuUserScreen();
			break;
		}
		}
	}
public :
	static void ShowManageUsersInfo() {
		string Title = "   Manage Users Screen\n";
		_DrawScreenHeader(Title);
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tManage Users Screen\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Users.\n";
		cout << setw(37) << left << "" << "\t[2] Add New User.\n";
		cout << setw(37) << left << "" << "\t[3] Delete User.\n";
		cout << setw(37) << left << "" << "\t[4] Update User.\n";
		cout << setw(37) << left << "" << "\t[5] Find User.\n";
		cout << setw(37) << left << "" << "\t[6] Main Menu.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		short ManageUsersOption = _ReadUsersMenuOption();
		_PerformMainManuOption((enManageUsersScreenOption) ManageUsersOption);
	}
};

