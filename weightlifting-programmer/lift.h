#pragma once
#include <string>
#include <set>
#include <map>
#include <memory>
#include <nlohmann/json.hpp>
#include "exercise_session.h"

class Lift {
private:
	std::string name_;
	std::string description_;
	std::weak_ptr<Lift> base_lift_; // the lift we derive the % from i.e. 75% Hang Clean would be at 75% of the Clean

public:
	Lift(const std::string& name, const std::string& desc, const std::weak_ptr<Lift>& b_lift)
		: name_(name), description_(desc), base_lift_(b_lift) {}

	Lift(const std::string& name, const std::string& desc) 
		: name_(name), description_(desc) {}

	Lift() : name_(""), description_("") {}

	std::string GetName() const;
	std::string GetDescription() const;
	std::shared_ptr<Lift> GetBaseLift() const;

	void SetName(const std::string& name);
	void SetDescription(const std::string& desc);
	void SetBaseLift(const std::shared_ptr<Lift>& b_lift);

	friend void to_json(nlohmann::json& j, const Lift& lift);
	friend void from_json(nlohmann::json& j, Lift& lift);
};
