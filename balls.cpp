#include <iostream>
#include <algorithm>
#include <vector>
#include "frac.h"
#include "utils.cpp"


using namespace std;


vector<vector<int>> permutations(int n) {
    vector<int> v;
    v.reserve(n);
    for (int i = 0; i < n; ++i) v.push_back(i + 1);

    vector<vector<int>> result;

    generate_n(back_inserter(result), factorial(n), [&v]() {
        next_permutation(v.begin(), v.end());
        return v;
    });

    return result;
}


int main() {
    auto input = bind(
            base_input<int>,
            placeholders::_1,
            [](int v) { return v > 0; },
            "Число должно быть больше 0"
    );

    auto n = input("Введите N: ");

    auto perms = permutations(n);
    for (auto& p: perms) {
        int ok = -1;
        for (int i = 0; i < p.size(); ++i) {
            ok = ((p[i] - 1) == i) ? i : ok;
        }
        if (ok != -1) {
            cout << ok + 1 << " шарик выводится " << ok + 1 << "-ым: ";
            copy(p.begin(), p.end(),
                 ostream_iterator<int>(cout, " "));
            cout << "\n";
        }
    }
}