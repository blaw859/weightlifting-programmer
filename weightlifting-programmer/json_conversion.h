#pragma once
#include <nlohmann/json.hpp>

template <typename T>
void to_json(nlohmann::json& j, const T* obj) {
	if (obj) {
		j = *obj;
	}
	else {
		j = nullptr;
	}
}

template <typename T>
void to_json(nlohmann::json& j, const std::shared_ptr<T>& obj) {
	if (obj) {
		j = *obj;
	}
	else {
		j = nullptr;
	}
}

template <typename T>
void to_json(nlohmann::json& j, const std::unique_ptr<T>& obj) {
	if (obj) {
		j = *obj;
	}
	else {
		j = nullptr;
	}
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::unique_ptr<T>& ptr) {
	if (ptr) {
		out << *ptr;
	}
	else {
		out << "Null pointer";
	}
	return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::shared_ptr<T>& ptr) {
	if (ptr) {
		out << *ptr;
	}
	else {
		out << "Null pointer";
	}
	return out;
}
