#include <vector>
#include <memory>
#include "exercise_session.h"
#include "day.h"

Day::Day() = default;

Day::Day(std::unique_ptr<ExerciseSession> session) {
	sessions_.push_back(std::move(session));
}

Day::Day(std::vector<std::unique_ptr<ExerciseSession>> sessions) : sessions_(std::move(sessions)) {}

std::vector<ExerciseSession*> Day::GetSessions() const {
	std::vector<ExerciseSession*> result;
	for (const auto& session_ptr : sessions_) {
		result.push_back(session_ptr.get());
	}
	return result;
}

void Day::SetSessions(std::vector<std::unique_ptr<ExerciseSession>> sessions) {
	sessions_ = std::move(sessions);
}

void Day::AddSession(std::unique_ptr<ExerciseSession> session) {
	sessions_.push_back(std::move(session));
}