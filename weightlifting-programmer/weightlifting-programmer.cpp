// weightlifting-programmer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/program_options.hpp>
#include <nlohmann/json.hpp>
#include "user.h"
#include "day.h"
#include "programme.h"
#include "exercise_session.h"
#include "lift.h"
#include "json_conversion.h"

nlohmann::json toJson(const User & user) {
	nlohmann::json j;
	j["name"] = user.GetUsername();
	j["age"] = user.GetAge();
	j["weight"] = user.GetWeight();
	j["height"] = user.GetHeight();
	return j;
}

// TODO: this should definitely move somehwere else

int main()
{
	auto clean_ptr = std::make_shared<Lift>("clean", "clean");
	auto jerk_ptr = std::make_shared<Lift>("jerk", "jerk");
	auto ohp_ptr = std::make_shared<Lift>("overhead press", "OHP or strict press", jerk_ptr);
	auto clean_pull_ptr = std::make_shared<Lift>("clean pull", "clean pull from the knee", clean_ptr);

	LiftInfo clean_info = { clean_ptr->GetId(), clean_ptr, 3, 1, 0.95 };
	LiftInfo jerk_info = { jerk_ptr->GetId(), jerk_ptr, 3, 1, 0.95 };

	auto clean_info_ptr = std::make_unique<LiftInfo>(clean_info);
	auto jerk_info_ptr = std::make_unique<LiftInfo>(jerk_info);

	auto sesh = std::make_unique<ExerciseSession>();
	sesh->addLift(std::move(clean_info_ptr));
	sesh->addLift(std::move(jerk_info_ptr));

	auto day = std::make_unique<Day>();
	day->AddSession(std::move(sesh));


	nlohmann::json sesh_json;
	to_json(sesh_json, day);

	std::cout << clean_info << std::endl;

	//std::cout << sesh_json.dump() << std::endl;


	//auto all_lifts = { clean_ptr, jerk_ptr, ohp_ptr, clean_pull_ptr };
	//nlohmann::json j_lift_array = nlohmann::json::array();

	//for (const auto& lift_ptr : all_lifts) {
	//	nlohmann::json j_lift;
	//	to_json(j_lift, *lift_ptr);
	//	j_lift_array.push_back(j_lift);
	//}

	//std::cout << j_lift_array.dump() << std::endl;

}

