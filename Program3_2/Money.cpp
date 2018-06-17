#include "Money.hpp"


namespace MyAwesomeBusiness{
	Money::Money(double amount){
	    dollars= static_cast<int> (amount);
	    cents= static_cast<int>(round((amount-dollars)*100));
	}

	int Money::getPennies() const{
		return dollars*100 + cents;
	}
	
	bool Money::isNegative() const{
	  if (dollars<0 && cents<0) 
	    return true;
	  else 
	    return false;
	}

	bool Money::isEqual(const Money &m) const{
	  if(this->getPennies()== m.getPennies() )
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

	void Money::print() const{
	  double amount= static_cast<double>((*this).getPennies())/100.0;
	  if ((*this).isNegative()==true){
	    std::cout << std::fixed;
	    std::cout << std::setprecision(2);
	    std::cout <<"($"<<amount<<")"; 
	  }
	  else {
	    std::cout << std::fixed;
	    std::cout << std::setprecision(2);
	    std::cout <<"$"<<amount;
	  }
	} 

	
}