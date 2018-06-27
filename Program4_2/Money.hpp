#ifndef MONEY_HPP
#define MONEY_HPP

#include <cmath>
#include <iostream>
#include <iomanip>
#include <string>
#include <string.h>

namespace MyAwesomeBusiness{
    class Money{
      public:
        //Constructors
        Money():dollars(0),cents(0) {}
        Money(int idollars, int icents):Money() {
            if ((idollars>0 && icents>0) || (idollars<0 && icents<0) || (idollars==0 || icents==0)) {
                dollars=idollars;
                cents=icents;
            }
        }
        Money(int idollars): dollars(idollars), cents(0) {}
        Money(double amount);

        //Member functions
        
        int getPennies() const;         
        bool isNegative() const;
        
        Money operator-() const ;
        Money&  operator++(); //prefix increment ++Money
        Money operator++(int); //postfix increment Money++
        Money&  operator--(); //prefix decrement --Money
        Money operator--(int); //postfix decrement Money-- 
      
        friend Money operator+(const Money& lhs,const Money& rhs);
        friend Money operator*(const Money& lhs,int ivalue);
        friend Money operator*(int ivalue, const Money& rhs);
        friend Money operator*(const Money& lhs,double dvalue);
        friend Money operator*(double dvalue,const Money&rhs);

        friend bool operator<(const Money& lhs, const Money& rhs);
        friend bool operator<=(const Money& lhs, const Money& rhs);
        friend bool operator>(const Money& lhs, const Money& rhs);
        friend bool operator>=(const Money& lhs, const Money& rhs);
        friend bool operator==(const Money& lhs, const Money& rhs);
        friend bool operator!=(const Money& lhs, const Money& rhs);

        friend std::istream& operator>>(std::istream& is,Money& iMoney);
        friend std::ostream& operator<<(std::ostream& os,const Money& oMoney);
          
      private:
        int dollars;
        int cents;
    };

    Money operator-(const Money& lhs, const Money& rhs);

}

#endif