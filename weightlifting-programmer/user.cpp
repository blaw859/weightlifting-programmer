#include "user.h"
#include <stdexcept>
#include <algorithm>


User::User(const std::string uname, int age, double weight, double height) {
	SetUsername(uname);
	SetAge(age);
	SetWeight(weight);
	SetHeight(height);
}

std::string User::GetUsername() const
{
	return username_;
}

int User::GetAge() const
{
	return age_;
}

double User::GetWeight() const
{
	return weight_;
}

double User::GetHeight() const
{
	return height_;
}

void User::SetUsername(const std::string& uname)
{
	if (uname.empty()) {
		throw std::invalid_argument("Username cannot be empty.");
	}

	if (uname.length() < MIN_USERNAME_LENGTH || uname.length() > MAX_USERNAME_LENGTH) {
		throw std::invalid_argument("Username must be between " + std::to_string(MIN_USERNAME_LENGTH) + " and " + std::to_string(MAX_USERNAME_LENGTH) + " characters.");
	}

	if (!std::all_of(uname.begin(), uname.end(), [](char c) { return std::isalnum(c) || c == '_'; })) {
		throw std::invalid_argument("Username can only contain alphanumeric or underscore");
	}

	username_ = uname;
}

void User::SetAge(int a)
{
	if (a < MIN_AGE || a > MAX_AGE) {
		throw std::invalid_argument("Ages must be between " + std::to_string(MIN_AGE) + " and " + std::to_string(MAX_AGE));
	}

	age_ = a;
}

void User::SetWeight(double w)
{
	if (w < MIN_WEIGHT || w > MAX_WEIGHT) {
		throw std::invalid_argument("Weights must be between " + std::to_string(MIN_WEIGHT) + " and " + std::to_string(MAX_WEIGHT));
	}

	weight_ = w;
}

void User::SetHeight(double h)
{
	if (h < MIN_HEIGHT || h > MAX_HEIGHT) {
		throw std::invalid_argument("Heights must be between " + std::to_string(MIN_HEIGHT) + " and " + std::to_string(MAX_HEIGHT));
	}

	height_ = h;
}
