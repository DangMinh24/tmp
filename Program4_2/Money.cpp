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
	  if (dollars<=0 && cents<=0) 
	    return true;
	  else 
	    return false;
	}

	Money Money::operator-()const {
		Money result(-(*this).dollars , -(*this).cents);
		return result;
	}
	
	Money& Money::operator++(){	//prefix increment
		(*this).dollars++;
		return *this;
	} 

	Money Money::operator++(int){ //postfix increment
		Money prev((*this).dollars,(*this).cents);
		++(*this); 
		return prev;
	}

	Money& Money::operator--(){ //prefix decrement
		(*this).dollars--;
		return *this;
	}

	Money Money::operator--(int){ //postfix decrement
		Money prev((*this).dollars,(*this).cents);
		--(*this);
		return prev;
	}


	//Friend functions
	Money operator+(const Money& lhs,const Money& rhs){
		int SumPennies= lhs.getPennies()+rhs.getPennies();
		return Money(SumPennies/100, SumPennies%100);
	}

	Money operator*(const Money& lhs,int ivalue){
		int MulPennies=lhs.getPennies()*ivalue;
		return Money(MulPennies/100, MulPennies%100);
	}
	Money operator*(int ivalue, const Money& rhs){
		Money m=rhs*ivalue;
		return m;		
	}

	Money operator*(const Money& lhs, double dvalue){
		//For cases where cents more than 2 digits:
		//Ex: Money m=2.6 , double d=5.99 ->m*d =15.574
		//I truncate to take only 15.57 part as a result
		int MulPennies=static_cast<int>(trunc(lhs.getPennies()*dvalue));
		return Money(MulPennies/100,MulPennies%100);
	}
	Money operator*(double dvalue,const Money&rhs){
		Money m=rhs*dvalue;
		return m;
	}


	bool operator<(const Money& lhs, const Money& rhs){
		if(lhs.getPennies()<rhs.getPennies())
			return true;
		else
			return false;
	}

	//Make use the operator< above.
    bool operator<=(const Money& lhs, const Money& rhs){
    	if( !(rhs<lhs))
    		return true;
    	else 
    		return false;
    }
    bool operator>(const Money& lhs, const Money& rhs){
    	if (rhs<lhs)			
    		return true;
    	else
    		return false;
    }
    bool operator>=(const Money& lhs, const Money& rhs){
    	if( !(lhs<rhs))
    		return true;
    	else
    		return false;
    }
    bool operator==(const Money& lhs, const Money& rhs){
    	if ( !(lhs < rhs) && !(rhs<lhs) )
    		return true;
    	else
    		return false;
    }
    bool operator!=(const Money& lhs, const Money& rhs){
    	if (!(lhs==rhs))
    		return true;
    	else
    		return false;
    }

    std::istream& operator>>(std::istream& is, Money& iMoney){
    	std::string input_str;
    	std::string::size_type sz; // Correct way to conver from string to double
    	
    	is>>input_str;
    	if(input_str[0]=='$'){ //Case where input is $X.XX
    		double input_double=std::stod(input_str.substr(1),&sz);    		
    		iMoney.dollars= static_cast<int> (input_double);
		    iMoney.cents= static_cast<int>(round((input_double-iMoney.dollars)*100));
    	} else { //Case where input is X.XX
    		double input_double=std::stod(input_str,&sz);    		
    		iMoney.dollars= static_cast<int> (input_double);
		    iMoney.cents= static_cast<int>(round((input_double-iMoney.dollars)*100));
    	}
    	return is;
    }

    std::ostream& operator<<(std::ostream& os, const Money& oMoney){
    	//Combine outcome into a single string for the setw later
    	if (oMoney.isNegative()==true){ //Negative case
    		std::string single_output;
    		single_output+="($";
    		single_output+=std::to_string(-oMoney.dollars);
    		single_output+=".";
    		if (std::abs(oMoney.cents)<10){		//Deal with the case when |cents| < 10 -> make it into 0X
    			single_output+="0";
    			single_output+=std::to_string(-oMoney.cents);
    		}else
    			single_output+=std::to_string(-oMoney.cents);
    		single_output+=")";
    		os<<single_output;
    	}
    	else{							//Positive case
    		std::string single_output;
    		single_output+="$";
    		single_output+=std::to_string(oMoney.dollars);
    		single_output+=".";
    		if (std::abs(oMoney.cents)<10){
    			single_output+="0";
    			single_output+=std::to_string(oMoney.cents);
    		}
    		else
    			single_output+=std::to_string(oMoney.cents);
    		single_output+="";
    		os<<single_output;
    	}
    	return os;
    }

    //Non-member, Non-friend function make use of existed functions
    Money operator-(const Money& lhs, const Money& rhs){
    	Money iMoney;
    	iMoney=lhs+(-rhs);	//make use operator+ and unary operator- 
    	return iMoney;
    }
}