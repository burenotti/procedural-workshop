#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
T input(string_view message) {
    cout << message << ": ";
    T value;
    cin >> value;
    return value;
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    auto x = input<double>("Введите x");
    auto y = input<double>("Введите y");
    auto b = input<double>("Введите b");

    double z = log(b - y) * sqrt(b - x);

    if (to_string(z) == "nan") {
        printf("Значение функции не определено");
    } else {
        printf("%f", z);
    }
}