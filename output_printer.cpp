#pragma once
#include "Header.h"

void output_printer() {
	std::cout << "Number of files scanned: " << count << std::endl;
	std::cout << "Low score: " << i_low*2 << std::endl;
	std::cout << "Medium score: " << i_medium*3 << std::endl;
	std::cout << "High score: " << i_high*5 << std::endl;
	std::cout << "Total score: " << i_score << std::endl;
	std::cout << "Hash Table: " << std::endl;
	for (const auto& outer_pair : scoremap) {
		std::cout <<"File name: "<< outer_pair.first << std::endl;
		const std::unordered_map<std::string, int>& inner_map = outer_pair.second;
		for (const auto& inner_pair : inner_map) {
			std::cout << "Severity type: " << inner_pair.first
				<< ", No. of comments: " << inner_pair.second << std::endl;
		}
	}
}