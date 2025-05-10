#pragma once
#include<iostream>
#include<string>
#include<iomanip>
#include<cstdlib>
#include"clsDate.h"

using namespace std;
class clsUtil
{

private:

public:

	static void Srand()
	{
		srand((unsigned)time(NULL));
	}
	
	static int RandomNumber(int From, int To)
	{

		int Random = rand() % (To - From + 1) + From;

		return Random;
	}

	static enum enTypes { SmallLetter = 1, CapitalLetter = 2, Digit = 3, SpecialCharacter = 4, MixChars = 5 };

	static char GetRandomCharacter(enTypes Types)
	{
		if (Types == enTypes::MixChars)
		{
			Types = enTypes(RandomNumber(1, 3));
		}
		switch (Types)
		{
		case enTypes::SmallLetter:
			return RandomNumber(97, 122);

		case enTypes::CapitalLetter:
			return RandomNumber(65, 90);

		case enTypes::Digit:
			return RandomNumber(48, 57);

		case enTypes::SpecialCharacter:
			return RandomNumber(33, 47);
		}			
	}

	static string GenerateWord(enTypes Types, short StLength, string Text = "")
	{
		for (int i = 0; i < StLength; i++)
		{
			Text += GetRandomCharacter(Types);
		}
		return Text;
	}

	static string GenerateKey(enTypes Types)
	{
		string Key = "";

		Key = Key + GenerateWord(Types, 4) + '-'
			+ GenerateWord(Types, 4) + '-'
			+ GenerateWord(Types, 4) + '-'
			+ GenerateWord(Types, 4);

		return Key;
	}

	static void GenerateKeys(int NumberOfKeys, enTypes Types)
	{
		cout << "\nGenerate Keys:\n";
		cout << "----------------\n";

		for (int i = 1; i <= NumberOfKeys; i++)
		{
			cout << "[" << i << "]: "
				<< GenerateKey(Types) << endl;
		}
	}

	static void Swap(int& Num1, int& Num2)
	{
		int Swap;

		Swap = Num1;
		Num1 = Num2;
		Num2 = Swap;
	}

	static void Swap(double& D1, double& D2)
	{
		double Swap;

		Swap = D1;
		D1 = D2;
		D2 = Swap;
	}

	static void Swap(string& S1, string& S2)
	{
		string Swap;

		Swap = S1;
		S1 = S2;
		S2 = Swap;
	}

	static void Swap(clsDate& d1, clsDate& d2)
	{
		clsDate Swap;

		Swap = d1;
		d1 = d2;
		d2 = Swap;
	}


	static void ShuffleArray(int Arr[], int ArrLength)
	{
		for (int i= 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	static void ShuffleArray(string Arr[], int ArrLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
		}
	}

	static void FillArrayWithRandomNumber(int Arr[], int ArrLength, int From, int To)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = RandomNumber(From, To);
		}
	}

	static void FillArrayWithRandomWords(string Arr[], int ArrLength, enTypes Types, short StLength)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateWord(Types, StLength);
		}
	}

	static void FillArrayWithRandomKeys(string Arr[], int ArrLength, enTypes Types)
	{
		for (int i = 0; i < ArrLength; i++)
		{
			Arr[i] = GenerateKey(Types);
		}
	}

	static string Tabs(short TabsLength, string Tabs = "")
	{
		for (short i = 0; i < TabsLength; i++)
		{
			Tabs += "\t";
		}
		return Tabs;
	}

	static string Encrypt_Text(short Steps, string Text)
	{
		for (int i = 0; i < Text.length(); i++)
		{

			Text[i] = char(int(Text[i] + Steps));
			//cout << int(Text[i]) << endl;
		}
		return Text;
	}
	static string Decryption_Text(short Steps, string Text)
	{
		for (int i = 0; i <= Text.length(); i++)
		{
			Text[i] = char(Text[i] - Steps);
		}
		return Text;
	}


	static string NumbersToText(long long Number)
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

			return arr[Number / 10] + " " + NumbersToText(Number % 10);
		}

		// Hundreds
		if (Number >= 100 && Number <= 199) // 100
		{
			return "One Hundred " + NumbersToText(Number % 100);

		}

		if (Number >= 200 && Number <= 999)
		{
			return NumbersToText(Number / 100) + " Hundreds " + NumbersToText(Number % 100);
		}

		// Thousands
		if (Number >= 1000 && Number <= 1999)
		{
			return  "One Thousand " + NumbersToText(Number % 1000);
		}

		if (Number >= 2000 && Number <= 999999)
		{
			return NumbersToText(Number / 1000) + " Thousands " + NumbersToText(Number % 1000);
		}

		// Millions
		if (Number >= 1000000 && Number <= 1999999)
		{
			return "One Million " + NumbersToText(Number % 1000000);
		}

		if (Number >= 2000000 && Number <= 999999999)
		{
			return NumbersToText(Number / 1000000) + " Milloins " + NumbersToText(Number % 1000000);
		}

		// Billion
		if (Number >= 1000000000 && Number <= 1999999999)
		{
			return "One Billion " + NumbersToText(Number % 1000000000);
		}
		else
		{
			return NumbersToText(Number / 1000000000) + " Billions " + NumbersToText(Number % 1000000000);
		}

	}


};

