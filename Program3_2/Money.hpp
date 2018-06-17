#ifndef MONEY_HPP
#define MONEY_HPP

#include <cmath>
#include <iostream>
#include <iomanip>

namespace MyAwesomeBusiness{
    class Money{
      public:
        //Constructors
        Money():dollars(0),cents(0) {}
        Money(int idollars, int icents): dollars(idollars), cents(icents) {}
        Money(int idollars): dollars(idollars), cents(0) {}
        Money(double amount);

        //Member functions
        
        int getPennies() const; 
        
        bool isNegative() const;
        bool isEqual(const Money &m) const;

        void add(const Money &m);
        void subtract(const Money &m);
        
        void print() const;
      
        
      private:
        int dollars;
        int cents;
    };

}
#endif