#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool is_digit(char x) {
    return '0' <= x && x <= '9';
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    ifstream file("./inputs/filter_file.txt");

    if (!file.is_open()) {
        cout << "File does not exists\n";
        return 0;
    }

    while (!file.eof()) {
        char x;
        cin >> x;
        if (is_digit(x))
            cout << x;
    }
}