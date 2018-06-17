#include "HotdogStand.hpp"

namespace MyAwesomeBusiness{
	//Static initialization
	int HotdogStand::total_sold=0;
	int HotdogStand::total_stands=0;
	Money HotdogStand::total_revenue;	//Use default constructor


	//Member functions
	const Money HotdogStand::getCash() const{
		return revenue;
	}

	const Money  HotdogStand::getPrice() const{
		return price;
	}

	int HotdogStand::getDogsSold() const{
		return sold;
	}

	const Money HotdogStand::getStandRevenue()const{
		double price_value=static_cast<double>(price.getPennies()) * sold /100.0;
		return Money(price_value);	
	}

	void HotdogStand::setPrice(double iprice){
		price=iprice;
	}

	void HotdogStand::sellHotdog(){
		revenue.add(price);
		sold+=1;
		
		HotdogStand::total_sold+=1;
		HotdogStand::total_revenue.add(price);
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
	void printRundown(const std::vector<HotdogStand> &franchises){

		std::cout<<std::setw(10)<<std::left<<"Stand"<<std::setw(10)<<std::left<<"Sales"<<std::setw(10)<<std::left<<"Price"<<std::setw(10)<<std::left<<"Revenue"<<std::endl;
		std::cout<<std::setw(10)<<std::left<<"====="<<std::setw(10)<<std::left<<"====="<<std::setw(10)<<std::left<<"====="<<std::setw(10)<<std::left<<"======="<<std::endl;
		int numbStands=0;
		for(auto ip=franchises.begin();ip!=franchises.end();ip++){
			std::cout<<std::setw(5)<<std::right<<++numbStands;
			std::cout<<std::setw(10)<<std::right<<(*ip).getDogsSold();
			std::cout<<std::setw(6)<<std::right;
			(*ip).getPrice().print();
			std::cout<<std::setw(6)<<std::right;
			(*ip).getStandRevenue().print();
			std::cout<<std::endl;

		}
		std::cout<<std::endl;


		std::cout<<"TOTALS";
		std::cout<<std::setw(9)<<std::right<<franchises.back().getTotalHotdogsSold();
		std::cout<<std::setw(16)<<std::right;
		franchises.back().getTotalRevenue().print();
		std::cout<<std::endl;
		std::cout<<"# of Stands: "<<numbStands<<std::endl;
	}
}
