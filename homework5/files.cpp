#include <iostream>
#include <vector>
#include <tuple>
#include <functional>
#include <fstream>
#include "../utils.cpp"

using namespace std;

auto read_pos = bind(
        base_input<int>,
        placeholders::_1,
        [](int v) { return v > 0; },
        "Число должно быть положительным");

auto read_not_empty = bind(
        base_input<string>,
        placeholders::_1,
        [](string_view str) { return !str.empty(); },
        ""
);

struct Toy {
    string name;
    int price;
    int age_from;
    int age_to;

    Toy() : price(0), age_from(0), age_to(0) {
    }
};

ofstream& operator<<(ofstream& out, const Toy& toy) {
    out << toy.name << " " << toy.price << " "
        << toy.age_from << " " << toy.age_to << endl;
    return out;
}

ostream& operator<<(ostream& out, const Toy& toy) {
    out << toy.name << " " << toy.price << " руб.";
    return out;
}

int main() {
    ofstream file;
    file.open("./outputs/toys.txt");

    if (!file.is_open()) {
        cout << "Не возможно создать файл\n";
        return 0;
    }

    auto toys_count = read_pos("Введите количество игрушек: ");
    vector<Toy> toys(toys_count);

    for (auto& toy: toys) {
        toy.name = read_not_empty("Введите название игрушки: ");
        toy.price = read_pos("Введите цену игрушки: ");
        toy.age_from = read_pos("Игрушка подходит детям от: ");
        toy.age_to = read_pos("Игрушка подходит детям до: ");

        file << toy.name << " " << toy.price << " "
             << toy.age_from << " " << toy.age_to << endl;
    }


    vector<Toy> filter1;

    copy_if(toys.begin(), toys.end(), back_inserter(filter1),
            [](Toy& t) {
                return t.price <= 400 && t.age_from <= 8 && 8 <= t.age_to;
            });


    if (!filter1.empty()) {
        cout << "Детям 8 лет подходят игрушки: \n";
        copy(toys.begin(), toys.end(),
             ostream_iterator<Toy>(cout, "\n"));
    } else {
        cout << "Игрушек не дороже 400 рублей для детей 8 лет нет.\n";
    }

    vector<Toy> filter2;


    copy_if(toys.begin(), toys.end(), back_inserter(filter2),
            [](Toy& t) {
                return (t.age_from <= 4 && 4 <= t.age_to) &&
                       (t.age_from <= 10 && 10 <= t.age_to);
            });

    if (!filter2.empty()) {
        cout << "Детям 4 и 10 лет подходят игрушки: \n";
        copy(filter2.begin(), filter2.end(),
             ostream_iterator<Toy>(cout, "\n"));
    } else {
        cout << "Игрушек для детей 4 и 10 лет нет.\n";
    }


    auto max_price_toy = *max_element(
            toys.begin(), toys.end(),
            [](auto t1, auto t2) {
                return t1.price < t2.price;
            });

    cout << "Самая дорогая игрушка " << max_price_toy.name
         << " стоит " << max_price_toy.price << " руб.";
}