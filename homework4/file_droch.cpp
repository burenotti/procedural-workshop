#include <iostream>
#include <fstream>
#include <filesystem> // Requires C++17
#include <numeric>

using namespace std;

int main() {
    {
        ofstream file;
        file.open("./outputs/file_droch.txt");

        if (!file.is_open()) {
            cout << "Не удалось создать или открыть файл";
            return 0;
        }
        for (int i = 0; i < 10; ++i) {
            file << (rand() % 100) << "\n";
        }

        file.flush();
        file.close();
    }
    {

        int sum = 0;
        ifstream file("./outputs/file_droch.txt");
        for_each(istream_iterator<int>(file), istream_iterator<int>(),
                 [&sum](int val) { sum += val; });
        cout << sum;
        file.close();
    }
}