#include<iostream>
#include <cmath>
#include <iomanip>
#include "../utils.cpp"

using namespace std;

double f(double S, double r, double n) {
    if (r > 0) {
        return (S * r * pow(1 + r, n)) /
               (12 * (pow(1 + r, n) - 1));
    } else {
        return S * r / 12;
    }
}

int main() {
    auto S = input<double>("Введите S");
    auto m = input<double>("Введите m");
    auto n = input<double>("Введите n");


    if (m <= 0 || S <= 0 || n < 1) {
        cout << "Данные не верны";
    }

    double left = 0;
    double right = 300;

    while (abs(right - left) > 1e-7) {
        double p = (left + right) / 2;

        if (f(S, p, n) < m) {
            left = p;
        } else {
            right = p;
        }
    }

    cout << "Процент равен " << fixed << setprecision(2) << left * 100 << endl;
}