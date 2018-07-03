#include "HotdogStand.hpp"

namespace MyAwesomeBusiness{
	//Static initializations
	int HotdogStand::total_sold=0;
	int HotdogStand::total_stands=0;
	Money HotdogStand::total_revenue;

	//Member functions
	const Money HotdogStand::getCash() const{
		return start;
	}

	const Money  HotdogStand::getPrice() const{
		return price;
	}

	int HotdogStand::getDailyDogsSold() const{
		return sold;
	}

	void HotdogStand::replenishSupplies(){
		double need_refill=static_cast<double>(max_storage-supply);
		Money need_refill_cost=need_refill*wholesale_cost;
		start=start-need_refill_cost;
		supply=max_storage;
	}

	void HotdogStand::payWorker(){
		Money payment=hr_wage*hours;
		start=start-payment;
	}

	void HotdogStand::dailyReset(){
		HotdogStand::total_sold+=sold;
		HotdogStand::total_revenue=HotdogStand::total_revenue+(*this).getStandRevenue();
		sold=0;
		
	}

	const Money HotdogStand::getStandRevenue()const{
		return price*sold;	
	}

	void HotdogStand::setPrice(double iprice){
		price=iprice;
	}

	void HotdogStand::sellHotdog(){
		if(supply>0){	//In case out of hotdogs
			start=start+price;
			this->sold= this->sold+1;
			supply=supply-1;
		}
	}

	int HotdogStand::getNumStands(){
		return HotdogStand::total_stands;
	}

	int HotdogStand::getTotalHotdogsSold(){
		return HotdogStand::total_sold;
	} 

	const Money HotdogStand::getTotalRevenue(){
		return HotdogStand::total_revenue;
	}


	
}
