#pragma once
#pragma warning (disable : 4996)
#include<ctime>
#include<iostream>
#include<vector>	
#include<string>
using namespace std;


class clsDate
{
private:
	short _Day;
	short _Month;
	short _Year;

public:
	clsDate()
	{
		time_t t = time(0);
		tm* now = localtime(&t);

		_Day = now->tm_mday;
		_Month = now->tm_mon + 1;
		_Year = now->tm_year + 1900;
	}

	clsDate(string sDate)
	{
		vector <string> vDate = SplitString(sDate, "/");

		_Day = stoi(vDate[0]);
		_Month = stoi(vDate[1]);
		_Year = stoi(vDate[2]);
	}

	clsDate(short Day, short Month, short Year)
	{
		_Day = Day;
		_Month = Month;
		_Year = Year;
	}

	clsDate(short DaysOrder, short Year)
	{
		clsDate Date = DayFromDayOrderInYear(DaysOrder, Year);

		_Day = Date._Day;
		_Month = Date._Month;
		_Year = Date. _Year;
	}


	// Property Set
	void SetDay(short Day)
	{
		_Day = Day;
	}
	void SetMonth(short Month)
	{
		_Month = Month;
	}
	void SetYear(short Year)
	{
		_Year = Year;
	}

	// Property Get
	short GetDay()
	{
		return _Day;
	}
	short GetMonth()
	{
		return _Month;
	}
	short GetYear()
	{
		return _Year;
	}


	void PrintDate()
	{
		cout << _Day << "/" << _Month << "/" << _Year << endl;
	}



	vector<string> SplitString(string Str, string delim)
	{
		vector <string> vSplitWords;

		string sWord; // define a string variable
		short Pos = 0;

		// use find() function to get the position of the delimiter
		while ((Pos = Str.find(delim)) != std::string::npos) // true
		{
			sWord = Str.substr(0, Pos); // store the word
			if (sWord != " ")
			{
				vSplitWords.push_back(sWord);
			}
			Str.erase(0, Pos + delim.length()); // erase() until position and move to next word. 
		}
		if (Str != " ")
		{
			vSplitWords.push_back(Str);
		}
		return vSplitWords;
	}


	static clsDate DayFromDayOrderInYear(short DaysOrder, short Year)
	{
		clsDate Date;

		short RemainingDays = DaysOrder;
		short DaysInMonth = 0;

		Date._Year = Year;
		Date._Month = 1;

		while (true)
		{
			DaysInMonth = NumberOfDaysInMonth(Date._Month, Year);

			if (RemainingDays > DaysInMonth)
			{
				RemainingDays -= DaysInMonth;
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


	static string ConvertNumbersToText(long long Number)
	{
		if (Number == 0)
		{
			return "";
		}

		if (Number >= 1 && Number <= 19)
		{
			string arr[] = { "", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten",
				"Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

			return arr[Number];
		}

		if (Number >= 20 && Number <= 99) // 10
		{
			string arr[] = { "", "", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

			return arr[Number / 10] + " " + ConvertNumbersToText(Number % 10);
		}

		// Hundreds
		if (Number >= 100 && Number <= 199) // 100
		{
			return "One Hundred " + ConvertNumbersToText(Number % 100);

		}

		if (Number >= 200 && Number <= 999)
		{
			return ConvertNumbersToText(Number / 100) + " Hundreds " + ConvertNumbersToText(Number % 100);
		}

		// Thousands
		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + ConvertNumbersToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return ConvertNumbersToText(Number / 1000) + " Thousands " + ConvertNumbersToText(Number % 1000);
		}

		// Millions
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + ConvertNumbersToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return ConvertNumbersToText(Number / 1000000) + " Milloins " + ConvertNumbersToText(Number % 1000000);
		}

		// Billion
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + ConvertNumbersToText(Number % 1000000000);
		}
		else
		{
			return ConvertNumbersToText(Number / 1000000000) + " Billions " + ConvertNumbersToText(Number % 1000000000);
		}
	}
	
	static bool CheckLeapYearOrNot(short Year)
	{
		return (Year % 400) == 0 || (Year % 4) == 0 && (Year % 100) != 0;
	}
	bool CheckLeapYearOrNot()
	{
		return CheckLeapYearOrNot(_Year);
	}

	// convert year to days, hours, minutes and seconds
	static short NumberOfDaysInYear(short Year)
	{
		return (CheckLeapYearOrNot(Year)) ? 366 : 365;
	}
	short NumberOfDaysInYear()
	{
		return NumberOfDaysInYear(_Year);
	}

	static short NumberOfHoursInYear(short Year)
	{

		return NumberOfDaysInYear(Year) * 24;

	}
	short NumberOfHoursInYear()
	{
		return NumberOfHoursInYear(_Year);
	}

	static int NumberOfMinutesInYear(short Year)
	{
		return NumberOfHoursInYear(Year) * 60;
	}
	int NumberOfMinutesInYear()
	{
		return NumberOfMinutesInYear(_Year);
	}

	static int NumberOfSecondsInYear(short Year)
	{
		return NumberOfMinutesInYear(Year) * 60;
	}
	int NumberOfSecondsInYear()
	{
		return NumberOfSecondsInYear(_Year);
	}


	// convert a month in a year to days, hours, minutes and seconds
	static short NumberOfDaysInMonth(short Month, short Year)
	{
		short arr31Days[13] = { 0, 31, 28, 31, 30, 31, 30, 31 , 31, 30, 31, 30, 31 };

		return (Month == 2) ? (CheckLeapYearOrNot(Year) ? 29 : 28) : arr31Days[Month];
	}
	short NumberOfDaysInMonth()
	{
		return NumberOfDaysInMonth(_Month, _Year);
	}

	static short NumberOfHoursInMonth(short Month, short Year)
	{
		return NumberOfDaysInMonth(Month, Year) * 24;
	}
	short NumberOfHoursInMonth()
	{
		return NumberOfHoursInMonth(_Month, _Year);
	}

	static int NumberOfMinutesInMonth(short Month, short Year)
	{
		return NumberOfHoursInMonth(Month, Year) * 60;
	}
	int NumberOfMinutesInMonth()
	{
		return NumberOfMinutesInMonth(_Month, _Year);
	}

	static int NumberOfSecondsInMonth(short Month, short Year)
	{
		return NumberOfMinutesInMonth(Month, Year) * 60;
	}
	int NumberOfSecondsInMonth()
	{
		return NumberOfSecondsInMonth(_Month, _Year);
	}


	static short CalculateNumOfDayOrder(short Day, short Month, short Year)
	{
		short a = (14 - Month) / 12;
		short y = Year - a;
		short m = Month + (12 * a) - 2;

		// Gregorian Way:
		return (Day + y + (y / 4) - (y / 100) + (y / 400) + ((31 * m) / 12)) % 7;
	}
	short CalculateNumOfDayOrder()
	{
		return CalculateNumOfDayOrder(_Day, _Month, _Year);
	}

	static string DayName(short Day, short Month, short Year)
	{
		short NumOfDay = CalculateNumOfDayOrder(Day, Month, Year);

		string arrDays[] = { "Sun", "Mon", "Tue", "Wen", "Thur", "Fri",  "Sat" };

		return arrDays[NumOfDay];
	}
	string DayName()
	{
		return DayName(_Day, _Month, _Year);
	}


	static string MonthName(short MonthOfYear)
	{

		string arrDays[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

		return arrDays[MonthOfYear - 1];
	}
	string MonthName()
	{
		return MonthName(_Month);
	}

	static void PrintMonthCalendar(short Month, short Year)
	{

		short FirstDayInMonth = CalculateNumOfDayOrder(1, Month, Year);
		short DayesOfWeek = NumberOfDaysInMonth(Month, Year);

		cout << "\n  _______________" << MonthName(Month) << "_______________\n\n";

		printf("  Sun  Mon  Tue  Wen  Thu  Fri  Sat\n");


		short i;
		for (i = 0; i < FirstDayInMonth; i++)
			printf("     ");

		for (short j = 1; j < DayesOfWeek; j++)
		{
			printf("%5d", j);

			if (++i == 7)
			{
				i = 0;
				cout << endl;
			}
		}
		cout << "\n  _________________________________\n";
	}
	void PrintMonthCalendar()
	{
		PrintMonthCalendar(_Month, _Year);
	}

	static void PrintAllMonthesCalendarsOfYear(short Year)
	{

		printf("\n  _________________________________\n");
		printf("\n          Calendar - %d", Year);
		printf("\n  _________________________________\n");


		for (short i = 1; i <= 12; i++)
		{
			PrintMonthCalendar(i, Year);
		}

	}
	void PrintAllMonthesCalendarsOfYear()
	{
		PrintAllMonthesCalendarsOfYear(_Year);
	}

	static short NumberOfDaysFromTheBeginingOfTheYear(short Day, short Month, short Year)
	{
		short TotalDays = 0;

		for (short i = 1; i < Month; i++)
		{

			TotalDays += NumberOfDaysInMonth(i, Year);
		}

		return TotalDays += Day;
	}
	short NumberOfDaysFromTheBeginingOfTheYear()
	{
		return NumberOfDaysFromTheBeginingOfTheYear(_Day, _Month, _Year);
	}

	static bool IsDate1BeforeDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year < Date2._Year) ? true : (Date1._Month < Date2._Month) ? true : (Date1._Day < Date2._Day) ? true : false;
	}
	bool IsDateBeforeDate2(clsDate Date2)
	{
		//*this sends the current object
		return IsDate1BeforeDate2(*this, Date2);
	}

	static bool IsDate1AfterDate2(clsDate Date1, clsDate Date2)
	{
		return (!IsDate1BeforeDate2(Date1, Date2) && !IsDate1EqualDate2(Date1, Date2));
	}
	bool IsDate1AfterDate2(clsDate Date2)
	{
		return IsDate1AfterDate2(*this, Date2);
	}

	static bool IsDate1EqualDate2(clsDate Date1, clsDate Date2)
	{
		return (Date1._Year == Date2._Year) ? ((Date1._Month == Date2._Month) ? ((Date1._Day == Date2._Day) ? true : false) : false) : false;
	}
	bool IsDateEqualDate2(clsDate Date2)
	{
		return IsDate1EqualDate2(*this, Date2);
	}

	
	enum enCompareDate { Before = -1, Equal = 0, After = 1 };
	static enCompareDate CompareDate1AndDate2(clsDate Date1, clsDate Date2)
	{

		if (IsDate1BeforeDate2(Date1, Date2))
			return enCompareDate::Before;

		if (IsDate1EqualDate2(Date1, Date2))
			return enCompareDate::Equal;


		return enCompareDate::After;

	}


	static string DateToString(short Day, short Month, short Year, string Delim = "/")
	{
		string StringDate = "";

		StringDate += to_string(Day) + Delim;
		StringDate += to_string(Month) + Delim;
		StringDate += to_string(Year);

		return StringDate;
	}
	string DateToString()
	{
		return DateToString(_Day, _Month, _Year);
	}


	static bool IsLastMonthInYear(clsDate Date)
	{
		return (Date._Month <= 12 && Date._Month >= 1);
	}
	bool IsLastMonthInYear()
	{
		return IsLastMonthInYear(*this);
	}

	static bool IsLastDayInMonth(clsDate Date)
	{
		short Days = NumberOfDaysInMonth(Date._Year, Date._Month);

		return (Date._Day <= Days && Date._Day >= 1);
	}
	bool IsLastDayInMonth()
	{
		return IsLastDayInMonth(*this);
	}

	static bool ValidateDate(clsDate Date)
	{
		return IsLastMonthInYear(Date) && IsLastDayInMonth(Date);
	}
	bool ValidateDate()
	{
		return ValidateDate(*this);
	}



};

