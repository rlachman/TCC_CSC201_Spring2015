class BankAccount //creates the class
{
public:
	BankAccount();// Two constructors 
	BankAccount(int balance);
	void deposit(int amount);//Two tansformers
	void withdrawl(int amount);
	int getBalance() const; //Two observers
	int getTransactions() const;
private: 
	int Current_Balance;
	int Number_of_Transactions;
};
