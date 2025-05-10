#include<iostream>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsPerson.h"
using namespace std;

void ReadClientInfo(clsBankClient& Client)
{
	cout << "\nEnter First Name: ";
	Client.FirstName = clsInputValidate::ReadString();

	cout << "\nEnter Last Name: ";
	Client.LastName = clsInputValidate::ReadString();

	cout << "\nEnter Email: ";
	Client.Email = clsInputValidate::ReadString();

	cout << "\nEnter Phone: ";
	Client.Phone = clsInputValidate::ReadString();

	cout << "\nEnter PinCode: ";
	Client.PinCode = clsInputValidate::ReadString();

	cout << "\nEnter Account Balance: ";
	Client.AccountBalance = clsInputValidate::ReadFtNumber("Invalid Number, Enter again: ");

	cout << "---------------------\n";
}

void UpdateClient()
{
	string AccountNumber = "";
	cout << "Please Enter Client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Not Found, Choose Anouther One: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client1 = clsBankClient::Find(AccountNumber);
	Client1.Print();

	cout << "\nUpdate Client Info:\n";
	cout << "---------------------\n";

	ReadClientInfo(Client1);

	clsBankClient::enSaveResults SaveResult;
	SaveResult = Client1.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
		cout << "\nAccount Update Seccessfully :-)\n";
		Client1.Print();
		break;

	case clsBankClient::enSaveResults::svFailEmptyObject:
		cout << "\nError Account Was Not Saved Because It's Empty :-(\n";
		break;
	}
}

void AddNewClient() 
{
	string AccountNumber = "";
	cout << "Please Enter Client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Found, Choose Anouther One: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

	ReadClientInfo(NewClient);

	clsBankClient::enSaveResults SaveResult;
	SaveResult = NewClient.Save();

	switch (SaveResult)
	{
	case clsBankClient::enSaveResults::svSucceeded:
		cout << "\nAccount Added Seccessfully :-)\n";
		NewClient.Print();
		break;

	case clsBankClient::enSaveResults::svFailEmptyObject:
		cout << "\nError Account Was Not Saved Because It's Empty :-(\n";
		break;

	case clsBankClient::enSaveResults::enFaildAccountNumberExists:
		cout << "\nError Account Was Not Saved Because Account Number Exists :-(\n";
		break;
	}
}


int main()
{


	AddNewClient();



	system("pause>0");
	return 0;
}