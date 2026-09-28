#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"
class clsShowUpdateRateScreen : protected clsScreen
{
private :
	static void _PrindCurrencyCard(clsCurrency& CurrentCurrency) {
		cout << "\nCurrency Card:\n";
		cout << "\n----------------------------------------\n";
		cout << "\nCountry : " << CurrentCurrency.Country();
		cout << "\nCode : " << CurrentCurrency.CurrencyCode();
		cout << "\nName : " << CurrentCurrency.CurrencyName();
		cout << "\nRate/(1$) : " << CurrentCurrency.Rate();
		cout << "\n----------------------------------------\n";
	}
public :
	static void ShowUpdateRateScreen() {
		string Title = "Update Currency Screen\n";
		_DrawScreenHeader(Title);
		UserAndDate();
		cout << "Please Enter Currency Code ? ";
		string CurrencyCode = clsInputValidate::ReadString();
	    while (!clsCurrency::IsCurrencyExist(CurrencyCode)) {
			cout << "\nCurrency is not found, choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}
			clsCurrency CurrentCurrency = clsCurrency::FindByCode(CurrencyCode);
			_PrindCurrencyCard(CurrentCurrency);
			char answer = 'n';
			cout << "\nAre you sure you want to update the rate of this currency ? y/n ? ";
			cin >> answer;
			if (answer == 'y' || answer == 'Y') {
				cout << "\nUpdate Currency Rate :\n";
				cout << "\n----------------------------------------\n";
				cout << "Enter New Rate : ";
				float NewRate = clsInputValidate::ReadFlNumber();
				CurrentCurrency.UpdateRate(NewRate);
				cout << "\nCurrency Rate Updated Successfully :-)\n";
				_PrindCurrencyCard(CurrentCurrency);
			}
	}
};

