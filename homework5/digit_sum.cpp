#include <iostream>

using namespace std;

int digit_sum(int n) {
    if (n == 0) return 0;
    return digit_sum(n / 10) + n % 10;
}


int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    int m;
    cout << "Введите m: ";
    cin >> m;
    if (0 > m || m >= 27) {
        cout << "0 < m < 27";
        return 0;
    }
    cout << "Числа, сумма цифр которых равна " << m << ":\n";
    for (int i = 100; i <= 999; ++i) {
        if (digit_sum(i) == m) cout << i << endl;
    }

}