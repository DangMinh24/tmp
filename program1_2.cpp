//File Name:program1.cpp
//Author: Dang Tran
//Student ID: s856f975
//Assignment Number: 1
#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

#define default_rate 1.0/100
#define default_name "Savings"
#define default_dollars 100
#define default_cents 0
using namespace std;

// Define structs below
struct Money {
    int dollars=default_dollars;
    int cents=default_cents;
    
};

struct Account {
    Money balance;
    double rate = default_rate;
    string name = default_name;
};

// Declare functions to do with Accounts and Money
Account createAccount(string file);
Account createAccount(string name, double rate, Money balance);
Account deposit(Account account, Money deposit);
Money withdraw( Account &account, Money withdraw);
void accrue(Account &account);
void print(Money money);
void print(Account account);

double amount(Money money);//additional function

// TEST HELPER FUNCTIONS -- DO NOT ALTER
int makePennies(Money m);
Money makeMoney(int p);
bool isNegative(Money m);
bool operator<(const Money& lhs, const Money& rhs);

// TEST FUNCTIONS -- DO NOT ALTER
bool testCreateAccountFile(bool n);
bool testCreateAccountParams();
bool testDeposit(Money dep);
bool testWithdraw(Money w);
bool testAccrue();
void testPrint(bool type, bool sign);

int main()
{
	// DO *NOT* ALTER THE MAIN FUNCTION
	int width = 50;
	char prev = std::cout.fill('.');
	std::cout << "\n--- Homework 1 Tests ---\n";
	std::cout << std::setw(width) << std::left << "createAccount(filename)" << testCreateAccountFile(true) << std::endl;
	std::cout << std::setw(width) << std::left << "createAccount(bad filename)" << testCreateAccountFile(false) << std::endl;
	std::cout << std::setw(width) << std::left << "createAccount(parameters)" << testCreateAccountParams() << std::endl;
	std::cout << "\n--- Begin Depost Testing ---\n";
	std::cout << std::setw(width) << std::left << "Deposit Message"; bool temp = testDeposit({10, 0});
	std::cout << std::setw(width) << std::left << "deposit()" << temp << std::endl;
	std::cout << std::setw(width) << std::left << "\nDeposit Message"; temp = testDeposit({0, -75});
	std::cout << std::setw(width) << std::left << "deposit() (negative deposit)" << temp << std::endl;
	std::cout << "--- End Deposit Testing ---\n\n";
	std::cout << "\n--- Begin Withdraw Testing---\n";
	std::cout << std::setw(width) << std::left << "Withdrawl Message"; temp = testWithdraw({10, 36});
	std::cout << std::setw(width) << std::left << "withdraw()" << temp << std::endl;
	std::cout << std::setw(width) << std::left << "\nWithdrawl Message"; temp = testWithdraw({60, 10});
	std::cout << std::setw(width) << std::left << "withdraw() (partial overdraft)" << temp << std::endl;
	std::cout << std::setw(width) << std::left << "\nWithdrawl Message"; temp = testWithdraw({200, 78});
	std::cout << std::setw(width) << std::left << "withdraw() (full overdraft)" << temp << std::endl;
	std::cout << std::setw(width) << std::left << "\nWithdrawl Message"; temp = testWithdraw({-3, -50});
	std::cout << std::setw(width) << std::left << "withdraw() (negative withdraw)" << temp << std::endl;
	std::cout << "--- End Withdraw Testing---\n\n";
	std::cout << "\n--- Begin Accrue Test ---\n";
	std::cout << std::setw(width) << std::left << "Accrue Message"; temp = testAccrue(); std::cout << std::endl;
	std::cout << std::setw(width) << std::left << "accrue()" << temp << std::endl;
	std::cout << "--- End Accrue Test ---\n\n";
	std::cout << std::setw(width) << std::left << "print() (Money) [Expect $567.32]"; testPrint(false, true); std::cout << std::endl;
	std::cout << std::setw(width) << std::left << "print() (Money) (negative) [Expect ($567.32)]"; testPrint(false, false); std::cout << std::endl;
	std::cout << std::setw(width) << std::left << "print() (Account) [Expect $567.32]"; testPrint(true, true); std::cout << std::endl;
	std::cout << std::setw(width) << std::left << "print() (Account) (negative) [Expect ($567.32)]"; testPrint(true, false); std::cout << std::endl;

	std::cout.fill(prev);

	return 0;
}

// IMPLEMENT YOUR FUNCTIONS HERE
Account createAccount(string file) {
    ifstream ifs(file, ios::in);

    Account result;

    if (ifs.good()) {// Check file existence
        getline(ifs, result.name);        
        ifs >> result.rate;
        ifs >> result.balance.dollars >> result.balance.cents;
        
    }
    return result;
}

Account createAccount(string name, double rate, Money balance){
    Account result;
    
    result.name=name;
    result.rate=rate;
    result.balance=balance;
    return result;
}


double amount(Money money){ // An additional function to take actual value of money - to deal with cases cents >100  
    return double(money.dollars)+double(money.cents)/100.0; 
}

Account deposit(Account account, Money deposit){
    if(deposit.dollars <0 or deposit.cents <0){
        cout << "Deposit amount should be a positive money."<<endl;
        return account;
    }else{ 
        double account_val=amount(account.balance);
        double deposit_val=amount(deposit);
        account_val+=deposit_val;
        
        cout << "$"<< deposit_val<<" deposited into " <<account.name<<"."<<endl;
        
        
        account.balance.dollars=int(account_val);
        account.balance.cents=int(round((account_val-account.balance.dollars)*100)); //Formula to convert money back into cents 
        return account;
    }
}



Money withdraw( Account &account, Money withdraw){
    Money money;
    if (withdraw.dollars <0  or withdraw.cents <0){
        cout << "Withdraw amount should be a positive money."<<endl;
        money.dollars=0;
        money.cents=0;
        return money;
    }else {
        double balance=amount(account.balance);
        double withdraw_val=amount(withdraw);
        if(withdraw_val >= balance+50.0){ 
            //When withdrawing the amount that larger than possible one (account's balance+50), the maximum amount that we 
            // can take out becomes account's balance+50 only. Consequently, the account will in debt $50.00.
            double remain= -50;
            money.dollars=int(balance+50.0);
            money.cents=int(round((balance+50-money.dollars)*100));
            account.balance.dollars=int(remain);
            account.balance.cents=0;
            
            return money;
        }else{
            //We want to find the remain amount of the account (also consider the case where remain cents is negative)
            cout << "$"<<withdraw_val<<" withdrawn from "<<account.name<<endl;
            double remain=balance-withdraw_val;
            account.balance.dollars=int(remain);
            account.balance.cents=int(round((remain-account.balance.dollars)*100));
            
            money.dollars=withdraw.dollars;
            money.cents=withdraw.cents;
            return money;
        }
    } 
}

void accrue(Account &account){// Find interest by rate and update accordingly
    double interest=account.rate* amount(account.balance);
    double new_balance= amount(account.balance)+interest;
    account.balance.dollars=int(new_balance);
    account.balance.cents=int(round((new_balance-account.balance.dollars)*100));
    cout<< "At "<<account.rate<<"%, your "<<account.name<<" account earned $"<<account.balance.dollars <<"."<<account.balance.cents<<"."<<endl;
    return;
} 

void print(Money money){
    double money_val=amount(money);
    if (money_val>=0){
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout << "You have $"<< money_val    <<endl;
        return;
    }else {
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout << "($"<< abs(money_val)<<")" <<endl;
        
    }
    
}
void print(Account account){
    double account_val=amount(account.balance);
    if (account_val>=0){
        std::cout << std::fixed;
        std::cout << std::setprecision(2);
        cout  << "$"<< account_val<<endl;
        return;
    }else {
        std::cout <<    std::fixed;
        std::cout << std::setprecision(2);
        cout  << "($"<< abs(account_val)<<")"<<endl;
        return;
    }
   
}

// HELPER FUNCTION IMPLEMENTATIONS -- DO NOT ALTER
int makePennies(Money m)
{
	return (m.dollars * 100) + m.cents;
}

Money makeMoney(int p)
{
	return Money{p / 100, p % 100};
}

bool isNegative(Money m)
{
	if (m.dollars < 0 || m.cents < 0)
		return true;
	else
		return false;
}

bool operator<(const Money& lhs, const Money& rhs)
{
	int leftPennies = makePennies(lhs);
	int rightPennies = makePennies(rhs);

	return leftPennies < rightPennies;
}
// DO *NOT* ALTER THESE FUNCTION IMPLEMENTATIONS
bool testCreateAccountFile(bool n)
{
	std::string fn;
	if (n)
		fn = "inputs";
	else
		fn = "garbage";
	
	Account acc = createAccount(fn);

	if (acc.name == "Saving for college" && acc.rate == 0.01 && acc.balance.dollars == 4321 && acc.balance.cents == 98)
		return true;
	else if (fn == "garbage" && acc.name == "Savings" && acc.rate == 0.01 && acc.balance.dollars == 100 && acc.balance.cents == 0)
		return true;
	else
		return false;
}

bool testCreateAccountParams()
{
	Account t = createAccount("Roth IRA", 0.055, {1234, 56});
	if (t.name == "Roth IRA" && t.rate == 0.055 && t.balance.dollars == 1234 && t.balance.cents == 56)
		return true;
	else
		return false;
}

bool testDeposit(Money dep)
    {
	Account t = createAccount("Checking", 0.005, {50, 0});
	int dollars = dep.dollars;
	int cents = dep.cents;

	t = deposit(t, dep);

	if (t.balance.dollars == 50 + dollars && t.balance.cents == 0 + cents) {
		return true;
	} else if (isNegative(dep)) {
		if (t.balance.dollars == 50 && t.balance.cents == 0) {
			return true;
		}
	} else {
		return false;
	}

	return false;
}

// USE AS DEBUGGER EXAMPLE
bool testWithdraw(Money w)
{
	Account t = createAccount("Index Fund", 0.06, {50, 0});
	Money overdrawLimit{t.balance.dollars + 50, t.balance.cents};

	Money amount = withdraw(t, w);

	if (isNegative(w)) {
		if (amount.dollars == 0 && amount.cents == 0) {
			return true;
		}
		return false;
	} else if (w < t.balance) {
		if (w.dollars == amount.dollars && w.cents == amount.cents) {
			return true;
		}
		return false;
	} else if (w < overdrawLimit) {
		if (w.dollars == amount.dollars && w.cents == amount.cents) {
			return true;
		}
		return false;
	} else {
		if (amount.dollars == overdrawLimit.dollars && amount.cents == overdrawLimit.cents) {
			return true;
		}
		return false;
	}

	return false;
}

bool testAccrue()
{
	Account t = {{48, 31}, 0.02, "Savings"};

	accrue(t);

	if (t.balance.dollars == 49 && t.balance.cents == 28)
		return true;
	else
		return false;
}

void testPrint(bool type, bool sign)
{
	Account a;
	Money m;

	if (type) {
		if (sign) {
			a = createAccount("CD", 0.03, {567, 32});
		} else {
			a = createAccount("CD", 0.03, {-567, -32});
		}
		print(a);
		return;
	} else {
		if (sign) {
			m = {567, 32};
		} else {
			m = {-567, -32};
		}
		print(m);
		return;
	}
}
