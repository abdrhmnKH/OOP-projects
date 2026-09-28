#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"
class clsFindCurrencyScreen : protected clsScreen
{
private :
	static void _PrindCurrencyCard(clsCurrency  & CurrentCurrency) {
		cout << "\n Currency Found :-)\n";
		cout << "\nCurrency Card:\n";
		cout << "\n----------------------------------------\n";
		cout << "\nCountry : " << CurrentCurrency.Country();
		cout << "\nCode : " << CurrentCurrency.CurrencyCode();
		cout << "\nName : " << CurrentCurrency.CurrencyName();
		cout << "\nRate/(1$) : " << CurrentCurrency.Rate();
		cout << "\n----------------------------------------\n";
	}
public :
	enum enFindBy{enByCode=1, enByCountry=2};
	static void ShowFindCurrencyScreen() {
		string Title = "Find Currency Screen\n";
		_DrawScreenHeader(Title);
		UserAndDate();
		int Choice;
		cout << "\nFind By : [1] Code or [2] Country ? ";
		Choice = clsInputValidate::ReadIntNumberBetween(1, 2);
		switch (Choice) {

		case clsFindCurrencyScreen::enByCode: {
			cout << "Please Enter Currency Code ? ";
			string CurrencyCode = clsInputValidate::ReadString();
			if (clsCurrency::IsCurrencyExist(CurrencyCode)) {
				clsCurrency CurrentCurrency = clsCurrency::FindByCode(CurrencyCode);
				_PrindCurrencyCard(CurrentCurrency);
			}
			else {
				cout << "\n Currency was not Found :-(\n";
			}
			break;
		}
		case clsFindCurrencyScreen::enByCountry: {
			cout << "Please Enter Country Name ? ";
			string CountryName = clsInputValidate::ReadString();
			if (clsCurrency::IsCountryExist(CountryName)) {
				clsCurrency CurrentCurrency = clsCurrency::FindByCountry(CountryName);
				_PrindCurrencyCard(CurrentCurrency);
			}
			else {
				cout << "\n Currency was not Found :-(\n";
			}
		}
		}
	}
	};

