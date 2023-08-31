// weightlifting-programmer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include "user.h"
#include "lift.h"

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

	auto clean_ptr = std::make_shared<Lift>("clean", "clean");
	auto jerk_ptr = std::make_shared<Lift>("jerk", "jerk");
	auto ohp_ptr = std::make_shared<Lift>("overhead press", "OHP or strict press", jerk_ptr);
	auto clean_pull_ptr = std::make_shared<Lift>("clean pull", "clean pull from the knee", clean_ptr);

	auto all_lifts = { clean_ptr, jerk_ptr, ohp_ptr, clean_pull_ptr };
	nlohmann::json j_lift_array = nlohmann::json::array();

	for (const auto& lift_ptr : all_lifts) {
		nlohmann::json j_lift;
		to_json(j_lift, *lift_ptr);
		j_lift_array.push_back(j_lift);
	}

	std::cout << j_lift_array.dump() << std::endl;

}

