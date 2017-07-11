//Ryan Lachman 
//CSC 201 - May 6 2015
//Project: Bank Account

//this program will keep a total of a bank account balance after a series of transactions and withdraws

#include <iostream>
#include <string>
#include <fstream>


using namespace std;

#include "BankAccount.cpp"

int main()
{
	BankAccount account(2000);
	char transaction;// withdraw or deposit transactions
	int amount;// keep record of the trasaction amounts
	ifstream inFile;//if stream creation
	ofstream outFile;//outstream creation
	inFile.open("input.txt");
	outFile.open("output.txt");
	if(inFile.is_open() && outFile.is_open())
    {
		while(inFile >> transaction >> amount)// while in data loop
        {
			if(transaction == 'w')//reads w from input file then withdraw
            {
				outFile << "w ";
				cout << "w ";
				if(amount > account.getBalance())
                // if amount is to much compared to current balance
                {
					account.withdrawl(amount);
					outFile << "Insufficient balance" << endl;
				}
				else
                //else ammount is outputed
                {
                    account.withdrawl(amount);
					outFile << account.getBalance() << endl;
					cout << account.getBalance() << endl;
				}
			}
			else
			if(transaction == 'd')//reads d from input file then deposit
            {
				account.deposit(amount);
				outFile << "d " << account.getBalance() << endl;
				cout << "d " << account.getBalance() << endl;
			}
		}
		outFile << "Current balance: " << account.getBalance() << endl;
		outFile << "Number of transactions: " << account.getTransactions() << endl;
		cout << "Current balance: " << account.getBalance() << endl;
		cout << "Number of transactions: " << account.getTransactions() << endl;
	}
    system("pause");
    return 0;
}
