#pragma once
#include <iostream>
#include <random>
#include "correct.h"


template <typename T>
bool comp(T left, T right) {
    return left < right;
}

template <>
bool comp<char*>(char* left, char* right) {
    return strlen(left) < strlen(right);
}

template <typename T>
void swap(T& left, T& right) {
    auto temp = left;
    left = right;
    right = temp;
}

template <typename T>
T* createArray(int& length) {
    int choice;

    do {
        std::cout << "1. Keyboard input\n2. Random values" << std::endl;
        choice = correct<int>();
    } while (choice <= 0 || choice >= 3);

    do {
        std::cout << "Enter the length" << std::endl;
        length = correct<int>();
    } while (length <= 0);

    T* array = new T[length];

    if (choice == 1) {
        for (int i = 0; i < length; i++) {
            std::cout << i + 1 << ". ";
            array[i] = correct<T>();
        }
    }
    else {

        for (int i = 0; i < length; i++) {
            // символы сортируются по кодам элементов из таблицы ASCII
            if (std::is_same<T, char>::value) array[i] = rand() % 94 + 33;
            else array[i] = rand() % 100;
        }
    }
    return array;
}

template <>
char** createArray<char*>(int& length) {
    std::cout << "Keyboard input\n" << std::endl;

    do {
        std::cout << "Enter the length" << std::endl;
        length = correct<int>();
    } while (length <= 0);

    char** array = new char* [length];
    char* buffer = nullptr;
    for (int i = 0; i < length; i++) {
        std::cout << i + 1 << ". ";
        buffer = correct<char*>();
        array[i] = buffer;
    }

    return array;
}

template<typename T>
void clear(T* arr, int len = 0) {
    delete[] arr;
}

template<>
void clear<char*>(char** arr, int len) {
    for (int i = 0; i < len; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

template<typename T>
void shellSort() {
    int len;

    T* arr = createArray<T>(len);

    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << "\n";

    for (auto d = len / 2; d != 0; d /= 2)
        for (auto i = d; i < len; i++)
            for (auto j = i; j >= d && comp<T>(*(arr + j), *(arr + j - d)); j -= d)
                swap<T>(*(arr + j), *(arr + j - d));

    std::cout << "\n";
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i] << "\t";
    }
    std::cout << "\n";

    clear<T>(arr, len);
}
