#ifndef HOTDOG_HPP
#define HOTDOG_HPP

#include "Money.hpp"
#include <vector>



namespace MyAwesomeBusiness{
    class HotdogStand{
        private:
            Money revenue;
            Money price;
            int sold;
            static int total_sold;
            static int total_stands;
            static Money total_revenue;

        public:
            //Constructors
            HotdogStand():revenue(),price(3.5),sold(0) { HotdogStand::total_stands+=1;}
            HotdogStand(double iprice): revenue(), price(iprice), sold(0) {HotdogStand::total_stands+=1;}
            
            
            //Member functions
            const Money getCash() const;
            
            const Money getPrice() const;
            
            int getDogsSold() const;
            
            const Money getStandRevenue() const;
            
            void setPrice(double iprice);
            
            void sellHotdog();
            
            static int getNumStands();
            static int getTotalHotdogsSold() ;
            static const Money getTotalRevenue() ;
    };
    //Nonmember function
    void printRundown(const std::vector<HotdogStand> &franchises);
}
#endif
