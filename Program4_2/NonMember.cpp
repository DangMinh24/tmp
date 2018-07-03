#include "NonMember.hpp"

namespace MyAwesomeBusiness{
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