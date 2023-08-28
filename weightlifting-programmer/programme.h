#pragma once
#include <vector>
#include <memory>
#include "exercise_session.h"
#include "day.h"

class Programme {
private:
	size_t length_; // length of programme in days
	std::vector<std::unique_ptr<Day>> Days;

public:
	Programme(size_t len) : length_(len) {}





};
