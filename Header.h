#pragma once
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <cstring>
#include "globals.h"
#include <re2/re2.h>
#include <unordered_map>
#include <json/json.h>
#include <json/value.h>

void reader();
void output_printer();
void json_generator();