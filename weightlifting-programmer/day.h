#pragma once
#include <vector>
#include <memory>
#include "exercise_session.h"

class Day {
private:
	std::vector<std::unique_ptr<ExerciseSession>> sessions_;

public:
	Day() = default;

	Day(std::unique_ptr<ExerciseSession> session) {
		sessions_.push_back(std::move(session));
	}

	Day(std::vector<std::unique_ptr<ExerciseSession>> sessions) : sessions_(std::move(sessions)) {}

	std::vector<ExerciseSession*> GetSessions() const {
		std::vector<ExerciseSession*> result;
		for (const auto& session_ptr : sessions_) {
			result.push_back(session_ptr.get());
		}
		return result;
	}

	void SetSessions(std::vector<std::unique_ptr<ExerciseSession>> sessions) {
		sessions_ = std::move(sessions);
	}

	void AddSession(std::unique_ptr<ExerciseSession> session) {
		sessions_.push_back(std::move(session));
	}
};
