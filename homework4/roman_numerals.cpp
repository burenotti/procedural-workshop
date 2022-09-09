#include <iostream>
#include <regex>
#include <functional>

using namespace std;

void replace_all(string& str, const char* pattern, const char* target) {
    str = regex_replace(str, regex(pattern), target);
}

bool is_valid_roman(const string& str) {
    static const regex pattern(R"(^M{0,4}(CM|CD|D?C{0,3})(XC|XL|L?X{0,3})(IX|IV|V?I{0,3})$)");
    return regex_match(str, pattern);
}

int32_t from_roman(string str) {

    if (!is_valid_roman(str)) {
        return -1;
    }

    replace_all(str, "CM", "DCCCC");
    replace_all(str, "CD", "CCCC");
    replace_all(str, "XC", "LXXXX");
    replace_all(str, "XL", "XXXX");
    replace_all(str, "IX", "VIIII");
    replace_all(str, "IV", "IIII");

    replace_all(str, "M", "DD");
    replace_all(str, "D", "CCCCC");
    replace_all(str, "C", "LL");
    replace_all(str, "L", "XXXXX");
    replace_all(str, "X", "VV");
    replace_all(str, "V", "IIIII");

    return static_cast<int32_t>(str.size());
}

int main() {
    string roman;
    while (roman != "q") {
        cout << "Введите число в римской сс: ";
        cin >> roman;
        auto num = from_roman(roman);
        if (num != -1) {
            cout << num << endl;
        } else {
            cout << "Некорректный вввод\n";
        }
    }
}