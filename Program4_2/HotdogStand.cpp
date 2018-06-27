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

	//Nonmember function
	void runSimulation(std::vector<HotdogStand>& franchises, int days){
		std::random_device rd;
		std::mt19937 generator(rd());
		std::uniform_int_distribution<int> RegUniDist(20,61);	//inclusive
		std::uniform_int_distribution<int> FanUniDist(1,31);	//inclusive
		
		Money total_remain(0,0);	
		for(int d=0;d<days;d++){
			for(auto i=franchises.begin();i!=franchises.end();i++){
				if((*i).getPrice()<=3.5){
					int rand_sold=RegUniDist(generator);
					for(int j=0;j<rand_sold;j++){
						(*i).sellHotdog();
					}
				}
				else{
					int rand_sold=FanUniDist(generator);
					for(int j=0;j<rand_sold;j++){
						(*i).sellHotdog();
					}
				}
				(*i).payWorker();
				(*i).replenishSupplies();
				total_remain=total_remain+(*i).getCash();
			}

			printRundown(franchises);
			std::cout<<std::endl;
			for(auto i=franchises.begin();i!=franchises.end();i++){
				(*i).dailyReset();
			}
		}
		std::cout<<std::setw(5)<<std::right<<"TOTALS"<<\
				std::setw(9)<<std::right<<(franchises.begin())->getTotalHotdogsSold()<<\
				std::setw(20)<<std::setfill(' ')<<\
				(franchises.begin())->getTotalRevenue()<<\
				std::setw(15)<<total_remain<<std::endl;
		std::cout<<"Stands:\t"<<(franchises.begin())->getNumStands()<<std::endl;	
	}

	void printRundown(const std::vector<HotdogStand> &franchises){
		std::cout<<std::setw(5)<<std::right<<"Stand"<<\
				std::setw(10)<<std::right<<"Sales"<<\
				std::setw(10)<<std::right<<"Price"<<\
				std::setw(10)<<std::right<<"Revenue"<<\
				std::setw(15)<<std::right<<"Remaining Cash"<<std::endl;
		std::cout<<std::setw(5)<<std::right<<"====="<<\
				std::setw(10)<<std::right<<"====="<<\
				std::setw(10)<<std::right<<"====="<<\
				std::setw(10)<<std::right<<"======="<<\
				std::setw(15)<<std::right<<"=============="<<\
				std::endl;

		int iter=1;
		for(auto i= franchises.begin();i!=franchises.end();i++){
			std::cout<<std::setw(5)<<std::right<<iter++<<\
					std::setw(10)<<std::right<<(*i).getDailyDogsSold()<<\
					std::setw(10)<<std::right<<(*i).getPrice()<<\
					std::setw(10)<<std::right<<(*i).getStandRevenue()<<\
					std::setw(15)<<std::right<<(*i).getCash()<<std::endl;
		}
	}
}
