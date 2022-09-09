#include <iostream>
#include <cmath>
#include <functional>
#include "../utils.cpp"

using namespace std;


int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    using placeholders::_1;

    auto input = bind(
            base_input<double>, _1,
            [](double v) { return v > 0; },
            "Число должно быть больше нуля"
    );


    auto r = input("Введите малый радиус: ");
    auto R = input("Введите большой радиус: ");
    auto h = input("Введите высоту: ");

    double l = sqrt(pow(h, 2) + pow(R - r, 2));

    double S = M_PI * (R*R + (R + r) * l + r*r);
    double V = M_PI * (1.0 / 3) * h * (R*R + R*r + r*r);

    printf("S=%f V=%f", S, V);
}