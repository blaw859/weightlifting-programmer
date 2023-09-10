#include "day.h"
#include "exercise_session.h"
#include "json_conversion.h"

Day::Day() = default;

Day::Day(std::unique_ptr<ExerciseSession> session)
{
   sessions_.push_back(std::move(session));
}

Day::Day(std::vector<std::unique_ptr<ExerciseSession>> sessions) : sessions_(std::move(sessions)) {}

const std::vector<std::unique_ptr<ExerciseSession>>& Day::GetSessions() const {
   return sessions_;
}

void Day::SetSessions(std::vector<std::unique_ptr<ExerciseSession>> sessions)
{
   sessions_ = std::move(sessions);
}

void Day::AddSession(std::unique_ptr<ExerciseSession> session)
{
   sessions_.push_back(std::move(session));
}

void to_json(nlohmann::json& j, const Day& day) {
   j = nlohmann::json{
       {"sessions", day.GetSessions()}
   };
}

void from_json(const nlohmann::json& j, Day day)
{
}

std::ostream& operator<<(std::ostream& out, const Day& lift)
{
   for (int i = 0; i < lift.GetSessions().size(); i++) {
      out << "Session " << i + 1 << std::endl;
      out << lift.GetSessions()[i];
   }
   return out;
}

void from_json(nlohmann::json& j, Day& day) {
   //if (j.contains("sessions") && j["sessions"].is_array()) {
   //   std::vector<std::unique_ptr<ExerciseSession>> sessions;
   //   for (nlohmann::json& session_json : j["sessions"]) {
   //      ExerciseSession session; 
   //      from_json(session_json, session);
   //      sessions.push_back(session);
   //   }
   //   day.SetSessions(std::move(sessions));
   //}
}