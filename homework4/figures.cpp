#include <iostream>
#include <cmath>
#include <functional>
#include "../utils.cpp"

using namespace std;


auto read_side = bind(
        base_input<double>,
        placeholders::_1,
        [](double v) { return v > 0; },
        "Сторона должна быть больше 0");

void rectangle(double a, double b) {
    cout << "Площадь прямоугольника: " << a * b << endl;
}

void triangle(double a, double h) {
    cout << "Площадь треугольника: " << 0.5 * a * h << endl;
}

void circle(double R) {
    cout << "Площадь круга: " << M_PI * R * R << endl;
}

int main() {
    double a, b, h, R;
    int ask;
    cout << "1.прямоугольник\n2.треугольник\n3.круг\n(1-3): ";
    cin >> ask;

    switch (ask) {
        case 1:
            a = read_side("Введите длину прямоугольника: ");
            b = read_side("Введите высоту: ");
            rectangle(a, b);
            break;
        case 2:
            a = read_side("Введите сторону треугольника: ");
            h = read_side("Введите высоту: ");
            triangle(a, h);
            break;
        case 3:
            R = read_side("Введите радиус окружности: ");
            circle(R);
            break;
        default:
            cout << "Такого варианта нет";
    }


}