#pragma once
#include <iostream>
#include <iomanip>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsString.h"
#include "clsCurrency.h"
class clsCurrencyCalculatorScreen : protected clsScreen
{
private :
	static void _PrindCaluclationResultInUSD(float Amount, string Code1, float Result, string Code2="USD") {
		cout << "\n" << Amount << " " << Code1 << " = " << Result << " " << Code2 << "\n";
	}
	static void _PrindCaluclationResult (float Amount,string Code1,float Result,string Code2) {
		cout << "\n" << Amount << " " << Code1 << " = " << Result << " " << Code2 << "\n";
	}
	static void _PrindCurrencyCardToUSD(clsCurrency& CurrentCurrency) {
		cout << "\nConvert From:\n";
		cout << "\n----------------------------------------\n";
		cout << "\nCountry : " << CurrentCurrency.Country();
		cout << "\nCode : " << CurrentCurrency.CurrencyCode();
		cout << "\nName : " << CurrentCurrency.CurrencyName();
		cout << "\nRate/(1$) : " << CurrentCurrency.Rate();
		cout << "\n----------------------------------------\n";
	}
	static void _PrintCurrencyCardFromUSD(clsCurrency& CurrentCurrency) {
		cout << "\nConvert From USD To :\n";
		cout << "\n----------------------------------------\n";
		cout << "\nCountry : " << CurrentCurrency.Country();
		cout << "\nCode : " << CurrentCurrency.CurrencyCode();
		cout << "\nName : " << CurrentCurrency.CurrencyName();
		cout << "\nRate/(1$) : " << CurrentCurrency.Rate();
		cout << "\n----------------------------------------\n";
	}
	static float ConvertToUsd(float Amount,float CurrencyRate) {
		return Amount / CurrencyRate;
	}
	static float ConvertToOtherCurrency(float Result, float CurrencyRate) {
		return Result * CurrencyRate;
	}
public :
	static void ShowCurrencyCalculatorScreen() {
		string Title = "Currency Calculator Screen\n";
		_DrawScreenHeader(Title);
		UserAndDate();
		char answer = 'n';
		do {
			cout << "Please Enter Currency1 Code ? ";
			string CurrencyCode1 = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist(CurrencyCode1)) {
				cout << "\nCurrency is not found, choose another one: ";
				CurrencyCode1 = clsInputValidate::ReadString();
			}
			clsCurrency CurrentCurrency1 = clsCurrency::FindByCode(CurrencyCode1);
			cout << "Please Enter Currency2 Code ? ";
			string CurrencyCode2 = clsInputValidate::ReadString();
			while (!clsCurrency::IsCurrencyExist(CurrencyCode2)) {
				cout << "\nCurrency is not found, choose another one: ";
				CurrencyCode2 = clsInputValidate::ReadString();
			}
			clsCurrency CurrentCurrency2 = clsCurrency::FindByCode(CurrencyCode2);
			float Amount = 0;
			cout << "\nEnter Amount to Exchange : ";
			Amount = clsInputValidate::ReadFlNumber();
			_PrindCurrencyCardToUSD(CurrentCurrency1);
			float ResultInUSD = ConvertToUsd(Amount,CurrentCurrency1.Rate());
			_PrindCaluclationResultInUSD(Amount, CurrentCurrency1.CurrencyCode(), ResultInUSD);
			if (CurrentCurrency2.CurrencyCode() != "USD") {
				float CurrencyResult = ConvertToOtherCurrency(ResultInUSD,CurrentCurrency2.Rate());
				_PrintCurrencyCardFromUSD(CurrentCurrency2);
				_PrindCaluclationResult(Amount, CurrentCurrency1.CurrencyCode(),CurrencyResult, CurrentCurrency2.CurrencyCode());
			}
			cout << "\nDo you want to perform another operation? y/n? \n";
			cin >> answer;
		} while (answer == 'y' || answer == 'Y');
	}
};

