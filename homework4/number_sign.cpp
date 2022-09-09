#include "iostream"

using namespace std;

double sign(double val) {
    if (val > 0)
        return 1;
    if (val == 0)
        return 0;
    else
        return -1;
}

int main() {
    double x;
    cout << "Введите число: ";
    cin >> x;
    cout << "Знак: " << sign(x);
}