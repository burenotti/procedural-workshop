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

    auto a = input<double>("Введите а");
    auto x = input<double>("Введите x");

    double w;

    if (abs(x) < 1) {
        w = a * log(abs(x));
    } else {
        w = sqrt(a - (x*x));
    }
    if (to_string(w) != "nan") {
        printf("w(%f, %f)=%f", a, x, w);
    } else {
        printf("Значение функции не определено");
    }
}