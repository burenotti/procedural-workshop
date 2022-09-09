#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;


int main() {

    int n;
    cout << "Введите n: ";
    cin >> n;

    if (n <= 1) {
        cout << "N должно быть больше 1\n";
    }

    double y = 0;
    for (int i = 1; i <= n; ++i) {
        double denom = 0;
        for (int j = 1; j <= i; ++j) {
            denom = denom + sin(j);
        }
        y = y + i / denom;
    }

    cout << "y(" << n << ") = " << setprecision(9) << y;
}