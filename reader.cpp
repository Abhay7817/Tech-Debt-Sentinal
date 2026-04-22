#include "Header.h"
#include <Windows.h>
int i_low; 
int i_medium;
int i_high;
int i_score;
int count;
//std::string low;
//std::string medium;
//std::string high;
static const RE2 pattern1("(?i)to\\s*do|(?i)to\\s*change|(?i)remove\\s*later"); //LOW SCORE +2
static const RE2 pattern4("(?i)\\brefactor\\b|(?i)\\boptimize\\b|(?i)\\bfix\\b"); //MEDIUM SCORE +3
static const RE2 pattern7("(?i)\\bhack\\b|(?i)\\bbug\\b|(?i)temporary"); //HIGH SCORE +5
static const RE2 match("(?://|/\*)(\.+)");
std::unordered_map<std::string, std::unordered_map<std::string, int>> scoremap;
std::vector<std::pair<std::string, int>> mscore = { {"Jan",0}, {"Feb", 0},{"Mar", 0}, {"Apr",0},{"May",0},{"Jun",0},{"Jul",0},{"Aug",0},{"Sep",0},{"Oct",0},{"Nov",0},{"Dec",0} };
void file_time_string(const std::filesystem::path &path, int val);
void reader() {
	for (auto const& dir_entry : std::filesystem::directory_iterator("D:/Programs/tech_debt_sentinal/sample_projects")) {
		if (dir_entry.is_regular_file() && (dir_entry.path().extension() == ".cpp" || dir_entry.path().extension() == ".h")) {
			std::ifstream file(dir_entry.path());
			if (!file.is_open()) {
				std::cout << "Failed to open file" << std::endl;
				break;
			}
			count++;
			//file_time_string(dir_entry.path());
			std::string line;
			re2::StringPiece mword;
			//std::string fname = dir_entry.path().filename().string();
			while (std::getline(file, line)) {
				if (file.bad()) {
					perror("error while reading file");
					break;
				}
				re2::StringPiece input(line);
				while (RE2::FindAndConsume(&input, match, &mword)) {
				i_score = 0;
					if (RE2::FullMatch(mword, "\\s*")) {
						break;
					}
					else if (RE2::PartialMatch(mword, pattern1)) {
						i_low++; i_score = i_score + 2;
						scoremap[dir_entry.path().filename().string()]["low"]++;
						file_time_string(dir_entry.path(), i_score);
					}
					else if (RE2::PartialMatch(mword, pattern4)) {
						i_medium++; i_score = i_score + 3;
						scoremap[dir_entry.path().filename().string()]["medium"]++;
						file_time_string(dir_entry.path(), i_score);
					}
					else if (RE2::PartialMatch(mword, pattern7)) {
						i_high++; i_score = i_score + 5;
						scoremap[dir_entry.path().filename().string()]["high"]++;
						file_time_string(dir_entry.path(), i_score);
					}
				}
				
			}
		}
	}
}
void file_time_string(const std::filesystem::path &path, int val) {
	/*const char* filePath = path.string();*/
	WIN32_FILE_ATTRIBUTE_DATA fileInfo;

	if (GetFileAttributesExW(path.c_str(), GetFileExInfoStandard, &fileInfo)) {
		FILETIME ft = fileInfo.ftLastWriteTime;

		SYSTEMTIME stUTC, stLocal;
		FileTimeToSystemTime(&ft, &stUTC);
		SystemTimeToTzSpecificLocalTime(NULL, &stUTC, &stLocal);
		//std::cout << stLocal.wMonth << " /";
		//std::cout << stLocal.wYear << std::endl;
		if (stLocal.wMonth >= 1 && stLocal.wMonth <= 12)
			mscore[stLocal.wMonth - 1].second += val;
	}
}