#pragma once
#include<iostream>
#include<string>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:
	static bool IsNumberBetween(short Num, short From, short To)
	{
		return (Num >= From && Num <= To) ? true : false;
	}

	static bool IsNumberBetween(int Num, int From, int To)
	{
		return (Num >= From && Num <= To) ? true : false;
	}

	static bool IsNumberBetween(float Num, float From, float To)
	{
		return (Num >= From && Num <= To) ? true : false;
	}

	static bool IsNumberBetween(double Num, double From, double To)
	{
		return (Num >= From && Num <= To) ? true : false;
	}

	static bool IsDateBetween(clsDate DateNow, clsDate From, clsDate To)
	{
		// Like (Num >= From && Num <= To)
		if ((clsDate::IsDate1AfterDate2(DateNow, From) || clsDate::IsDate1EqualDate2(DateNow, From))
			&&
			(clsDate::IsDate1BeforeDate2(DateNow, To) || clsDate::IsDate1EqualDate2(DateNow, To)))
			return true;

		// Like (Num >= To && Num <= From)
		if ((clsDate::IsDate1AfterDate2(DateNow, To) || clsDate::IsDate1EqualDate2(DateNow, To))
			&&
			(clsDate::IsDate1BeforeDate2(DateNow, From) || clsDate::IsDate1EqualDate2(DateNow, From)))
			return true;

		
		return false;
		
	}

	static int ReadIntNumber(string Message)
	{
		int Num;
		cin >> Num;

		while (cin.fail())
		{
			// user didn't input a number.

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static int ReadIntNumberBetween(int From, int To, string StMessage, string WrongNumMessage)
	{
		int Num;
		cin >> Num;

		while (true)
		{
			// user didn't input a number.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << StMessage;
			}
			else if (!IsNumberBetween(Num, From, To))
				cout << WrongNumMessage;
			
			else
				break;
			
			cin >> Num;
		}
		return Num;
	}

	static short ReadShortNumber(string Message)
	{
		short Num;
		cin >> Num;

		while (cin.fail())
		{
			// user didn't input a number.

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static short ReadShortNumberBetween(short From, short To, string StMessage, string WrongNumMessage)
	{
		short Num;
		cin >> Num;

		while (true)
		{
			// user didn't input a number.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << StMessage;
			}
			else if (!IsNumberBetween(Num, From, To))
				cout << WrongNumMessage;

			else
				break;

			cin >> Num;
		}
		return Num;
	}

	static float ReadFtNumber(string Message)
	{
		float Num;
		cin >> Num;

		while (cin.fail())
		{
			// user didn't input a number.

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static float ReadFtNumberBetween(float From, float To, string StMessage, string WrongNumMessage)
	{
		float Num;
		cin >> Num;

		while (true)
		{
			// user didn't input a number.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << StMessage;
			}
			else if (!IsNumberBetween(Num, From, To))
				cout << WrongNumMessage;

			else
				break;

			cin >> Num;
		}
		return Num;
	}

	static double ReadDblNumber(string Message)
	{
		double Num;
		cin >> Num;

		while (cin.fail())
		{
			// user didn't input a number.

			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << Message;
			cin >> Num;
		}
		return Num;
	}
	static double ReadDblNumberBetween(double From, double To, string StMessage, string WrongNumMessage)
	{
		double Num;
		cin >> Num;

		while (true)
		{
			// user didn't input a number.
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				cout << StMessage;
			}
			else if (!IsNumberBetween(Num, From, To))
				cout << WrongNumMessage;

			else
				break;

			cin >> Num;
		}
		return Num;
	}

	static bool IsValideDate(clsDate Date)
	{
		return clsDate::ValidateDate(Date);
	}

	static string ReadString()
	{
		string S1 = "";
		getline(cin >> ws, S1);
		return S1;
	}


};

