#pragma once
#include <vector>
#include <memory>
#include <nlohmann/json.hpp>
#include "exercise_session.h"
#include "day.h"

class Programme {
private:
	size_t length_; // length of programme in days
	std::vector<Day> Days;

public:
	Programme(size_t len) : length_(len) {}

	Day& operator[](size_t index);
	const Day& operator[](size_t index) const;
   friend std::ostream& operator<<(std::ostream& out, const Programme& lift);
	






};
