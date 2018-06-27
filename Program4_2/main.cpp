// /* Filename: main.cpp
//  * Name: Dang Tran
//  * ID: S856F975
//  * Assignment: 4
//  *
//  */

#include <iostream>
#include "Money.hpp"
#include "HotdogStand.hpp"
namespace MAB=MyAwesomeBusiness;
int main(){
	int numbStands;
	int numbFancyStands;
	std::string FancyPriceStr;	//Using string input to get "$" symbol in istream
	double FancyPrice;
	int days;
	std::vector<MAB::HotdogStand> V;

	std::cout<<"Welcome!"<<std::endl;
	std::cout<<"How many hotdog stands do you own? "<<std::endl;
	std::cin>>numbStands;
	do{
		std::cout<<"How many of those sell fancy hotdog? "<<std::endl;
		std::cin>>numbFancyStands;
	} while(numbFancyStands>numbStands);

	
	std::cout<<"How much does a fancy hotdog cost? "<<std::endl;
	std::cin>>FancyPriceStr;
	std::cout<<"How many days will you simulate? "<<std::endl;
	std::cin>>days;

	std::string::size_type str_size;	
	if(FancyPriceStr[0]=='$'){
		FancyPrice=std::stod(FancyPriceStr.substr(1),&str_size);
	}else
		FancyPrice=std::stod(FancyPriceStr,&str_size);
	
	for(int i=0;i<numbStands;i++){
		if(i<numbStands-numbFancyStands){
			V.emplace_back();
		}
		else{
			V.emplace_back(FancyPrice);
		}
	}
	MAB::runSimulation(V,days);
	
}