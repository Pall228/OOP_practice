#include "Customer.h"
#include <iostream>

int main() {
    Customer object1, object2, object3;

    std::cout << "Введіть дані для трьох клієнтів (по черзі).\n";
    std::cout << "Формат вводу: id прізвище ім'я по_батькові адреса номер_картки баланс\n\n";

    // Перевірка оператора >>
    std::cin >> object1 >> object2 >> object3;

    std::cout << "\n\nВиведення клієнтів:\n";

    // Перевірка оператора <<
    std::cout << object1 << "\n\n" << object2 << "\n\n" << object3 << "\n\n";

    // Перевірка оператора ==
    if (object1 == object2) {
        std::cout << "object1 дорівнює object2\n";
    } else {
        std::cout << "object1 НЕ дорівнює object2\n";
    }

    return 0;
}