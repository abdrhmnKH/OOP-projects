#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
using namespace std;
class clsLogin : protected clsScreen
{
private :
	static void _Login() {
		bool LoginFailed = false;
		string UserName, Password;
		do {
			if (LoginFailed) {
				cout << "InValid UserName/Password\n";
			}
			cout << "Enter UserName? ";
			cin >> UserName;
			cout << "\n Enter Password?";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName,Password);
			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed);
		clsMainScreen::ShowMainMenu();
	}
public :
	static void ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLogin Screen.");
		_Login();	
	}
};