#pragma once
#include <iostream>
#include<vector>
using namespace std;

class clsString
{

private:
	string _Value;
	
public:
	clsString()
	{
		_Value = "";
	}

	clsString(string Value)
	{
		_Value = Value;
	}


	void SetValue(string Value)
	{
		_Value = Value;
	}
	string GetValue()
	{
		return _Value;
	}


	 __declspec(property(get = GetValue, put = SetValue)) string Value;


	 static short Length(string Str)
	 {
		 return Str.length();
	 }
	 short Length()
	 {
		 return Length(_Value);
	 }

	 static void PrintFirstLettersInString(string Str)
	 {
		 bool IsFirstLetter = true;

		 cout << "\nFirst letters of this string:\n";

		 for (short i = 0; i < Str.length(); i++)
		 {

			 if (Str[i] != ' ' && IsFirstLetter)
			 {

				 cout << Str[i] << endl;

			 }
			 IsFirstLetter = (Str[i] == ' ') ? true : false;

		 }
		 cout << endl;
	 }
	 void PrintFirstLettersInString()
	 {
		 PrintFirstLettersInString(_Value);
	 }

	 static string UpperFirstLetterOfEachWord(string Str)
	 {
		 bool FirstLetter = true;

		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (Str[i] != ' ' && FirstLetter)
			 {
				 Str[i] = toupper(Str[i]);
			 }
			 FirstLetter = (Str[i] == ' ') ? true : false;
		 }
		 return Str;
	 }
	 void UpperFirstLetterOfEachWord()
	 {
		 _Value = UpperFirstLetterOfEachWord(_Value);
	 }

	 static string LowerFirstLetterOfEachWord(string Str)
	 {
		 bool FirstLetter = true;

		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (Str[i] != ' ' && FirstLetter)
			 {
				 Str[i] = tolower(Str[i]);
			 }
			 FirstLetter = (Str[i] == ' ') ? true : false;
		 }
		 return Str;
	 }
	 void LowerFirstLetterOfEachWord()
	 {
		 _Value = LowerFirstLetterOfEachWord(_Value);
	 }

	 static string UpperAllString(string Str)
	 {

		 for (short i = 0; i < Str.length(); i++)
		 {
		
			Str[i] = toupper(Str[i]);
		
		 }
		 return Str;
	 }
	 void UpperAllString()
	 {
		 _Value = UpperAllString(_Value);
	 }

	 static string LowerAllString(string Str)
	 {

		 for (short i = 0; i < Str.length(); i++)
		 {

			 Str[i] = tolower(Str[i]);

		 }
		 return Str;
	 }
	 void LowerAllString()
	 {
		 _Value = LowerAllString(_Value);
	 }

	 static char InvertCharcterCase(char Letter)
	 {
		 return islower(Letter) ? toupper(Letter) : tolower(Letter);
	 }
	 static string InvertLettersCase(string& S)
	 {

		 for (short i = 0; i < S.length(); i++)
		 {

			 S[i] = InvertCharcterCase(S[i]);

		 }
		 return S;
	 }
	 void InvertLettersCase()
	 {
		 _Value = InvertLettersCase(_Value);
	 }


	enum enWhatTypeLetter { SmallLetter = 1, CapitalLetter = 2, All = 3 };
	static short CountLetters(string Str, enWhatTypeLetter WhatCount = enWhatTypeLetter::All)
	 {

		 if (WhatCount == enWhatTypeLetter::All)
		 {
			 return Str.length();
		 }

		 short Count = 0;
		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (WhatCount == enWhatTypeLetter::CapitalLetter && isupper(Str[i]))
			 {
				 Count++;
			 }

			 if (WhatCount == enWhatTypeLetter::SmallLetter && islower(Str[i]))
			 {
				 Count++;
			 }
		 }
		 return Count;
	 }

	static short CountCapitalLetter(string Str)
	{
	 return CountLetters(Str, enWhatTypeLetter::CapitalLetter);
	}
	short CountCapitalLetter()
	{
		return CountCapitalLetter(_Value);
	}

	 static short CountSmallLetter(string Str)
	 {
		 return CountLetters(Str, enWhatTypeLetter::SmallLetter);
	 }
	 short CountSmallLetter()
	 {
		 return CountSmallLetter(_Value);
	 }

	static short WhatLetterCount(string Str, char Ch= ' ')
	{
		 short Count = 0;

		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (tolower(Ch) == tolower(Str[i]))
			 {
				 Count++;
			 }
		 }
		 return Count;
	}
	short WhatLetterCount(char Ch)
	{
		return  WhatLetterCount(_Value, Ch);
	}

	 static bool IsCharVowel(char Letter)
	 {
		 Letter = tolower(Letter);

		 return ((Letter == 'a') || (Letter == 'e') || (Letter == 'i') || (Letter == 'o') || (Letter == 'u'));

	 }
	 static short CountVowelLetters(string Str)
	 {
		 short Count = 0;

		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (IsCharVowel(Str[i]))
				 Count++;
		 }
		 return Count;
	 }
	 short CountVowelLetters()
	 {
		 return CountVowelLetters(_Value);
	 }

	 static void PrintVowelLetters(string Str)
	 {

		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (IsCharVowel(Str[i]))
				 cout << Str[i] << "   ";
		 }
		 cout << endl;
	 }
	 void PrintVowelLetters()
	 {
		 PrintVowelLetters(_Value);
	 }

	 static void PrintEachWordInString(string Str)
	 {
		 string delim = " "; // delimiter  Or Space
		 short Pos = 0;
		 string sWord; // define a string variable

		 cout << "Your string words are: \n\n";

		 //use find() function to get the position of the delimiter
		 while ((Pos = Str.find(delim)) != std::string::npos) // true
		 {
			 sWord = Str.substr(0, Pos); // store the word
			 if (sWord != " ")
			 {
				 cout << sWord << endl;
			 }
			 Str.erase(0, Pos + delim.length()); // erase() until position and move to next word. 
		 }
		 if (Str != " ")
		 {
			 cout << Str << endl; // it print last word of the string.
		 }
	 }
	 void PrintEachWordInString()
	 {
		 PrintEachWordInString(_Value);
	 }

	 static short CountWords(string Str)
	 {
		 string delim = " "; // delimiter  Or Space
		 string sWord; // define a string variable
		 short Pos = 0, Count = 0;

		 //use find() function to get the position of the delimiter
		 while ((Pos = Str.find(delim)) != std::string::npos) // true
		 {
			 sWord = Str.substr(0, Pos); // store the word
			 if (sWord != " ")
			 {
				 Count++;
			 }
			 Str.erase(0, Pos + delim.length()); // erase() until position and move to next word. 
		 }
		 if (Str != " ")
		 {
			 Count++;
		 }
		 return Count;
	 }
	 short CountWords()
	 {
		 return CountWords(_Value);
	 }

	 
	 static vector <string> Split(string Str, string delim)
	 {
		 vector <string> vSplitWords;

		 string sWord; // define a string variable
		 short Pos = 0;

		  //use find() function to get the position of the delimiter
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
	 static void PrintSplitStringEachWordInVector(string Str, string delim = " ")
	 {
		 vector <string> vSplitWords = Split(Str, delim);

		 for (string& i : vSplitWords)
		 {
			 cout << i << "\n";
		 }
	 }
	 void PrintSplitStringEachWordInVector()
	 {
		 PrintSplitStringEachWordInVector(_Value);
	 }

	 static string TrimLeft(string Str)
	 {
		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (Str[i] != ' ')
				 return Str.substr(i, Str.length() - i);
		 }
		 return "";
	 }
	 void TrimLeft()
	 {
		 _Value = TrimLeft(_Value);
	 }

	 static string TrimRight(string Str)
	 {

		 for (short i = Str.length() - 1; i >= 0; i--)
		 {
			 if (Str[i] != ' ')
				 return  Str.substr(0, i + 1);
		 }
		 return "";
	 }
	 void TrimRight()
	 {
		 _Value = TrimRight(_Value);
	 }

	 static string Trim(string Str)
	 {
		 return TrimRight(TrimLeft((Str)));
	 }
	 void Trim()
	 {
		 _Value = Trim(_Value);
	 }

	 static string JoinString(string S1, string delim)
	 {
		 vector <string> vSplitWords = Split(S1, " ");

		 string Str = "";
		 for (string& i : vSplitWords)
		 {
			 Str = Str + i + delim;
		 }
		 return Str.substr(0, Str.length() - delim.length());
	 }
	 string JoinString(string delim)
	 {
		 return JoinString(_Value, delim); // for object
	 } 


	 static string ReversString(string Str)
	 {

		 vector <string> vString;
		 vString = Split(Str, " ");

		 string Rstr = "";

		 vector<string>::iterator iter = vString.end();

		 while (iter != vString.begin())
		 {
			 --iter;
			 Rstr += *iter + " ";

		 }
		 Rstr = Rstr.substr(0, Rstr.length() - 1);

		 return Rstr;
	 }
	 void ReversString()
	 {
		 _Value = ReversString(_Value);
	 }

	 static string ReplaceWords(string Str, string Word, string ReplaceWord)
	 {
		 short Pos = Str.find(Word);

		 while (Pos != std::string::npos)
		 {

			 Str = Str.replace(Pos, Word.length(), ReplaceWord);
			 Pos = Str.find(Word); // find next 
		 }
		 return Str;
	 }
	 string ReplaceWords(string Word, string ReplaceWord)
	 {
		 return ReplaceWords(_Value, Word, ReplaceWord); // for object
	 }

	 // Replace Words Custom
	 static string JoinString(vector <string> vSplitWords, string delim)
	 {
		 string Str = "";
		 for (string& i : vSplitWords)
		 {
			 Str = Str + i + delim;
		 }
		 return Str.substr(0, Str.length() - delim.length());
	 }
	 static string ReplaceWordsCustom(string Str, string Word, string ReplaceWord, bool MatchCase = true)
	 {
		 vector <string> vString = Split(Str, " ");

		 for (string& S : vString)
		 {
			 if (MatchCase)
			 {
				 if (S == Word)
				 {
					 S = ReplaceWord;
				 }
			 }
			 else
			 {
				 if (LowerAllString(S) == LowerAllString(Word))
				 {
					 S = ReplaceWord;
				 }
			 }
		 }
		 return JoinString(vString, " ");
	 }
	 string ReplaceWordsCustom(string Word, string ReplaceWord)
	 {
		 return ReplaceWordsCustom(_Value, Word, ReplaceWord); // For Object
	 }
	

	 static string RemovePunctution(string Str)
	 {
		 string S1 = "";
		 for (short i = 0; i < Str.length(); i++)
		 {
			 if (!ispunct(Str[i]))
			 {
				 S1 += Str[i];
			 }
		 }
		 return S1;
	 }
	 void RemovePunctution()
	 {
		 _Value = RemovePunctution(_Value);
	 }


};

