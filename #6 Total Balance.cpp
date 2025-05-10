#include<iostream>
#include<iomanip>
#include"clsBankClient.h"
#include"clsInputValidate.h"
#include"clsPerson.h"
#include "clsUtil.h"
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

void DeleteClient()
{
	string AccountNumber = "";
	cout << "Please Enter Client Account Number: ";
	AccountNumber = clsInputValidate::ReadString();

	while (!clsBankClient::IsClientExist(AccountNumber))
	{
		cout << "Account Number Is Not Found, Choose Anouther One: ";
		AccountNumber = clsInputValidate::ReadString();
	}

	clsBankClient Client = clsBankClient::Find(AccountNumber);
	Client.Print();

	char Answer = 'y';
	cout << "Do You Want To Delete This Client? ";
	cin >> Answer;

	if (Answer == 'y' || Answer == 'Y')
	{
		if (Client.Delete())
		{
			cout << "\nClient Deleted Successfully :-)\n";
			Client.Print();
		}
		else
		{
			cout << "\nError Client Was Not Deleted\n";
		}
	}
	

}

void PrintEachClient(clsBankClient Client)
{
	cout << "| " << setw(15) << left << Client.GetAccountNumber();
	cout << "| " << setw(20) << left << Client.GetFullName();
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(20) << left << Client.Email;
	cout << "| " << setw(15) << left << Client.PinCode;
	cout << "| " << setw(12) << left << Client.AccountBalance;
}
void ShowAllClients()
{
	vector <clsBankClient> vAllClients = clsBankClient::GetAllClientsList();

	cout << "\t\t\t\tClient List (" << vAllClients.size() << ") Client(s).\n";
	cout << "--------------------------------------------------";
	cout << "---------------------------------------------------\n\n";
	cout << "| " << setw(15) << left << "Account Number";
	cout << "| " << setw(20) << left << "Client Name";
	cout << "| " << setw(12) << left << "Phone";
	cout << "| " << setw(20) << left << "Email";
	cout << "| " << setw(15) << left << "Pin Code";
	cout << "| " << setw(12) << left << "Balance";
	cout << "\n-------------------------------------------------";
	cout <<	"-----------------------------------------------------\n\n";
	
	if (vAllClients.size() == 0)
	{
		cout << "\n\t\t\t\tThere Are No Clients In The File :-( \n\n\n";
	}
	else
	{
		for (clsBankClient& C : vAllClients)
		{
			PrintEachClient(C);
			cout << endl;
		}
	}
	cout << "--------------------------------------------------";
	cout << "---------------------------------------------------\n\n";

}

void PrintEachBalanceForClient(clsBankClient Client)
{
	cout << "| " << setw(30) << left << Client.GetAccountNumber();
	cout << "| " << setw(40) << left << Client.GetFullName();
	cout << "| " << setw(30) << left << Client.AccountBalance;
}
void ShowTotalBalances()
{

	vector <clsBankClient> vAllClients = clsBankClient::GetAllClientsList();

	cout << "\n\t\tBalances List (" << vAllClients.size() << ") Client(s).\n";
	cout << "\n--------------------------------------";
	cout << "------------------------------------------------\n";
	cout << "| " << setw(30) << left << "Account Number";
	cout << "| " << setw(40) << left << "Client Name";
	cout << "| " << setw(30) << left << "Balance";
	cout << "\n------------------------------------------------";
	cout << "--------------------------------------\n\n";

	double TotalBalances = clsBankClient::GetTotalBalances();

	if (vAllClients.size() == 0)
	{
		cout << "\n\t\t\t\tThere Are No Clients In The File :-( \n\n\n";
	}
	else
	{
		for (clsBankClient& C : vAllClients)
		{
			PrintEachBalanceForClient(C);
			cout << endl;
		}
	}
	cout << "\n----------------------------------------";
	cout << "----------------------------------------------\n";
	cout << right << setw(75) << "Total Balances = " << TotalBalances << endl;
	cout << right << setw(50) << "( " << clsUtil::NumbersToText(TotalBalances) << " )" << endl;
}


int main()
{

	ShowTotalBalances();



	system("pause>0");
	return 0;
}