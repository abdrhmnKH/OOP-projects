#pragma once
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsUser.h"
#include "clsCurrenciesListScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsShowUpdateRateScreen.h"
class clsCurrencyExchangeScreen : protected clsScreen
{
private :
	static short _ReadCurrencyExchangeOption() {
		cout << "\t\t\t\t\tChoose what do you want to do ? ";
		short choice = clsInputValidate::ReadIntNumberBetween(1, 6);
		return choice;
	}
	enum enCurrencyExchangeOption {
		enListCurrencies = 1, enFindCurrency = 2, enUpdateRate = 3, enCurrencyCalculator = 4,enMainMenu = 5
	};
	static void _ShowListCurrenciesScreen() {
		clsCurrenciesListScreen::ShowCurrenciesList();
	}
	static void _ShowFindCurrencyScreen() {
		clsFindCurrencyScreen::ShowFindCurrencyScreen();
	}
	static void _ShowUpdateRateScreen() {
		clsShowUpdateRateScreen::ShowUpdateRateScreen();
	}
	static void _ShowCurrencyCalculator() {
		//clsDepositScreen::ShowDepositScreen();
	}
	static void _PerformMainManuOption(enCurrencyExchangeOption CurrencyExchangeOption) {
		switch (CurrencyExchangeOption) {
		case enCurrencyExchangeOption::enListCurrencies: {
			system("cls");
			_ShowListCurrenciesScreen();
			break;
		}
		case enCurrencyExchangeOption::enFindCurrency: {
			system("cls");
			_ShowFindCurrencyScreen();
			break;
		}
		case enCurrencyExchangeOption::enUpdateRate: {
			system("cls");
			_ShowUpdateRateScreen();
			break;
		}
		case enCurrencyExchangeOption::enCurrencyCalculator: {
			system("cls");
			_ShowCurrencyCalculator();
			break;
		}
		case enCurrencyExchangeOption::enMainMenu: {

		}
		}
	}
public :
	static void ShowCurrencyExchangeMenu() {
		if (!CheckAccessRights(clsUser::_enPermissions::prCurrencyExchangeList)) {
			return;
		}
		string Title = "\Currency Exchange Screeen\n";
		_DrawScreenHeader(Title);
		UserAndDate();
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t\t\tCurrency Exchange Menu\n";
		cout << setw(37) << left << "" << "========================================================\n";
		cout << setw(37) << left << "" << "\t[1] List Currencies.\n";
		cout << setw(37) << left << "" << "\t[2] Find Currency.\n";
		cout << setw(37) << left << "" << "\t[3] Update Rate.\n";
		cout << setw(37) << left << "" << "\t[4] Currency Calculator.\n";
		cout << setw(37) << left << "" << "\t[5] Main Menu.\n";
		cout << setw(37) << left << "" << "========================================================\n";
		_PerformMainManuOption((enCurrencyExchangeOption)_ReadCurrencyExchangeOption());

	}
};

