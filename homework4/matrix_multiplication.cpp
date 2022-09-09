#include <iostream>
#include <vector>

using namespace std;

#define GOODS_COUNT 4
#define SELLERS_COUNT 3


int main() {
    int goods[SELLERS_COUNT][GOODS_COUNT];
    double prices[GOODS_COUNT][2];
    double result[GOODS_COUNT][2];

    for (int i = 0; i < SELLERS_COUNT; ++i) {
        for (int j = 0; j < GOODS_COUNT; ++j) {
            cout << "Введите количество " << j + 1 << "-ого товара у " << i + 1 << "-ого продавца: ";
            cin >> goods[i][j];
        }
    }

    for (int i = 0; i < GOODS_COUNT; ++i) {
        cout << "Введите цену на " << i + 1 << " товар: ";
        cin >> prices[i][0];
        cout << "Введите цену на " << i + 1 << " товар: ";
        cin >> prices[i][1];
    }

    for (int i = 0; i < SELLERS_COUNT; ++i) {
//        cout << '\n';
        for (int j = 0; j < 2; ++j) {
            result[i][j] = 0;
            for (int k = 0; k < GOODS_COUNT; ++k) {
                result[i][j] += goods[i][k] * prices[k][j];
            }
//            cout << result[i][j];
        }
    }

    int max_proceeds = 0;
    int min_proceeds = 0;
    int max_profit = 0;
    int min_profit = 0;
    double sum_proceeds = 0;
    double sum_profit = 0;

    for (int i = 0; i < GOODS_COUNT; ++i) {

        sum_proceeds += result[i][0];
        sum_profit += result[i][1];

        if (result[max_proceeds][0] < result[i][0])
            max_proceeds = i;

        if (result[min_proceeds][0] > result[i][0])
            min_proceeds = i;

        if (result[max_profit][0] < result[i][1])
            max_profit = i;

        if (result[min_profit][0] > result[i][1])
            min_profit = i;
    }

    cout << "Выручка:\nМакс:" << max_proceeds + 1
         << "продавец \nМин: " << min_proceeds + 1 << " продавец \n\n";

    cout << "Комиссионные:\nМакс: " << max_profit + 1
         << "продавец \nМин: " << min_profit + 1 << " продавец \n\n";

    cout << "Суммарная выручка: " << sum_proceeds << "\n"
         << "Суммарные комиссионные: " << sum_profit << "\n";
}