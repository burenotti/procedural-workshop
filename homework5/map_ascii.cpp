#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    ifstream file("./inputs/map_ascii.txt");

    if (!file.is_open()) {
        cout << "Невозможно открыть файл";
        return 0;
    }

    string data;
    getline(file, data, '\0');

    copy(data.begin(), data.end(),
         ostream_iterator<int>(cout, " "));
}