#pragma once
#include "Header.h"
#include <fstream>
#include <json/json.h>
#include <json/value.h>
#include <string>
#include <vector>

std::vector<std::pair<std::string, int>> sorted_v;
Json::Value root;
Json::Value recent_files(Json::arrayValue);
Json::Value sorted_high(Json::arrayValue);
Json::Value month_score(Json::arrayValue);
int total = 0;

void json_generator(){
	//std::ifstream file("parse_data.json");
	//recent_files.append(count);
	for (const auto& outer_pair : scoremap) {
		recent_files.append(outer_pair.first);
		const std::unordered_map<std::string, int>& inner_map = outer_pair.second;
		for (const auto& inner_pair : inner_map) {
			if (inner_pair.first == "low") {
				root["scores"]["low"] = root["scores"]["low"].asInt() + inner_pair.second * 2;
				total = total + inner_pair.second * 2;
			}
			else if (inner_pair.first == "medium") {
				root["scores"]["medium"] = root["scores"]["medium"].asInt() + inner_pair.second * 3;
				total = total + inner_pair.second * 3;
			}
			else if (inner_pair.first == "high") {
				root["scores"]["high"] = root["scores"]["high"].asInt() + inner_pair.second * 5;
				total = total + inner_pair.second * 5;
				sorted_v.push_back(std::make_pair(outer_pair.first, inner_pair.second*5));
			}
		}
	}
	std::sort(sorted_v.begin(), sorted_v.end(), [](const std::pair <std::string, int> &a, const std::pair <std::string, int> &b) {
		return a.second > b.second;
	});
	for (auto pair : sorted_v) {
		Json::Value obj(Json::objectValue);
		obj[pair.first] = pair.second;
		sorted_high.append(obj);
	}
	for (auto pair : mscore) {
		Json::Value obj(Json::objectValue);
		obj[pair.first] = pair.second;
		month_score.append(obj);
	}
	root["scores"]["total"] = total;
	root["recent_files"] = recent_files;
	root["sorted_high"] = sorted_high;
	root["month_score"] = month_score;
	std::ofstream file("parse_data.json");
	Json::StreamWriterBuilder builder;
	builder["indentation"] = " ";
	std::unique_ptr<Json::StreamWriter> writer(builder.newStreamWriter());
	writer->write(root, &file);
	file.close();
	std::cout << "JSON file written successfully" << std::endl;
}
