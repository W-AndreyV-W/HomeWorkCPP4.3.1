﻿#include <iostream>
#include <locale.h>

class SmartArray {
public:

    SmartArray(const SmartArray&) = delete;
    SmartArray& operator=(const SmartArray&) = delete;

    SmartArray(int size) {
        array = new int[size] {};
        size_ = size;
    }

    ~SmartArray() {
        delete[] array;
        array = nullptr;
        if (array_new != nullptr) {
            delete[] array_new;
            array_new = nullptr;
        }
    }

    void add_element(int number);

    int get_element(int array_out) {
        return array[array_out];
    }

private:
    int* array = nullptr;
    int* array_new = nullptr;
    int size_ = 1;
    int num_array = 0;

    // Изменение размера массива
    void changing_array();
};

void SmartArray::changing_array() {

    int size_new = 2 * size_;
    array_new = new int[size_new] {};

    for (int i = 0; i < size_; i++) {
        array_new[i] = array[i];
    }

    size_ = size_new;

    delete[] array;
    array = array_new;
    array_new = nullptr;
}

void SmartArray::add_element(int number) {

    if (num_array == size_) {
        changing_array();
    }

    array[num_array] = number;
    num_array++;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    try {
        SmartArray arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        arr.add_element(25);
        std::cout << arr.get_element(5) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
}