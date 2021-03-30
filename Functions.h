// Анализ строк в текстовом файле
#pragma once
#include <fstream>
#include <string>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;

bool filter_search(std::string, std::vector<std::string>, bool);
void select_strings(std::vector<std::string>, bool);

std::string convert_String_to_string(String^);
