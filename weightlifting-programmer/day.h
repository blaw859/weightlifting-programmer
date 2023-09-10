#pragma once
#include <nlohmann/json.hpp>
#include <vector>
#include "exercise_session.h"
class Day {
private:
   std::vector<std::unique_ptr<ExerciseSession>> sessions_;

public:
   Day();
   Day(std::unique_ptr<ExerciseSession> session);
   Day(std::vector<std::unique_ptr<ExerciseSession>> sessions);
   const std::vector<std::unique_ptr<ExerciseSession>>& GetSessions() const;
   void SetSessions(std::vector<std::unique_ptr<ExerciseSession>> sessions);
   void AddSession(std::unique_ptr<ExerciseSession> session);
   friend void to_json(nlohmann::json& j, const Day& day);
   friend void from_json(const nlohmann::json& j, Day day);
   friend std::ostream& operator<<(std::ostream& out, const Day& lift);
};
