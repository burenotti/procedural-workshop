#include <iostream>
#include <cmath>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    double a, b, c;
    cout << "Введите a b c:\n";
    cin >> a >> b >> c;
    if (a != 0) {
        double D = b * b - 4 * a * c;
        if (D < 0) {
            cout << "Нет решений";
            return 0;
        }

        cout << (-b + sqrt(D)) / (2 * a) << endl;

        if (D > 0)
            cout << (-b - sqrt(D)) / (2 * a) << endl;
    } else {
        if (b == 0)

            if (c == 0) {
                cout << "Любое число\n";
            } else {
                cout << "Решений нет\n";
            }

        else {
            cout << (-c / b);
        }
    }
}