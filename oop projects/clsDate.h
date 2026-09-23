#pragma once
#pragma warning(disable : 4996)
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include "clsString.h"
using namespace std;
class clsDate
{
private:
	string _Value;
	short _Day = 1;
	short _Month = 1;
	short _Year = 1900;
public:
	static string GetSystemDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		short Year = now->tm_year + 1900;
		short Month = now->tm_mon + 1;
		short Day = now->tm_mday;

		return to_string(Day) + "/" +
			to_string(Month) + "/" +
			to_string(Year);
	}
	static string GetSystemDateTimeString()
	{
		//system datetime string
		time_t t = time(0);
		tm* now = localtime(&t);

		short Day, Month, Year, Hour, Minute, Second;

		Year = now->tm_year + 1900;
		Month = now->tm_mon + 1;
		Day = now->tm_mday;
		Hour = now->tm_hour;
		Minute = now->tm_min;
		Second = now->tm_sec;

		return (to_string(Day) + "/" + to_string(Month) + "/"
			+ to_string(Year) + " - "
			+ to_string(Hour) + ":" + to_string(Minute)
			+ ":" + to_string(Second));

	}
	static bool isLeapYear(short Year)
	{
		// if year is divisible by 4 AND not divisible by 100
		// OR if year is divisible by 400
		// then it is a leap year
		return (Year % 4 == 0 && Year % 100 != 0) || (Year % 400 ==
			0);
	}
	bool isLeapYear() {
		return isLeapYear(_Year);
	}
	static short NumberOfDaysInAYear(short Year)
	{
		return isLeapYear(Year) ? 366 : 365;
	}
	short NumberOfDaysInAYear() {
		return NumberOfDaysInAYear(_Year);
	}
	static short NumberOfHoursInAYear(short Year)
	{
		return NumberOfDaysInAYear(Year) * 24;
	}
	short NumberOfHoursInAYear()
	{
		return NumberOfDaysInAYear(_Year) * 24;
	}
	static int NumberOfMinutesInAYear(short Year)
	{
		return NumberOfHoursInAYear(Year) * 60;
	}
	int NumberOfMinutesInAYear()
	{
		return NumberOfHoursInAYear(_Year) * 60;
	}
	static int NumberOfSecondsInAYear(short Year)
	{
		return NumberOfMinutesInAYear(Year) * 60;
	}
	int NumberOfSecondsInAYear()
	{
		return NumberOfMinutesInAYear(_Year) * 60;
	}
	static short NumberOfDaysInAMonth(short Month, short Year)
	{
		if (Month < 1 || Month>12)
			return 0;

		int NumberOfDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

		return (Month == 2) ? (isLeapYear(Year) ? 29 : 28) :
			NumberOfDays[Month - 1];
	}
	short NumberOfDaysInAMonth() {
		return NumberOfDaysInAMonth(_Month, _Year);
	}
	static short DayOfWeekOrder(short Day, short Month, short Year)
	{
		short a, y, m;
		a = (14 - Month) / 12;
		y = Year - a;
		m = Month + (12 * a) - 2;
		// Gregorian:
		//0:sun, 1:Mon, 2:Tue...etc
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m)
			/ 12)) % 7;
	}
	short DayOfWeekOrder() {
		return DayOfWeekOrder(_Day, _Month, _Year);
	}
	static short DayOfWeekOrder(clsDate Date) {
		return DayOfWeekOrder(Date._Day, Date._Month, Date._Year);
	}
	static string DayShortName(short DayOfWeekOrder)
	{
		string arrDayNames[] = {
		"Sun","Mon","Tue","Wed","Thu","Fri","Sat" };
		return arrDayNames[DayOfWeekOrder];
	}
	string DayShortName() {
		return DayShortName(DayOfWeekOrder());
	}
	static string MonthShortName(short MonthNumber)
	{
		string Months[12] = { "Jan", "Feb", "Mar",
		"Apr", "May", "Jun",
		"Jul", "Aug", "Sep",
		"Oct", "Nov", "Dec"
		};
		return (Months[MonthNumber - 1]);
	}
	string MonthShortName() {
		return MonthShortName(_Month);
	}
	static void PrintMonthCalendar(short Month, short Year)
	{
		int NumberOfDays;
		// Index of the day from 0 to 6
		int current = DayOfWeekOrder(1, Month, Year);
		NumberOfDays = NumberOfDaysInAMonth(Month, Year);
		// Print the current month name
		printf("\n _______________%s_______________\n\n",
			MonthShortName(Month).c_str());
		// Print the columns
		printf(" Sun Mon Tue Wed Thu Fri Sat\n");
		// Print appropriate spaces
		int i;
		for (i = 0; i < current; i++)
			printf(" ");
		for (int j = 1; j <= NumberOfDays; j++)
		{
			printf("%5d", j);
			if (++i == 7)
			{
				i = 0;
				printf("\n");
			}
		}
		printf("\n _________________________________\n");
	}
	void PrintMonthCalendar() {
		PrintMonthCalendar(_Month, _Year);
	}
	static void PrintYearCalendar(short Year)
	{
		printf("\n _________________________________\n\n");
		printf(" Calendar - %d\n", Year);
		printf(" _________________________________\n");
		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}
	}
	void PrintYearCalendar() {
		return PrintYearCalendar(_Year);
	}
	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month,
		short Year)
	{
		short TotalDays = 0;
		for (int i = 1; i <= Month - 1; i++)
		{
			TotalDays += NumberOfDaysInAMonth(i, Year);
		}
		TotalDays += Day;
		return TotalDays;
	}
	short NumberOfDaysFromTheBeginingOfTheYear() {
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}
	static clsDate DateAddDays(short Days, clsDate Date)
	{
		short RemainingDays = Days +
			NumberOfDaysFromTheBeginingOfTheYear(Date._Day, Date._Month,
				Date._Year);
		short MonthDays = 0;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Date._Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
				if (Date._Month > 12)
				{
					Date._Month = 1;
					Date._Year++;
				}
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate DateAddDays(short Days) {
		return DateAddDays(Days, *this);
	}
	static clsDate GetDateFromDayOrderInYear(short DateOrderInYear, short Year)
	{
		clsDate Date;
		short RemainingDays = DateOrderInYear;
		short MonthDays = 0;
		Date._Year = Year;
		Date._Month = 1;
		while (true)
		{
			MonthDays = NumberOfDaysInAMonth(Date._Month, Year);
			if (RemainingDays > MonthDays)
			{
				RemainingDays -= MonthDays;
				Date._Month++;
			}
			else
			{
				Date._Day = RemainingDays;
				break;
			}
		}
		return Date;
	}
	clsDate GetDateFromDayOrderInYear() {
		return GetDateFromDayOrderInYear(_Day, _Year);
	}
	static string DateToString(clsDate date) {
		return to_string(date._Day) + "/" + to_string(date._Month) + "/" + to_string(date._Year);
	}
	string DateToString() {
		return DateToString(*this);
	}
	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : ((Date1._Year ==
			Date2._Year) ? (Date1._Month < Date2._Month ? true : (Date1._Month ==
				Date2._Month ? Date1._Day < Date2._Day : false)) : false);
	}
	bool IsDate1BeforeDate2(clsDate Date2)
	{
		return IsDate1BeforeDate2(*this, Date2);//(this->_Year < Date2._Year) ? true : ((this->_Year ==
		//Date2._Year) ? (this->_Month < Date2._Month ? true : (this->_Month ==
			//Date2._Month ? this->_Day < Date2._Day : false)) : false);
	}
	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month ==
			Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false)
			: false) : false;
	}
	bool IsDate1EqualDate2(clsDate Date2) {
		return IsDate1EqualDate2(*this, Date2);
	}
	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) &&
			!IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2) {
		return IsDate1AfterDate2(*this, Date2);
	}

	enum enDateCompare { Before = -1, Equal = 0, After = 1 };

	static enDateCompare CompareDates(clsDate Date1, clsDate Date2)
	{
		if (IsDate1BeforeDate2(Date1, Date2))
			return enDateCompare::Before;
		if (IsDate1EqualDate2(Date1, Date2))
			return enDateCompare::Equal;

		return enDateCompare::After;
	}

	enDateCompare CompareDates(clsDate Date2) {
		return CompareDates(*this, Date2);
	}
	static bool IsLastDayInMonth(clsDate Date)
	{
		return (Date._Day == NumberOfDaysInAMonth(Date._Month,
			Date._Year));
	}
	bool IsLastDayInMonth() {
		return IsLastDayInMonth(*this);
	}
	static bool IsLastMonthInYear(short Month)
	{
		return (Month == 12);
	}
	bool IsLastMonthInYear() {
		return IsLastMonthInYear(this->_Month);
	}
	static clsDate IncreaseDateByOneDay(clsDate Date)
	{
		if (IsLastDayInMonth(Date))
		{
			if (IsLastMonthInYear(Date._Month))
			{
				Date._Month = 1;
				Date._Day = 1;
				Date._Year++;
			}
			else
			{
				Date._Day = 1;
				Date._Month++;
			}
		}
		else
		{
			Date._Day++;
		}
		return Date;
	}
	clsDate IncreaseDateByOneDay() {
		return IncreaseDateByOneDay(*this);
	}
	static void SwapDates(clsDate& Date1, clsDate& Date2)
	{
		clsDate TempDate;
		TempDate._Year = Date1._Year;
		TempDate._Month = Date1._Month;
		TempDate._Day = Date1._Day;
		Date1._Year = Date2._Year;
		Date1._Month = Date2._Month;
		Date1._Day = Date2._Day;
		Date2._Year = TempDate._Year;
		Date2._Month = TempDate._Month;
		Date2._Day = TempDate._Day;
	}
	void SwapDates(clsDate Date2) {
		return SwapDates(*this, Date2);
	}

	static int GetDifferenceInDays(clsDate Date1, clsDate Date2, bool
		IncludeEndDay = false)
	{
		int Days = 0;
		short SawpFlagValue = 1;
		if (!IsDate1BeforeDate2(Date1, Date2))
		{
			//Swap Dates
			SwapDates(Date1, Date2);
			SawpFlagValue = -1;
		}
		while (IsDate1BeforeDate2(Date1, Date2))
		{
			Days++;
			Date1 = IncreaseDateByOneDay(Date1);
		}
		return IncludeEndDay ? ++Days * SawpFlagValue : Days *
			SawpFlagValue;
	}
	int GetDifferenceInDays(clsDate Date2) {
		return GetDifferenceInDays(*this, Date2, false);
	}

	static clsDate IncreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByOneWeek() {
		return IncreaseDateByOneWeek(*this);
	}

	static clsDate IncreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = IncreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXWeeks(short weeks) {
		return IncreaseDateByXWeeks(weeks, *this);
	}
	static clsDate IncreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 12)
		{
			Date._Month = 1;
			Date._Year++;
		}
		else
		{
			Date._Month++;
		}

		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}

	clsDate IncreaseDateByOneMonth() {
		return   IncreaseDateByOneMonth(*this);
	}

	static clsDate IncreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = IncreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXDays(short Days) {
		return IncreaseDateByXDays(Days, *this);
	}
	static clsDate IncreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = IncreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXMonths(short Months) {
		return IncreaseDateByXMonths(Months, *this);
	}
	static clsDate IncreaseDateByOneYear(clsDate Date)
	{
		Date._Year++;
		return Date;
	}
	clsDate IncreaseDateByOneYear() {
		return IncreaseDateByOneYear(*this);
	}

	static clsDate IncreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = IncreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate IncreaseDateByXYears(short Years) {
		return IncreaseDateByXYears(Years, *this);
	}
	static clsDate DecreaseDateByOneDay(clsDate Date)
	{
		if (Date._Day == 1)
		{
			if (Date._Month == 1)
			{
				Date._Month = 12;
				Date._Day = 31;
				Date._Year--;
			}
			else
			{
				Date._Month--;
				Date._Day = NumberOfDaysInAMonth(Date._Month,
					Date._Year);
			}
		}
		else
		{
			Date._Day--;
		}
		return Date;
	}
	clsDate DecreaseDateByOneDay() {
		return DecreaseDateByOneDay(*this);
	}
	static clsDate DecreaseDateByOneWeek(clsDate Date)
	{
		for (int i = 1; i <= 7; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByOneWeek() {
		return DecreaseDateByOneWeek(*this);
	}

	static clsDate DecreaseDateByXWeeks(short Weeks, clsDate Date)
	{
		for (short i = 1; i <= Weeks; i++)
		{
			Date = DecreaseDateByOneWeek(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXWeeks(short Weeks) {
		return DecreaseDateByXWeeks(Weeks, *this);
	}

	static clsDate DecreaseDateByOneMonth(clsDate Date)
	{
		if (Date._Month == 1)
		{
			Date._Month = 12;
			Date._Year--;
		}
		else
			Date._Month--;

		short NumberOfDaysInCurrentMonth =
			NumberOfDaysInAMonth(Date._Month, Date._Year);
		if (Date._Day > NumberOfDaysInCurrentMonth)
		{
			Date._Day = NumberOfDaysInCurrentMonth;
		}
		return Date;
	}
	clsDate DecreaseDateByOneMonth() {
		return DecreaseDateByOneMonth(*this);
	}

	static clsDate DecreaseDateByXDays(short Days, clsDate Date)
	{
		for (short i = 1; i <= Days; i++)
		{
			Date = DecreaseDateByOneDay(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXDays(short Days) {
		return DecreaseDateByXDays(Days, *this);
	}

	static clsDate DecreaseDateByXMonths(short Months, clsDate Date)
	{
		for (short i = 1; i <= Months; i++)
		{
			Date = DecreaseDateByOneMonth(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXMonths(short Months) {
		return DecreaseDateByXMonths(Months, *this);
	}

	static clsDate DecreaseDateByOneYear(clsDate Date)
	{
		Date._Year--;
		return Date;
	}
	clsDate DecreaseDateByOneYear()
	{
		return DecreaseDateByOneYear(*this);

	}

	static clsDate DecreaseDateByXYears(short Years, clsDate Date)
	{
		for (short i = 1; i <= Years; i++)
		{
			Date = DecreaseDateByOneYear(Date);
		}
		return Date;
	}
	clsDate DecreaseDateByXYears(short Years) {
		return DecreaseDateByXYears(Years, *this);
	}

	static short IsEndOfWeek(clsDate Date)
	{
		return DayOfWeekOrder(Date) == 6;
	}
	short IsEndOfWeek() {
		return IsEndOfWeek(*this);
	}
	static bool IsWeekEnd(clsDate Date)
	{
		//Weekends are Fri and Sat
		short DayIndex = DayOfWeekOrder(Date);
		return (DayIndex == 5 || DayIndex == 6);
	}
	bool IsWeekEnd() {
		return IsWeekEnd(*this);
	}
	static bool IsBusinessDay(clsDate Date)
	{
		return !IsWeekEnd(Date);
	}
	bool IsBusinessDay() {
		return IsBusinessDay(*this);
	}
	static short DaysUntilTheEndOfWeek(clsDate Date)
	{
		return 6 - DayOfWeekOrder(Date);
	}
	short DaysUntilTheEndOfWeek() {
		return DaysUntilTheEndOfWeek(*this);
	}
	static short DaysUntilTheEndOfMonth(clsDate Date1)
	{
		clsDate EndOfMontDate;
		EndOfMontDate._Day = NumberOfDaysInAMonth(Date1._Month,
			Date1._Year);
		EndOfMontDate._Month = Date1._Month;
		EndOfMontDate._Year = Date1._Year;
		return GetDifferenceInDays(Date1, EndOfMontDate, true);
	}
	short DaysUntilTheEndOfMonth() {
		return DaysUntilTheEndOfMonth(*this);
	}
	static short DaysUntilTheEndOfYear(clsDate Date1)
	{
		clsDate EndOfYearDate;
		EndOfYearDate._Day = 31;
		EndOfYearDate._Month = 12;
		EndOfYearDate._Year = Date1._Year;
		return GetDifferenceInDays(Date1, EndOfYearDate, true);
	}

	short DaysUntilTheEndOfYear() {
		return DaysUntilTheEndOfYear(*this);
	}
	static short CalculateVacationDays(clsDate DateFrom, clsDate DateTo)
	{
		short DaysCount = 0;
		while (IsDate1BeforeDate2(DateFrom, DateTo))
		{
			if (IsBusinessDay(DateFrom))
				DaysCount++;
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}
		return DaysCount;
	}
	short CalculateVacationDays(clsDate DateTo) {
		return CalculateVacationDays(*this, DateTo);
	}

	static clsDate CalculateVacationReturnDate(clsDate DateFrom, short VacationDays)
	{

		short WeekEndCounter = 0;

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}


		for (short i = 1; i <= VacationDays + WeekEndCounter; i++)
		{

			if (IsWeekEnd(DateFrom))
				WeekEndCounter++;

			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		while (IsWeekEnd(DateFrom))
		{
			DateFrom = IncreaseDateByOneDay(DateFrom);
		}

		return DateFrom;
	}

	clsDate CalculateVacationReturnDate(short VacationDays) {
		return CalculateVacationReturnDate(*this, VacationDays);
	}
	static bool IsValidDate(clsDate Date)
	{
		if (Date._Day < 1 || Date._Day>31)
			return false;
		if (Date._Month < 1 || Date._Month>12)
			return false;
		if (Date._Month == 2)
		{
			if (isLeapYear(Date._Year))
			{
				if (Date._Day > 29)
					return false;
			}
			else
			{
				if (Date._Day > 28)
					return false;
			}
		}
		short DaysInMonth = NumberOfDaysInAMonth(Date._Month,
			Date._Year);
		if (Date._Day > DaysInMonth)
			return false;
		return true;
	}
	bool IsValidDate() {
		return IsValidDate(*this);
	}

	vector<string> SplitString(string S1, string Delim)
	{
		vector<string> vString;
		short pos = 0;
		string sWord; // define a string variable
		// use find() function to get the position of the delimiters
		while ((pos = S1.find(Delim)) != std::string::npos)
		{
			sWord = S1.substr(0, pos); // store the word
			if (sWord != "")
			{
				vString.push_back(sWord);
			}
			S1.erase(0, pos + Delim.length());
		}
		if (S1 != "")
		{
			vString.push_back(S1); // it adds last word of the string.
		}
		return vString;
	}
	clsDate StringToDate(string DateString)
	{
		clsDate Date;
		vector <string> vDate;
		vDate = SplitString(DateString, "/");
		Date._Day = stoi(vDate[0]);
		Date._Month = stoi(vDate[1]);
		Date._Year = stoi(vDate[2]);
		return Date;
	}
	clsDate() {
		_Value = GetSystemDate();
		vector<string> vDateParts = clsString::SplitString(_Value, "/");
		_Day = stoi(vDateParts[0]);
		_Month = stoi(vDateParts[1]);
		_Year = stoi(vDateParts[2]);
	}
	clsDate(string Date) {
		_Value = Date;
		vector<string> vDateParts = clsString::SplitString(_Value, "/");
		_Day = stoi(vDateParts[0]);
		_Month = stoi(vDateParts[1]);
		_Year = stoi(vDateParts[2]);
	}
	clsDate(int Day, int Month, int Year) {
		_Value = to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year);
		vector<string> vDateParts = clsString::SplitString(_Value, "/");
		_Day = stoi(vDateParts[0]);
		_Month = stoi(vDateParts[1]);
		_Year = stoi(vDateParts[2]);
	}
	clsDate(int days, int year) {
		*this = GetDateFromDayOrderInYear(days, year);
		vector<string> vDateParts = clsString::SplitString(DateToString(*this), "/");
		_Day = stoi(vDateParts[0]);
		_Month = stoi(vDateParts[1]);
		_Year = stoi(vDateParts[2]);
	}
	void Print() {
		cout << DateToString(*this) << endl;

	}
};