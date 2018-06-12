//File Name:program2.cpp
//Author: Dang Tran
//Student ID: s856f975
//Assignment Number: 2

// Add Or Subtract Libraries As Needed
#include <cmath>
#include <iomanip>
#include <iostream>
#include <string.h>
#include <string>

using namespace std;
// Place Money Class Definition Here
class Money{
  public:
    Money();
    Money(int idollars, int icents);
    Money(int idollars);
    Money(double amount);

    bool isNegative() const;
    bool isEqual(const Money &m) const;

    void add(const Money &m);
    void subtract(const Money &m);
    
    void print() const;

       
    const double getPennies() const; // helper function
    
  private:
    int dollars;
    int cents;

};

// Place Account Class Definition Here
class Account{
  private:
    string name;
    double rate;
    Money balance;
  public:
    Account();
    Account(string iname, double irate, Money imoney);
    Account(string iname, double irate, int idollars);
    Account(string iname, double irate, double ibalance);
    
    
    const string getName() const;
    double getRate() const;
    const Money getBalance() const;
    
    void setName(string newName);
    void deposit(const Money &m);
    void deposit(int d, int c);
    void deposit(int d);
    void deposit(double d);

    const Money withdraw(const Money &m);
    const Money withdraw(int d,int c);
    const Money withdraw(int d);
    const Money withdraw(double d);

    void accrue();

    void print() const;

    void transferTo(Account &dest, const Money &amount);
    
};

// Define Non-Member Function Here
const Account createAccount();
double str2double(const string & istr ); //Helper function for non-class function create_account

// Test Functions; *** DO NOT ALTER ***
bool moneyIsNegative(bool expected);
bool moneyAdd();
bool moneySubtractPos();
bool moneySubtractNeg();
void moneyPrint(double arg);
bool acctGetName();
bool acctGetRate();
bool acctGetBalance();
bool acctSetName();
bool acctDep01();
bool acctDep02();
bool acctDep03();
bool acctDep04();
void acctBadDep();
bool acctWith01();
bool acctWith02();
bool acctWith03();
bool acctWith04();
bool acctWithPart01();
bool acctWithPart02();
void acctBadWith();
bool acctAccrue();
void acctPrint(double arg);
bool acctTransfer();

// Main Function; *** DO NOT ALTER ***
int main()
{
	char prev = std::cout.fill('.');

	std::cout << "*** TESTING MONEY CLASS FUNCTIONS ***\n";
	std::cout << std::setw(57) << std::left << "3. Testing Money class IsNegative:" << (moneyIsNegative(true)) << std::endl;
	std::cout << std::setw(57) << std::left << "4. Testing Money class IsNegative:" << (moneyIsNegative(false)) << std::endl;
	std::cout << std::setw(57) << std::left << "5. Testing Money class Add:" << (moneyAdd()) << std::endl;
	std::cout << std::setw(57) << std::left << "6. Testing Money class Subtract:" <<  (moneySubtractPos()) << std::endl;
	std::cout << std::setw(57) << std::left << "7. Testing Money class Subtract:" <<  (moneySubtractNeg()) << std::endl;
	std::cout << std::setw(57) << std::left << "8. Testing Money class Print ( Must match $5.44 ):"; (moneyPrint(5.44)); std::cout << std::endl;
	std::cout << std::setw(57) << std::left << "9. Testing Money class Print ( Must match ($5.44) ):"; (moneyPrint(-5.44)); std::cout << std::endl;

	std::cout << "\n*** TESTING ACCOUNT CLASS FUNCTIONS ***\n";
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "1. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetName:" << (acctGetName()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "2. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetRate:" << (acctGetRate()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "3. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class GetBalance:" << (acctGetBalance()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "4. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class SetName:" << (acctSetName()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "5. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #1:" << (acctDep01()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "6. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #2:" << (acctDep02()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "7. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #3:" << (acctDep03()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "8. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit #4:" << (acctDep04()) << std::endl;
	std::cout << std::setw(4) << std::left << std::setfill(' ') << "9. " << std::setw(53) << std::left << std::setfill('.') << "Testing Account class Deposit (ERROR):"; acctBadDep();
	std::cout << std::setw(4) << std::left << "10. " << std::setw(53) << std::left << "Testing Account class Withdraw #1:" << (acctWith01()) << std::endl;
	std::cout << std::setw(4) << std::left << "11. " << std::setw(53) << std::left << "Testing Account class Withdraw #2:" << (acctWith02()) << std::endl;
	std::cout << std::setw(4) << std::left << "12. " << std::setw(53) << std::left << "Testing Account class Withdraw #3:" << (acctWith03()) << std::endl;
	std::cout << std::setw(4) << std::left << "13. " << std::setw(53) << std::left << "Testing Account class Withdraw #4:" << (acctWith04()) << std::endl;
	std::cout << std::setw(4) << std::left << "14. " << std::setw(53) << std::left << "Testing Account class Withdraw (OVERDRAW):" << (acctWithPart01()) << std::endl;
	std::cout << std::setw(4) << std::left << "15. " << std::setw(53) << std::left << "Testing Account class Withdraw (PARTIAL):" << (acctWithPart02()) << std::endl;
	std::cout << std::setw(4) << std::left << "16. " << std::setw(53) << std::left << "Testing Account class Withdraw (ERROR):"; acctBadWith();
	std::cout << std::setw(4) << std::left << "17. " << std::setw(53) << std::left << "Testing Account class Accrue: " << (acctAccrue()) << std::endl;
	std::cout << std::setw(4) << std::left << "18. " << std::setw(53) << std::left << "Testing Account class Transfer: " << (acctTransfer()) << std::endl;
	std::cout << std::setw(4) << std::left << "19. " << std::setw(53) << std::left << "Testing Account class Print ( Must match $50.00 ):"; (acctPrint(50.00)); std::cout << std::endl;
	std::cout << std::setw(4) << std::left << "20. " << std::setw(53) << std::left << "Testing Account class Print ( Must match ($50.00) ):"; (acctPrint(-50.00)); std::cout << std::endl;

	Account account = createAccount();
	std::cout << "\n\n*** TESTING NON-CLASS FUNCTION CREATEACCOUNT ***\n";
	std::cout << std::setw(19) << std::left << "1. Account Name:" << account.getName() << std::endl;
	std::cout << std::setw(19) << std::left << "2. Interest Rate:" << account.getRate() << std::endl; 
	std::cout << std::setw(19) << std::left << "3. Balance:"; (account.getBalance()).print(); std::cout << std::endl; 

	std::cout.fill(prev);

	return 0;
}


// Implement Money Class Functions Here
Money::Money(){
  dollars=0;
  cents=0;
}

Money::Money(int d,int c){
  dollars=d;
  cents=c;
}

Money::Money(int d){
  dollars=d;
  cents=0;
}

Money::Money(double amount){
  dollars= static_cast<int> (amount);
  cents= static_cast<int>(round((amount-dollars)*100));
}

bool Money::isNegative() const{
  if (dollars<0 || cents<0) 
    return true;
  else 
    return false;
}

void Money::add( const Money &m){
  dollars+=m.dollars;
  cents+=m.cents;
}

void Money::subtract(const Money &m){
    dollars-=m.dollars;
    cents-=m.cents;
}

bool Money::isEqual(const Money &m) const{
  if(this->getPennies()== m.getPennies() )
    return true;
  else 
    return false;
}

void Money::print() const{
  double amount= (*this).getPennies();
  if ((*this).isNegative()==true){
    cout << std::fixed;
    cout << std::setprecision(2);
    cout <<"($"<<amount<<")"; 
  }
  else {
    cout << std::fixed;
    cout << std::setprecision(2);
    cout <<"$"<<amount;
  }
} 

const double Money::getPennies() const{
  return static_cast<double>((*this).dollars)+static_cast<double>((*this).cents)/100.0;
}


// Implement Account Class Functions Here
Account::Account(){
  name="Savings";
  rate=0;
}

Account::Account(string iname, double irate, Money imoney){
	name=iname;
	rate=irate;
	balance=imoney;
}
Account::Account(string iname,double irate, int idollars){
	name=iname;
	rate=irate;
        Money m(idollars);
	balance.add(m);
}
Account::Account(string iname, double irate, double amount){
	name=iname;
	rate=irate;
        Money m(amount);
	balance.add(m);
}

const string Account::getName()const{
	return name;
}

double Account::getRate() const{
	return rate;
}

const Money Account::getBalance() const {
    return balance;
}

void Account::setName(string newName){
	name=newName;
}

void Account::deposit(const Money &m){
	if (m.isNegative()==true){//print error
		cout<<"Deposit money should not be negative"<<endl;
		return;
	}
	else{
		balance.add(m);
	}
}

void Account::deposit(int d,int c){
	Money tmp(d,c);		//temporary Money object to be added
	
	if (tmp.isNegative()==true){//print error
		cout<<"Deposit money should not be negative"<<endl;
		return;
	}
	else{
		balance.add(tmp);
	}
}

void Account::deposit(int d){
	Money tmp(d);
	if (tmp.isNegative()==true){//print error
		cout<<"Deposit money should not be negative"<<endl;
		return;
	}
	else{
		balance.add(tmp);
	}
}

void Account::deposit(double amount){
	Money tmp(amount);
	if (tmp.isNegative()==true){//print error
		cout<<"Deposit money should not be negative"<<endl;
		return;
	}
	else{
		balance.add(tmp);
	}
}

const Money Account::withdraw(const Money &m){

	if (m.isNegative()==true){//print error
		cout<<"Withdraw money should not be negative"<<endl;
		return Money();
	}

	double overdraw_amount=balance.getPennies()+50.0;
	double hoped_amount= m.getPennies();
	if(hoped_amount > overdraw_amount){ 
		//If the user want to draw more than amount of money in his account $50,
		//they can only get a restricted amount. And their account will in debt $50
		Money tmp(overdraw_amount);
		balance.subtract(tmp);

		return tmp;
	}else {
		Money tmp(hoped_amount);
		balance.subtract(hoped_amount);
		return tmp;
	}
}
const Money Account::withdraw(int d,int c){
	Money m(d,c);
	if (m.isNegative()==true){//print error
		cout<<"Withdraw money should not be negative"<<endl;
		return Money();
	}
	double overdraw_amount=balance.getPennies()+50.0;
	double hoped_amount= m.getPennies();
	if(hoped_amount > overdraw_amount){ 
		//If the user want to draw more than amount of money in his account $50,
		//they can only get a restricted amount. And their account will in debt $50
		Money tmp(overdraw_amount);
		balance.subtract(tmp);

		return tmp;
	}else {
		Money tmp(hoped_amount);
		balance.subtract(hoped_amount);
		return tmp;
	}
}
const Money Account::withdraw(int d){
	Money m(d);
	if (m.isNegative()==true){//print error
		cout<<"Withdraw money should not be negative"<<endl;
		return Money();
	}
	double overdraw_amount=balance.getPennies()+50.0;
	double hoped_amount= m.getPennies();
	if(hoped_amount > overdraw_amount){ 
		//If the user want to draw more than amount of money in his account $50,
		//they can only get a restricted amount. And their account will in debt $50
		Money tmp(overdraw_amount);
		balance.subtract(tmp);

		return tmp;
	}else {
		Money tmp(hoped_amount);
		balance.subtract(hoped_amount);
		return tmp;
	}	
}
const Money Account::withdraw(double amount){
	Money m(amount);
	if (m.isNegative()==true){//print error
		cout<<"Withdraw money should not be negative"<<endl;
		return Money();
	}
	double overdraw_amount=balance.getPennies()+50.0;
	double hoped_amount= m.getPennies();
	if(hoped_amount > overdraw_amount){ 
		//If the user want to draw more than amount of money in his account $50,
		//they can only get a restricted amount. And their account will in debt $50
		Money tmp(overdraw_amount);
		balance.subtract(tmp);

		return tmp;
	}else {
		Money tmp(hoped_amount);
		balance.subtract(hoped_amount);
		return tmp;
	}	
}

void Account::accrue(){
	double amount= (*this).balance.getPennies();
	double interest= rate*amount;
	Money minterest(interest);
	balance.add(minterest);
}

void Account::print()const{
	balance.print();
}

void Account::transferTo(Account &dest, const Money &amount){
	const Money mwithdraw=(*this).withdraw(amount);
	dest.deposit(mwithdraw);
}

// Implement Non-Member Function Here
const Account createAccount(){
	string acc_name;
	double acc_rate;
	double acc_money;
        string acc_money_str;
	cout<<"Let's set up your account"<<endl;
	cout<<"First, what's the name of the account? ";
	getline(cin,acc_name);

	cout<<"What is the interest rate of your " <<acc_name<<" account?"<<endl;
	cin>>acc_rate;
	cout<<"Finally, what is the starting balance of your "<<acc_name <<" account?"<<endl;
        cin >> acc_money_str;
        if(acc_money_str[0]=='$'){
            acc_money=str2double( acc_money_str.substr(1,acc_money_str.size()) );
        }else
            acc_money=str2double(acc_money_str);
        //Make assumption that user's input money will be valid
        
        
	return Account(acc_name,acc_rate,acc_money);
}

double str2double(const string & istr ){
    return stod(istr);
}

// Test Functions; *** DO NOT ALTER ***


bool moneyIsNegative(bool expected)
{
	if (expected == true) {
		Money money1(-5, 55);
		Money money2(5, -55);
		Money money3(-5);
		Money money4(-5.55);
		return ( ( money1.isNegative() && 
					money2.isNegative() && 
					money3.isNegative() && 
					money4.isNegative() ) == expected );
	} else {
		Money money1(5, 55);
		Money money2(5);
		Money money3(5.55);
		Money money4;
		return ( !( !(money1.isNegative()) && 
					!(money2.isNegative()) && 
					!(money3.isNegative()) &&
					!(money4.isNegative()) ) == expected );
	}
}

void moneyPrint(double arg)
{
	Money money(arg);
	money.print();
}

bool moneyAdd()
{
	Money left(4, 64), right(5, 36);
	left.add(right);
	
	return left.isEqual(10);
}

bool moneySubtractPos()
{
	Money money(20);
	money.subtract(10.11);
	
	return money.isEqual(9.89);
}

bool moneySubtractNeg()
{
	Money money(20);
	money.subtract(30.11);
	
	return money.isEqual(-10.11);
}

bool acctGetName()
{
	Account account;

	return (account.getName() == "Savings");
}

bool acctGetRate()
{
	Account account("Savings", 0.01, Money(5, 0));

	return (account.getRate() == 0.01);
}

void acctPrint(double arg)
{
	Account account("Savings", 0.015, arg);
	account.print();
}

bool acctGetBalance()
{
	Money money(50);
	Account account("Savings", 0.01, money);
	Money bal = account.getBalance();

	return (bal.isEqual(money));
}

bool acctSetName()
{
	std::string name = "ROTH IRA";
	Account account("Savings", 0.01, 5);

	account.setName(name);
	return (name == account.getName());
}

bool acctDep01()
{
	Money money(5.63);
	Account account;

	account.deposit(money);

	return ((account.getBalance()).isEqual(money));
}

bool acctDep02()
{
	Account account;

	account.deposit(5, 63);

	return ((account.getBalance()).isEqual(5.63));
}

bool acctDep03()
{
	Account account;

	account.deposit(20);

	return ((account.getBalance()).isEqual(20));
}

bool acctDep04()
{
	Account account;

	account.deposit(5.63);

	return ((account.getBalance()).isEqual(5.63));
}


void acctBadDep()
{
	Account account;
	account.deposit(-50);
}

bool acctWith01()
{
	Money money(25.44);
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(money);

	return (w.isEqual(money) && (account.getBalance()).isEqual(24.56));
}

bool acctWith02()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(25, 44);

	return (w.isEqual(25.44) && (account.getBalance()).isEqual(24.56));
}

bool acctWith03()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(24);

	return (w.isEqual(24) && (account.getBalance()).isEqual(26));
}

bool acctWith04()
{
	Account account("Savings", 0.015, 50);

	Money w = account.withdraw(25.44);

	return (w.isEqual(25.44) && (account.getBalance()).isEqual(24.56));
}

bool acctWithPart01()
{
	Account account("Checking", 0.015, 54.33);

	Money w = account.withdraw(60);

	return w.isEqual(60) && (account.getBalance()).isEqual(-5.67);
}

bool acctWithPart02()
{
	Account account("Checking", 0.015, 54.33);

	Money w = account.withdraw(300);

	return w.isEqual(104.33) && (account.getBalance()).isEqual(-50);
}

void acctBadWith()
{
	Account account;

	account.withdraw(-10);
}

bool acctAccrue()
{
	Account account("Roth", 0.07, 1000);
	
	account.accrue();

	return (account.getBalance()).isEqual(1070);
}

bool acctTransfer()
{
	Account savings;
	Account checking("Checking", 0.015, 2500);

	checking.transferTo(savings, 500);

	return (savings.getBalance()).isEqual(500) && (checking.getBalance()).isEqual(2000);
}
