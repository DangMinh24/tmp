#ifndef HOTDOG_HPP
#define HOTDOG_HPP

#include "Money.hpp"
#include <vector>
#include <random>


namespace MyAwesomeBusiness{
    class HotdogStand{
        private:    
        //Organize these variables in the correct order, for inline initializations
            const int hours=8;
            Money price;
            int sold;
            int cum_sold;
            Money hr_wage;
            int supply;
            int max_storage;            
            Money wholesale_cost;

            Money start;

            static int total_sold;
            static int total_stands;
            static Money total_revenue;

        public:
            //Constructors
            HotdogStand():price(3.5),sold(0),cum_sold(0),\
                        hr_wage(7.25),supply(60),max_storage(60),\
                        wholesale_cost(0.15),\
                        start(-wholesale_cost*max_storage)\
                        { HotdogStand::total_stands+=1;}
            HotdogStand(Money iprice):price(iprice),sold(0),\
                                    cum_sold(0),hr_wage((price>3.5)? 8 :7.25),\
                                    supply((price>3.5)? 30 : 60),\
                                    max_storage(supply),\
                                    wholesale_cost((price>3.5)? 0.5 : 0.15),\
                                    start(-wholesale_cost*max_storage)\
                                    {HotdogStand::total_stands+=1;}
            HotdogStand(double iprice): HotdogStand(Money(iprice)) {}
            
            
            //Member functions
            const Money getCash() const;
            const Money getPrice() const;
            int getDailyDogsSold() const;
            void replenishSupplies();

            void payWorker();

            void dailyReset();

            const Money getStandRevenue() const;
            
            void setPrice(double iprice);
            
            void sellHotdog();
            
            static int getNumStands();
            static int getTotalHotdogsSold() ;
            static const Money getTotalRevenue() ;
        
    };
    //Nonmember function
    void runSimulation(std::vector<HotdogStand>& franchises, int days);
    void printRundown(const std::vector<HotdogStand> &franchises);
}
#endif
