#include <iostream>
#include <functional>
#include <tuple>

using namespace std;


tuple<function<int()>, function<void()>> get_random() {
    int m = 37;
    int b = 3;
    int c = 64;
    int s0 = 0;
    int* s = new int;
    auto next = [=]() -> int {
        *s = (m * (*s) + b) % c;
        return (*s);
    };

    auto finalize = [=]() {
        delete s;
    };
    return make_tuple(next, finalize);
}

int main() {
    auto [rand, finalize] = get_random();
    for(int i = 0; i < 10; ++i) {
        cout << rand() << " ";
    }
    finalize();
}