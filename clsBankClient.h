#pragma once
#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"clsPerson.h"
#include"clsString.h"
using namespace std;

class clsBankClient : public clsPerson
{

private:

	enum enMode {EmptyMode = 0, UpdateMode = 2, AddNewMode = 3};

	enMode _Mode;
	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;
	bool _FlagForRemoveClient = false;


	static clsBankClient _ConvertLineClientObject(string LineInFile, string Seperator = "#//#")
	{
		vector <string> vClient = clsString::Split(LineInFile, Seperator);

		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2], vClient[3], vClient[4],
			vClient[5], stof(vClient[6]));
	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static vector <clsBankClient> _LoadClientsDataFromFile()
	{
		
		fstream MyFile;
		vector <clsBankClient> vAllClients;

		MyFile.open("BankClients.txt", ios::in); // Read mode

		if (MyFile.is_open())
		{
			string LineInFile;
			while (getline(MyFile, LineInFile))
			{
				clsBankClient EachClient = _ConvertLineClientObject(LineInFile);
				vAllClients.push_back(EachClient);
			}
		}
		MyFile.close();

		return vAllClients;
	}

	string _ConvertClientObjectToLine(clsBankClient Client, string Seperator = "#//#")
	{
		string S1 = "";
		S1 += Client.FirstName + Seperator;
		S1 += Client.LastName + Seperator;
		S1 += Client.Email + Seperator;
		S1 += Client.Phone + Seperator;
		S1 += Client.GetAccountNumber() + Seperator;
		S1 += Client.PinCode + Seperator;
		S1 += to_string(Client.AccountBalance);

		return S1;
	}

	void _SaveClientsDataToFile(vector <clsBankClient> vAllClients)
	{

		fstream MyFile;
		MyFile.open("BankClients.txt", ios::out); //Overwrite

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient& C : vAllClients)
			{
				Line = _ConvertClientObjectToLine(C);
				MyFile << Line << endl;	
			}
		}
		MyFile.close();
	}

	void _Update()
	{
		vector <clsBankClient> vClients;
		vClients = _LoadClientsDataFromFile();

		for (clsBankClient &C : vClients)
		{
			if (C.GetAccountNumber() == GetAccountNumber())
			{
				C = *this; 
				break;
			}
		}
		_SaveClientsDataToFile(vClients);
	}

	// Add New Client
	void _AddNew()
	{
		_AddDataLineToFile(_ConvertClientObjectToLine(*this));
	}
	void _AddDataLineToFile(string Line)
	{
		fstream MyFile;

		MyFile.open("BankClients.txt", ios::out | ios::app);

		if (MyFile.is_open())
		{
			MyFile << Line << endl;
		}
		MyFile.clear();
	}

	 // Delete
	void _SavingClientsToFile(vector <clsBankClient> vAllClients)
	{
		fstream MyFile;

		MyFile.open("BankClients.txt", ios::out); // Overwrite

		if (MyFile.is_open())
		{
			string Line;
			for (clsBankClient& C : vAllClients)
			{
				if (C.FlagForRemoveClient() == false)
				{
					Line = _ConvertClientObjectToLine(C);
					MyFile << Line << endl;
				}
			}
		}
		MyFile.close();
	}

public:
	
	clsBankClient(enMode Mode, string FirstName, string LastName, string Email, string Phone,
		string AccountNumber, string PinCod, float AccountBalance) : clsPerson(FirstName, LastName, Email, Phone)
	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCod;
		_AccountBalance = AccountBalance;
	}

	
	// Property Set
	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}
	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	// Property Get
	string GetAccountNumber()
	{
		return _AccountNumber;

	}
	string GetPinCode()
	{
		return _PinCode;
	}
	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	bool FlagForRemoveClient()
	{
		return _FlagForRemoveClient;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode))string PinCode;
	__declspec(property(get = GetAccountBalance, put = SetAccountBalance))float AccountBalance;


	static clsBankClient Find(string AccountNumber)
	{
		fstream MyFile;
		
		MyFile.open("BankClients.txt", ios::in); // Read mode

		if (MyFile.is_open())
		{
			string LineInFile;

			while (getline(MyFile, LineInFile))
			{
				clsBankClient Client = _ConvertLineClientObject(LineInFile);

				if (Client.GetAccountNumber() == AccountNumber)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}
	
		return _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{
		fstream MyFile;

		MyFile.open("BankClients.txt", ios::in); // Read mode

		if (MyFile.is_open())
		{
			string LineInFile;

			while (getline(MyFile, LineInFile))
			{
				clsBankClient Client = _ConvertLineClientObject(LineInFile);

				if (Client.GetAccountNumber() == AccountNumber && Client.GetPinCode() == PinCode)
				{
					MyFile.close();
					return Client;
				}
			}
			MyFile.close();
		}

		return _GetEmptyClientObject();
	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector <clsBankClient> _vAllClients = _LoadClientsDataFromFile();

		for (clsBankClient& C : _vAllClients)
		{

			if (C.GetAccountNumber() == _AccountNumber)
			{
				C._FlagForRemoveClient = true;
			}
		}

		_SavingClientsToFile(_vAllClients);

		*this = _GetEmptyClientObject();

		return true;
	}

	static vector <clsBankClient> GetAllClientsList()
	{
		return _LoadClientsDataFromFile();
	}

	static double GetTotalBalances()
	{
		vector <clsBankClient> vAllClients = clsBankClient::GetAllClientsList();

		double TotalBalances = 0;

		for (clsBankClient &C : vAllClients)
		{
			TotalBalances += C.AccountBalance;
		}
		return TotalBalances;
	}


	enum enSaveResults { svFailEmptyObject = 0, svSucceeded = 1 , enFaildAccountNumberExists = 2};

	enSaveResults Save()
	{
		switch (_Mode)
		{
		case clsBankClient::EmptyMode:

			if (IsEmpty())
			{
				return enSaveResults::svFailEmptyObject;
				break;
			}
			

		case clsBankClient::UpdateMode:

			_Update();
			return enSaveResults::svSucceeded;
			break;


		case clsBankClient::AddNewMode:

			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::enFaildAccountNumberExists;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;
				return enSaveResults::svSucceeded;
				break;
			}
		}
	}

	void Print()
	{
		cout << "\nClient Card:";
		cout << "\n---------------------------\n";
		cout << "FirstName     : " << FirstName << endl;
		cout << "LastName      : " << LastName << endl;
		cout << "FullName      : " << GetFullName() << endl;
		cout << "Email         : " << Email<< endl;
		cout << "Phone         : " << Phone << endl;
		cout << "AccountNumber : " << _AccountNumber << endl;
		cout << "PinCode       : " << _PinCode << endl;
		cout << "AccountBalance: " << _AccountBalance << endl;
		cout << "----------------------------\n";
	}

};

