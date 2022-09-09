#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
char rand_char(T& random) {
    return static_cast<char>('A' + random() % 26);
}


template<class TBegin, class TMid, class TEnd>
void merge(TBegin&& begin, TMid&& middle, TEnd&& end) {

    int len = distance(begin, end);
    std::vector<typename std::remove_reference_t<decltype(*begin)>> buffer(len);

    auto left = begin;
    auto right = middle;
    auto left_stop = right;

    for (int i = 0; i < len; ++i) {
        if ((*left < *right && left != left_stop) || right == end) {
            buffer[i] = *left;
            left++;
        } else {
            buffer[i] = *right;
            right++;
        }
    }

    std::copy(buffer.begin(), buffer.end(), begin);
}


template<class TBegin, class TEnd>
void merge_sort(TBegin&& begin, TEnd&& end) {
    int len = distance(begin, end);

    if (len > 1) {
        auto mid = begin + len / 2;
        merge_sort(begin, mid);
        merge_sort(mid, end);
        merge(begin, mid, end);
    }
}

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");
    std::string str;

    std::mt19937 random((std::random_device()()));

    for(int i = 0; i < 30; ++i) {
        str += rand_char(random);
    }
    cout << "Изначальная строка: " << str << endl;


    sort(str.begin(), str.end());

    cout << "Отсортированная строка: " << str;
    merge_sort(str.begin(), str.end());
}