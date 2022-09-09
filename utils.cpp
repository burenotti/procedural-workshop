#pragma once

#include <string_view>
#include <functional>
#include <iostream>

using std::string_view;
using std::function;
using std::cout;
using std::cin;

template<typename T>
T base_input(
        string_view message,
        function<bool(T)> checker,
        string_view error_message = ""
) {

    T value;

    while (true) {
        cout << message << '\n';
        cin >> value;
        if (checker(value)) {
            return value;
        } else {
            cout << error_message << '\n';
        }
    }
}

template<typename T>
T input(string_view message) {
    return base_input<T>(message, [](T){return true;}, "");
}