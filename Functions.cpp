// Анализ строк в текстовом файле
#include "Functions.h"

// Поиск строк, удовлетворяющих входным данным
bool filter_search(std::string curr_str, std::vector<std::string> filters, bool filters_contain) {
	std::vector<bool> ex(filters.size(), false);

	for (int i = 0; i < filters.size(); i++) {
		if (curr_str.length() >= filters[i].length()) {
			for (int j = 0; j <= curr_str.length() - filters[i].length(); j++) {
				int k = filters[i].length() - 1;
				while (k >= 0) {
					if (curr_str[j + k] == filters[i][k])
						k--;
					else break;
				}
				if (k == -1) {
					ex[i] = true;
					break;
				}
			}
		}
		else
			ex[i] = false;
	}
	for (int i = 0; i < filters.size(); i++) {
		if (ex[i] != filters_contain)
			return false;
	}

	return true;
}

// Запись нужных строк в выходной файл Result.log
void select_strings(std::vector<std::string> filters, bool filters_contain) {
	std::string curr_str;
	std::fstream fin;

	fin.open("Пример лога для парсинга.log", std::ios::in);
	if (fin.is_open()) {
		std::fstream fout;
		fout.open("Result.log", std::ios::out);
		while (getline(fin, curr_str)) {
			if (filter_search(curr_str, filters, filters_contain) && fout.is_open())
				fout << curr_str << std::endl;
		}
		fout.close();
	}
	fin.close();
}

// Дополнительная функция, конвертация String^ в std::string
// необходима для чтения данных из формы
std::string convert_String_to_string(String^ s) {
    std::string os;
    using namespace Runtime::InteropServices;
    const char* chars =
        (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    os = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));

    return os;
}