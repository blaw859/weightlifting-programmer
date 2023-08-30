#pragma once
#include <vector>
#include <memory>
#include "exercise_session.h"

class Day {
private:
	std::vector<std::unique_ptr<ExerciseSession>> sessions_;

public:
	Day();
	Day(std::unique_ptr<ExerciseSession> session);
	Day(std::vector<std::unique_ptr<ExerciseSession>> sessions);

	std::vector<ExerciseSession*> GetSessions() const;
	void SetSessions(std::vector<std::unique_ptr<ExerciseSession>> sessions);
	void AddSession(std::unique_ptr<ExerciseSession> session);
};
