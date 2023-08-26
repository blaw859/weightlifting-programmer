#pragma once
#include <vector>
#include <memory>
#include "exercise_session.h"
#include "day.h"

class Programme {
private:
	size_t length; // length of programme in days
	std::vector<std::unique_ptr<ExerciseSession>> sessions_;

public:
};
