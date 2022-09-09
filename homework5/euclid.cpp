#include <iostream>


using namespace std;

int euclid(int a, int b) {
    if (a == b)
        return a;

    return (a > b) ? euclid(a - b, b) : euclid(a, b - a);
}

int euclid2(int a, int b) {
    if (a == 0 || b == 0)
        return a + b;

    return (a > b) ? euclid2(a % b, b) : euclid2(a, b % a);
}

int main() {
    int a, b;
    cout << "Введите два числа: ";
    cin >> a >> b;
    if (a == 0 || b == 0) {
        cout << "Нельзя искать НОД с 0\n";
        return 0;
    }

    cout << "НОД вычитанием: " << euclid(a, b) << '\n';
    cout << "НОД делением: " << euclid2(a, b) << '\n';

}