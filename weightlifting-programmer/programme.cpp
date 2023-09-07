#include "programme.h"

Day& Programme::operator[](size_t index) {
   return Days[index];
}

const Day& Programme::operator[](size_t index) const {
   return Days[index];
}

void to_json(nlohmann::json& j, const Programme& programme) {
   j = nlohmann::json{};
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
