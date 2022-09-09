cmake_minimum_required(VERSION 3.20)
project(titanic_17)

set(CMAKE_CXX_STANDARD 20)

# Homework 1
add_executable(name homework1/name.cpp)
add_executable(arithmetic homework1/arithmetic.cpp)
add_executable(equantion homework1/equantion.cpp)
add_executable(another_equantion homework1/another_equantion.cpp)
add_executable(lamp homework1/lamp.cpp)


# Homework 2
add_executable(konus homework2/konus.cpp utils.cpp)
add_executable(function homework2/function.cpp)
add_executable(function2 homework2/function2.cpp)
add_executable(tabualtion homework2/tabulation.cpp)
add_executable(order homework2/order.cpp)


# Homework 3
add_executable(zaem homework3/zaem.cpp utils.cpp)
add_executable(ssuda homework3/ssuda.cpp utils.cpp)
add_executable(char_sort homework3/char_sort.cpp utils.cpp)
add_executable(print_file homework3/print_file.cpp)
add_executable(filter_file homework3/filter_file.cpp)


# Homework 4
add_executable(random_generator homework4/rand_gen.cpp)
add_executable(matrix_multiplication homework4/matrix_multiplication.cpp)
add_executable(file_droch homework4/file_droch.cpp)
add_executable(number_sign homework4/number_sign.cpp)
add_executable(figures homework4/figures.cpp)
add_executable(past_glory homework4/past_glory.cpp)
add_executable(roman_numerals homework4/roman_numerals.cpp)

# Homework 5
add_executable(euclid homework5/euclid.cpp)
add_executable(sinus homework5/sinus.cpp)
add_executable(sieve homework5/sieve.cpp)
add_executable(replace_spaces homework5/replace_spaces.cpp)
add_executable(map_ascii homework5/map_ascii.cpp)
add_executable(digit_sum homework5/digit_sum.cpp)
add_executable(rows_1 homework5/rows_1.cpp frac.h)
add_executable(rows_2 homework5/rows_2.cpp frac.h)
add_executable(files homework5/files.cpp)

# Задача шарики
add_executable(balls balls.cpp)

# Test
#add_executable(frac frac.cpp)