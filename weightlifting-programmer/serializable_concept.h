#pragma once
#include <nlohmann/json.hpp>
template<typename T>
concept Serializable = requires(T a, nlohmann::json j) {
	{ to_json(j, a) };
	{ from_json(j, a) } -> std::convertible_to<T>;
};
