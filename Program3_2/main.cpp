/* Filename: main.cpp
 * Name: Dang Tran
 * ID: S856F975
 * Assignment: 3
 *
 */

#include <iostream>
#include <random>
#include "HotdogStand.hpp"
#include "Money.hpp"
#include <string>

namespace MAB= MyAwesomeBusiness; // use alias for namespace
int main() {

	std::random_device rd;
	std::mt19937 generator(rd());
	std::uniform_int_distribution<int> RegUniDist(20,60);
	std::uniform_int_distribution<int> FanUniDist(1,30);

	
	int numbStands;
	int numbFancyStands;
	std::string FancyPriceStr;	//Using string input to get "$" symbol in istream
	double FancyPrice;
	std::vector<MAB::HotdogStand> V;
	
	std::cout<<"Welcome!"<<std::endl;
	std::cout<<"How many hotdog stands do you own? ";
	std::cin>>numbStands;
	std::cout<<"How many of those sell fancy hotdog? ";
	std::cin>>numbFancyStands;
	std::cout<<"How much does a fancy hotdog cost? ";
	std::cin>>FancyPriceStr;

	//Assume that string will in the correct format
	//Correct way to use stod
	//http://www.cplusplus.com/reference/string/stod/
	std::string::size_type str_size;	
	if(FancyPriceStr[0]=='$'){
		FancyPrice=std::stod(FancyPriceStr.substr(1),&str_size);
	}else
		FancyPrice=std::stod(FancyPriceStr,&str_size);
	
	for(int i=0;i<numbStands-numbFancyStands;i++){
		V.emplace_back();
		int rand_sold=RegUniDist(generator);
		for(int j=0;j<rand_sold;j++){
			V.back().sellHotdog();
		}
	}
	for(int i=0;i<numbFancyStands;i++){
		V.emplace_back(FancyPrice);
		int rand_sold=FanUniDist(generator);
		for(int j=0;j<rand_sold;j++){
			V.back().sellHotdog();
		}
	}

	MAB::printRundown(V);


	
}

