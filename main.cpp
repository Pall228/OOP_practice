#include <iostream>
#include <list>
#include <map>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>
#include <string>
#include "Person.h"
#include "Customer.h"
#include "Seller.h"

// Функція меню
int showMenu() {
    int choice;
    std::cout << "\n=== Головне меню ===\n";
    std::cout << "1. Демонстрація роботи з std::list (непарні/парні числа)\n";
    std::cout << "2. Додати об'єкт до std::map (за ID)\n";
    std::cout << "3. Вивести об'єкт за ID з std::map\n";
    std::cout << "4. Вивести всі об'єкти з std::map\n";
    std::cout << "0. Вихід\n";
    std::cout << "Ваш вибір: ";
    std::cin >> choice;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return choice;
}

// Підменю для вибору типу об'єкта
int chooseObjectType() {
    int type;
    std::cout << "\nОберіть тип об'єкта:\n";
    std::cout << "1. Клієнт (Customer)\n";
    std::cout << "2. Продавець (Seller)\n";
    std::cout << "Вибір: ";
    std::cin >> type;
    std::cin.ignore();
    return type;
}

int main() {
    std::cout << "=== Практична робота №8: std::list, std::map та ієрархія класів ===\n\n";

    // Контейнери для демонстрації std::list
    std::list<int> oddList;
    std::list<int> evenList;
    std::list<int> mergedList;

    // Асоціативний контейнер: ключ — ID (int), значення — вказівник на Person
    std::map<int, Person*> objectMap;

    // Генератор випадкових чисел
    std::mt19937 gen(static_cast<unsigned>(std::time(nullptr)));
    std::uniform_int_distribution<> dis(1, 200);

    bool running = true;
    while (running) {
        int choice = showMenu();

        switch (choice) {
        case 1: {
            // 2-4. Робота з std::list
            oddList.clear();
            evenList.clear();
            mergedList.clear();

            std::cout << "\nЗаповнення першого списку непарними числами:\n";
            for (int i = 0; i < 10; ++i) {
                int num;
                do {
                    num = dis(gen);
                } while (num % 2 == 0);
                oddList.push_back(num);
                std::cout << num << " ";
            }
            std::cout << "\n";

            std::cout << "Заповнення другого списку парними числами (через ітератор):\n";
            auto it = evenList.begin();
            int count = 0;
            while (count < 10) {
                int num = dis(gen);
                if (num % 2 == 0) {
                    evenList.insert(it, num);  // вставляємо перед ітератором
                    std::cout << num << " ";
                    ++count;
                }
            }
            std::cout << "\n";

            // Сортування
            oddList.sort();
            evenList.sort();

            // Об'єднання
            std::merge(oddList.begin(), oddList.end(),
                       evenList.begin(), evenList.end(),
                       std::back_inserter(mergedList));

            // Вивід
            std::cout << "\nПерший список (непарні, відсортовані): ";
            for (int x : oddList) std::cout << x << " ";
            std::cout << "\nДругий список (парні, відсортовані): ";
            for (int x : evenList) std::cout << x << " ";
            std::cout << "\nТретій список (об'єднаний): ";
            for (int x : mergedList) std::cout << x << " ";
            std::cout << "\n\n";
            break;
        }
        case 2: {
            // 5-6. Додавання об'єкта до map за ID
            int id;
            std::cout << "Введіть ID об'єкта: ";
            std::cin >> id;
            std::cin.ignore();

            if (objectMap.find(id) != objectMap.end()) {
                std::cout << "Об'єкт з ID " << id << " вже існує!\n";
                break;
            }

            int type = chooseObjectType();
            Person* obj = nullptr;

            if (type == 1) {
                Customer* c = new Customer();
                std::cin >> *c;
                obj = c;
            } else if (type == 2) {
                Seller* s = new Seller();

                // Заповнення базових полів
                Customer temp;
                std::cin >> temp;
                s->setSurname(temp.getSurname());
                s->setName(temp.getName());
                s->setPatronymic(temp.getPatronymic());
                s->setAddress(temp.getAddress());

                std::cout << "Введіть ID продавця (якщо відрізняється від ключа): ";
                int sellerId;
                std::cin >> sellerId;
                std::cin.ignore();

                std::string acc;
                std::cout << "Введіть номер рахунку: ";
                std::getline(std::cin, acc);

                s->setId(sellerId);
                s->setAccountNumber(acc);

                std::cout << "Введіть кількість товарів: ";
                int n;
                std::cin >> n;
                std::cin.ignore();
                for (int i = 0; i < n; ++i) {
                    std::string good;
                    std::cout << "Товар " << i + 1 << ": ";
                    std::getline(std::cin, good);
                    s->addGood(good);
                }

                obj = s;
            } else {
                std::cout << "Невірний тип!\n";
                break;
            }

            objectMap[id] = obj;
            std::cout << "Об'єкт з ID " << id << " успішно додано до map!\n";
            break;
        }
        case 3: {
            // 7. Вивід об'єкта за ID
            int id;
            std::cout << "Введіть ID об'єкта для виведення: ";
            std::cin >> id;

            auto it = objectMap.find(id);
            if (it != objectMap.end()) {
                std::cout << "\nОб'єкт з ID " << id << ":\n";
                std::cout << *(it->second) << "\n";
                it->second->showRole();
            } else {
                std::cout << "Об'єкт з ID " << id << " не знайдено!\n";
            }
            break;
        }
        case 4: {
            // Вивід всіх об'єктів з map
            if (objectMap.empty()) {
                std::cout << "Контейнер std::map порожній!\n";
            } else {
                std::cout << "\n=== Всі об'єкти в std::map ===\n";
                for (const auto& pair : objectMap) {
                    std::cout << "ID: " << pair.first << "\n";
                    std::cout << *(pair.second) << "\n";
                    pair.second->showRole();
                    std::cout << "\n";
                }
            }
            break;
        }
        case 0:
            running = false;
            break;
        default:
            std::cout << "Невірний вибір!\n";
        }
    }

    // Очищення пам'яті
    for (auto& pair : objectMap) {
        delete pair.second;
    }

    std::cout << "\nПрограма завершена успішно!\n";
    return 0;
}