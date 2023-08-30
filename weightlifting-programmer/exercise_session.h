#pragma once
#include<vector>
#include<string>

struct LiftInfo {
	std::string lift_name;
	int number_of_sets;
	int number_of_reps;
	double percent_intensity;
};

class ExerciseSession {
	/* this should probably contain: {lift, sets, reps, percent of base lift} */
private:
	std::vector<LiftInfo> lifts_;


};
