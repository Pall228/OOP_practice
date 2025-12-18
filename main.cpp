#include <iostream>
#include <vector>
#include <string>
#include <limits>
#include "Customer.h"
#include "Seller.h"

int showMenu() {
    int choice;
    std::cout << "\n=== Меню створення об'єкта ===\n";
    std::cout << "1. Створити Клієнта (Customer)\n";
    std::cout << "2. Створити Продавця (Seller)\n";
    std::cout << "0. Завершити введення\n";
    std::cout << "Ваш вибір: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

int main() {
    const int SIZE = 5;
    Person* people[SIZE];  // масив вказівників на базовий клас
    int count = 0;

    std::cout << "Створення до 5 об'єктів через поліморфізм\n";

    while (count < SIZE) {
        int choice = showMenu();

        if (choice == 0) break;

        if (choice == 1) {
            // Створюємо Customer
            Customer* c = new Customer();
            std::cin >> *c;  // використовуємо перевантажений >>
            people[count++] = c;
        }
        else if (choice == 2) {
            // Створюємо Seller
            Seller* s = new Seller();
            // Заповнюємо базові поля через >>
            Customer temp;  // тимчасовий об'єкт, щоб використати спільний оператор (або зробити окремий)
            std::cin >> temp;
            s->setSurname(temp.getSurname());
            s->setName(temp.getName());
            s->setPatronymic(temp.getPatronymic());
            s->setAddress(temp.getAddress());

            int id;
            std::string acc;
            std::cout << "Введіть ID продавця: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Введіть номер рахунку: ";
            std::getline(std::cin, acc);

            s->setId(id);
            s->setAccountNumber(acc);

            std::cout << "Введіть кількість товарів: ";
            int n;
            std::cin >> n;
            std::cin.ignore();
            for (int i = 0; i < n; ++i) {
                std::string good;
                std::cout << "Товар " << i+1 << ": ";
                std::getline(std::cin, good);
                s->addGood(good);
            }

            people[count++] = s;
        }
        else {
            std::cout << "Невірний вибір!\n";
        }
    }

    // Вивід усіх об'єктів
    std::cout << "\n=== Дані всіх об'єктів ===\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Об'єкт " << i+1 << ":\n";
        std::cout << *people[i] << "\n";
    }

    // Виклик віртуального методу
    std::cout << "\n=== Виклик віртуального методу showRole() ===\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Об'єкт " << i+1 << ": ";
        people[i]->showRole();
    }

    // Очищення пам'яті
    for (int i = 0; i < count; ++i) {
        delete people[i];
    }

    std::cout << "\nПрограма завершена.\n";
    return 0;
}