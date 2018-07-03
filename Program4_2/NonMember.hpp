#ifndef NONMEMBER_HPP
#define NONMEMBER_HPP
#include "HotdogStand.hpp"

namespace MyAwesomeBusiness{
	void runSimulation(std::vector<HotdogStand>& franchises, int days);

	void printRundown(const std::vector<HotdogStand> &franchises);
}

#endif