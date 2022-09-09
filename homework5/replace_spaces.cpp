#include <iostream>
#include <fstream>

using namespace std;


int main() {
    setlocale(LC_ALL, "ru_RU.utf8");
    ifstream file("./inputs/replace.txt");

    if (!file.is_open()) {
        cout << "Невозможно открыть файл";
        return 0;
    }

    string data;
    char x;
    cout << "Введите символ, на который нужно заменить пробелы: ";
    cin >> x;

    getline(file, data, '\0');
    for (char & c : data) {
        if (isspace(c)){
            c = x;
        }
    }

    file.close();
    ofstream fw("inputs/replace.txt");
    fw << data;
    fw.flush();
    fw.close();
}