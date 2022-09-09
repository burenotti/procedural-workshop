#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    cout << "Введите два числа:\n";
    double a, b;
    cin >> a >> b;
    cout << a << "+" << b << "=" << a + b << '\n'
         << a << "-" << b << "=" << a - b << '\n'
         << a << "*" << b << "=" << a * b << '\n';
    if (b != 0)
        cout << a / b << '\n';
    else
        cout << "На ноль делить нельзя\n";
}