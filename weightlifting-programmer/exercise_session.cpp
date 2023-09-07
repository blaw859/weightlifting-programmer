#include "exercise_session.h"

void to_json(nlohmann::json& j, const LiftInfo& lift_info)
{
   nlohmann::json j = {
      {"lift_name", lift_info.lift_name},
      {"sets", lift_info.number_of_sets},
      {"reps", lift_info.number_of_reps},
      {"intensity", lift_info.percent_intensity}
   };
}

void from_json(nlohmann::json& j, LiftInfo& lift_info)
{
   lift_info.lift_name = j.at("lift_name");
   lift_info.number_of_sets = j.at("sets");
   lift_info.number_of_reps = j.at("reps");
   lift_info.percent_intensity = j.at("intensity");
}

void to_json(nlohmann::json& j, const ExerciseSession& session)
{
}

void from_json(nlohmann::json& j, ExerciseSession& session)
{
}
