#include <iostream>

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    double b, c;
    std::cout << "Введите два числа:";
    std::cin >> b >> c;
    if (b == 0 && c == 0)
        std::cout << "Любое число\n";

    if (b != 0)
        std::cout << (-c / b);
    else
        std::cout << "Решений нет";
}