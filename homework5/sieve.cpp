#include <iostream>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<bool> ok(n + 1, true);
    for (int i = 2; i <= n; ++i) {
        int j = 2;
        while ((j != n) && (j * i <=n)) {
            ok[j * i] = false;
            ++j;
        }
    }
    vector<int> result;
    for (int i = 2; i < ok.size(); ++i) {
        if (ok[i]) result.push_back(i);
    }
    return result;
}

int main() {
    int n;
    cout << "Введите число: ";
    cin >> n;
    if (n < 0) {
        cout << "Число должно быть положительным\n";
        return 0;
    }
    cout << "Простые числа от 2 до " << n << ":\n";

    for(auto e: sieve(n)) {
        cout << e << " ";
    }
}