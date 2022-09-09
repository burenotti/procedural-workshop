#include <iostream>
#include <fstream>

using namespace std;


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    ifstream file("./inputs/print_file.txt");
    if (!file.is_open()) {
        cout << "File does not exists\n";
        return 0;
    }
    string data;
    getline(file, data, '\0');
    cout << data;
}