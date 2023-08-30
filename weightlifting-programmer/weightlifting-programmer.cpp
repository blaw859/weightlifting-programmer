// weightlifting-programmer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include "user.h"

nlohmann::json toJson(const User & user) {
	nlohmann::json j;
	j["name"] = user.GetUsername();
	j["age"] = user.GetAge();
	j["weight"] = user.GetWeight();
	j["height"] = user.GetHeight();
	return j;
}

int main()
{
	User lifter_a("jimmy_lifter", 24, 100.3, 182);
	nlohmann::json lifter_json = toJson(lifter_a);
	std::cout << lifter_json.dump() << std::endl;
}

