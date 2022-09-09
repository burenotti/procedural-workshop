#include <iostream>
#include <vector>
#include "../frac.h"

using namespace std;


vector<int> factorials(int n) {
    vector<int> results = {1};
    int accum = 1;
    for (int i = 1; i <= n; ++i) {
        results.push_back(accum);
        accum *= i;
    }
    return results;
}

int main() {
    int n;



    cout << "Введите n: ";
    cin >> n;

    if (n <= 1) {
        cout << "N должно быть больше 1\n";
    }



    auto fact = factorials(n);

    Frac y;
    for (int k = 1; k <= n; ++k) {
        Frac denom(0, 1);
        for (int i = 1; i <= k; ++i) {
            if (i % 2 == 1)
                denom = denom + Frac(1, k);
            else
                denom = denom + (-Frac(1, k));
        }
        y = y + Frac::from_int(fact[k]) / denom;
    }
    cout << y;
}