#pragma once
#include<vector>
#include<string>
#include <nlohmann/json.hpp>

struct LiftInfo {
	std::string lift_name;
	int number_of_sets;
	int number_of_reps;
	double percent_intensity;
};

void to_json(nlohmann::json& j, const LiftInfo& lift);
void from_json(nlohmann::json& j, LiftInfo& lift);

class ExerciseSession {
private:
	std::vector<LiftInfo> lifts_;
public:
	friend void to_json(nlohmann::json& j, const ExerciseSession& lift);
	friend void from_json(nlohmann::json& j, ExerciseSession& lift);
};
