#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    for (int i = 0; i < 13; ++i) {
        if (i < 7) {
            if (i % 2 == 0) {
                for (int j = 0; j < 4; ++j) {
                    cout << "  *";
                }
                cout.width(60);
                cout << setw(60) << setfill('0');
            } else {
                cout << " ";
                for (int j = 0; j < 4; ++j)
                    cout << "*  ";
            }
            cout << '\n';
        }

    }

    for (int i = 0; i < 18; ++i) {
        char filler;
        if (i % 2 == 0)
            filler = ' ';
        else
            filler = '0';

        cout << setw(72) << setfill(filler) << '\n';
    }

    return 0;
}