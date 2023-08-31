#include "lift.h"

std::string Lift::GetName() const
{
    return name_;
}

std::string Lift::GetDescription() const
{
    return description_;
}

std::shared_ptr<Lift> Lift::GetBaseLift() const
{
    return base_lift_.lock();
}

void Lift::SetName(const std::string& name)
{
    name_ = name;
}

void Lift::SetDescription(const std::string& desc)
{
    description_ = desc;
}

void Lift::SetBaseLift(const std::shared_ptr<Lift>& b_lift)
{
    base_lift_ = b_lift;
}

void to_json(nlohmann::json& j, const Lift& lift) {
    j = nlohmann::json{
        {"name", lift.name_},
        {"description", lift.description_}
    };
    if (auto base_lift_ptr = lift.base_lift_.lock()) {
        j["base_lift"] = base_lift_ptr->GetName();
    }
    else {
        j["base_lift"] = nullptr;
    }
}

void LoadLiftsFromJson(const nlohmann::json& json_data) {
    std::map<std::string, std::shared_ptr<Lift>> all_lifts;

    /* first pass, just get the name and description put it in the list of all lifts */
    for (const auto& lift_data : json_data) {
        auto lift = std::make_shared<Lift>();
        lift->SetName(lift_data.at("name").get<std::string>());
        lift->SetDescription(lift_data.at("description").get<std::string>());
        all_lifts[lift->GetName()] = lift;
    }

    /* second pass, extract the base lift name from the json and get it from the list of all_lifts */
    for (const auto& lift_data : json_data) {
        if (lift_data.contains("base_lift") && !lift_data["base_lift"].is_null()) {
            std::string base_lift_name = lift_data["base_lift"].get<std::string>();
            all_lifts[lift_data["name"].get<std::string>()]->SetBaseLift(all_lifts[base_lift_name]);
            // TODO: what if the lift doesn't exist
        }
    }
}
