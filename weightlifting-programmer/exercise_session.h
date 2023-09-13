#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <format>
#include <nlohmann/json.hpp>
#include "lift.h"

struct LiftInfo {
	std::string lift_id;
	std::shared_ptr<Lift> lift;
	int number_of_sets;
	int number_of_reps;
	double percent_intensity;
};

void to_json(nlohmann::json& j, const LiftInfo& lift);
void from_json(nlohmann::json& j, LiftInfo& lift);
int make_info_string(const LiftInfo&, std::string* info_string);
std::ostream& operator<<(std::ostream& out, const LiftInfo& lift_info);

class ExerciseSession {
private:
	std::vector<std::unique_ptr<LiftInfo>> lifts_;
public:
	const std::vector<std::unique_ptr<LiftInfo>>& getLifts() const;
	void setLifts(std::vector<std::unique_ptr<LiftInfo>> lifts);
	void addLift(std::unique_ptr<LiftInfo> lift);
	friend std::ostream& operator<<(std::ostream& out, const ExerciseSession& lift_info);
	friend void to_json(nlohmann::json& j, const ExerciseSession& session);
	friend void from_json(nlohmann::json& j, ExerciseSession session);

};
