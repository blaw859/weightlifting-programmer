#pragma once
#include <string>

class User {
private:
	std::string username_;
	int age_;
	double height_;
	double weight_;

public:
	static constexpr size_t MIN_USERNAME_LENGTH = 3;
	static constexpr size_t MAX_USERNAME_LENGTH = 32;
	static constexpr int MIN_AGE = 0;
	static constexpr int MAX_AGE = 120;
	static constexpr double MAX_WEIGHT = 635;
	static constexpr double MIN_WEIGHT = 2;
	static constexpr double MAX_HEIGHT = 272;
	static constexpr double MIN_HEIGHT = 54.6;

	// constructor
	User(const std::string uname, int age, double weight, double height);

	// getters
	std::string GetUsername() const;
	int GetAge() const;
	double GetWeight() const;
	double GetHeight() const;

	// setters
	void SetUsername(const std::string& uname);
	void SetAge(int a);
	void SetWeight(double w); //TODO: different measurements
	void SetHeight(double h); //TODO: different measurements
};
