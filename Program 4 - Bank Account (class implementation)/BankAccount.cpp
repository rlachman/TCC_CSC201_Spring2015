#include <iostream>
#include <string>


using namespace std;

#include "BankAccount.h"

BankAccount::BankAccount()
{
	Current_Balance = 1000;// sets balance to 1000
	Number_of_Transactions = 0;//sets transactions to 0
}
BankAccount::BankAccount(int balance)
{
	Current_Balance = balance;
	Number_of_Transactions = 0;
}
void BankAccount::deposit(int amount)
{
	Current_Balance = Current_Balance + amount;// adds the balance changes
	Number_of_Transactions++;//incaraments transactions
}
void BankAccount::withdrawl(int amount)
{
	if(amount > Current_Balance)
    {
		cout << "Insufficient balance" << endl;
	}
	else
    {
		Current_Balance = Current_Balance - amount;//remove amount from balance
		Number_of_Transactions++;//incaraments transactions
	}

}
int BankAccount::getBalance() const
{
	return Current_Balance;// Returns upodated balance
}
int BankAccount::getTransactions() const
{
	return Number_of_Transactions;//Returns number of transactions
}

