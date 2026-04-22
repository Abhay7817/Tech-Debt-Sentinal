#pragma once
#include <unordered_map>
#include <string>
#include <map>
extern int count;
// inline constexpr std::array<std::string_view, 9> debtWords = {
//     "todo","fix","to change","hack","temporary","refactor","remove later","optimize later","bug" 
// };
extern int i_low;
extern int i_medium;
extern int i_high;
extern int i_score;
extern int count;
extern std::unordered_map<std::string, std::unordered_map<std::string, int>> scoremap;
extern std::vector<std::pair<std::string, int>> sorted_v;
extern std::vector<std::pair<std::string, int>> mscore;