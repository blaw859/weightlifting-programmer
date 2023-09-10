#include "exercise_session.h"
#include "json_conversion.h"

struct LiftInfo;
class ExerciseSession;

const std::vector<std::unique_ptr<LiftInfo>>& ExerciseSession::getLifts() const { return lifts_; }

void ExerciseSession::setLifts(std::vector<std::unique_ptr<LiftInfo>> lifts) {
	lifts_ = std::move(lifts);
}

void ExerciseSession::addLift(std::unique_ptr<LiftInfo> lift) {
   lifts_.push_back(std::move(lift));
}

void to_json(nlohmann::json& j, const LiftInfo& lift_info)
{
   j = nlohmann::json{
      {"lift_id", lift_info.lift->GetId()},
      {"lift", *lift_info.lift},
      {"sets", lift_info.number_of_sets},
      {"reps", lift_info.number_of_reps},
      {"intensity", lift_info.percent_intensity}
   };
}

void from_json(const nlohmann::json& j, LiftInfo& lift_info)
{
   lift_info.lift_id = j.at("lift_id").get<std::string>();
   lift_info.number_of_sets = j.at("sets").get<int>();
   lift_info.number_of_reps = j.at("reps").get<int>();
   lift_info.percent_intensity = j.at("intensity").get<double>();
}

std::ostream& operator<<(std::ostream& out, const LiftInfo& lift_info)
{
   out << lift_info.lift->GetName() << ": " << lift_info.number_of_reps << "x" << lift_info.number_of_sets << "@" << lift_info.percent_intensity;
   return out;
}

std::ostream& operator<<(std::ostream& out, const ExerciseSession& exercise_session)
{
   for (const auto& lift : exercise_session.getLifts()) {
      if (lift) {
         out << *lift << std::endl;
      }
   }
   return out;
}

void to_json(nlohmann::json& j, const ExerciseSession& session)
{
   j = nlohmann::json{
      {"lifts", session.lifts_}
   };
}
void from_json(nlohmann::json& j, ExerciseSession& session)
{
//       if (j.contains("lifts") && j["lifts"].is_array()) {
//        std::vector<std::unique_ptr<LiftInfo>> tempLifts;
//        for (const auto& lift_json : j["lifts"]) {
//            LiftInfo lift;
//            from_json(lift_json, lift);  // Deserializing each lift item.
//            tempLifts.push_back(lift);
//        }
//        session.setLifts(tempLifts);
//    } else {
//        // Handle error: either "lifts" key is missing or its value is not an array
//    }
}
