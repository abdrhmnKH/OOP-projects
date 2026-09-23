#pragma once
#include <iostream>
#include "clsUser.h"
#include "Global.h"
#include "clsScreen.h"
#include "clsMainScreen.h"
#include "clsDate.h"
using namespace std;
class clsLogin : protected clsScreen
{
private :
	static bool _Login() {
		UserAndDate();
		bool LoginFailed = false;
		string UserName, Password;
		short Trials = 3;
		do {
			if (LoginFailed) {
				cout << "InValid UserName/Password\n";
				Trials--;
				cout << "You Have " << Trials << " Trials to Login\n";
				if (Trials == 0) {
					cout << "You are locked after 3 failed trials\n";
					return false;
				}
			}
			cout << "Enter UserName? ";
			cin >> UserName;
			cout << "\n Enter Password?";
			cin >> Password;
			CurrentUser = clsUser::Find(UserName, Password);
			LoginFailed = CurrentUser.IsEmpty();
		} while (LoginFailed);
		CurrentUser.RegisterLogIn();
		clsMainScreen::ShowMainMenu();
	}
public :
	static bool ShowLoginScreen() {
		system("cls");
		_DrawScreenHeader("\tLogin Screen.");
	return _Login();
	}
};