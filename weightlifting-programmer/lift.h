#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>
#include <memory>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include <nlohmann/json.hpp>

struct LiftInfo;


class Lift {
private:
	boost::uuids::uuid id_;
	std::string name_;
	std::string description_;
	std::weak_ptr<Lift> base_lift_; // the lift we derive the % from i.e. 75% Hang Clean would be at 75% of the Clean

public:
	Lift(const std::string& name, const std::string& desc, const std::weak_ptr<Lift>& b_lift)
		: name_(name), description_(desc), base_lift_(b_lift) {
		id_ = boost::uuids::random_generator()();
	}

	Lift(const std::string& name, const std::string& desc) 
		: name_(name), description_(desc) {
		id_ = boost::uuids::random_generator()();
	}

	std::string GetId() const;
	std::string GetName() const;
	std::string GetDescription() const;
	std::shared_ptr<Lift> GetBaseLift() const;

	void SetName(const std::string& name);
	void SetDescription(const std::string& desc);
	void SetBaseLift(const std::shared_ptr<Lift>& b_lift);

	friend void to_json(nlohmann::json& j, const Lift& lift);
	friend void from_json(nlohmann::json& j, Lift& lift);
	friend std::ostream& operator<<(std::ostream& out, const Lift& lift);
};
