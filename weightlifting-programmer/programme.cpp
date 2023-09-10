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

std::ostream& operator<<(std::ostream& out, const Programme& lift)
{
   // TODO: insert return statement here
   return out;
}
