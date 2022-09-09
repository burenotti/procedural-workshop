#include <iostream>
#include <cmath>
#include "../utils.cpp"

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    auto S = input<double>("Введите S");
    double p = input<double>("Введите p");
    double n = input<int>("Введите n");

    double r = p / 100.0;
    if (p < 0 || S < 0 || n < 1) {
        cout << "Данные не верны";
    } else if (p == 0) {
        cout << "Месячная выплата равна " << ((S) / (12 * n)) << endl;
    } else {
        cout << "Месячная выплата равна " << ((S * r * pow(1 + r, n)) / (12 * (pow(1 + r, n) - 1))) << endl;
    }
}