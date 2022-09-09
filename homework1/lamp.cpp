#include <iostream>
#include <string_view>
#include <string>
//#include <cmath>

using namespace std;

bool input_bool(string_view message) {
    string value;

    while (value != "да" && value != "нет") {
        std::cout << message << " [да/нет] ";
        cin >> value;
        for_each(value.begin(), value.end(), [](char& x){
           x = static_cast<char>(tolower(x));
        });
    }
    return (value == "да");
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    bool lamp_on = input_bool("Лампа включена?");
    bool is_day = input_bool("На улице день?");
    bool window_open = input_bool("Шторы открыты?");

    if(is_day && window_open || lamp_on) {
        cout << "На улице светло\n";
    } else {
        cout << "На улице темно\n";
    }
}