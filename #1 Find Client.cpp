#include <iostream>
#include "clsBankClient.h"
using namespace std;


int main()
{
	clsBankClient Client1 = clsBankClient::Find("A102");
	Client1.Print();

	clsBankClient Client2 = clsBankClient::Find("A101", "123");
	Client2.Print();


	cout << endl << Client1.IsClientExist("A101") << endl;


	return 0;
}