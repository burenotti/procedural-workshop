#include <iostream>
#include "../utils.cpp"

using namespace std;

int main() {
    auto input = bind(
            base_input<double>, placeholders::_1,
            [](double v) { return v > 0 && (int) v == v; },
            "Число должно быть больше нуля"
    );
    auto n = input("Введите n:");

    for(int i = n; i < n + 10; ++i)
        cout << i << " ";
}