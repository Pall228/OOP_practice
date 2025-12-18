#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
#include <limits>
#include "Person.h"
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
    std::cout << "=== Практична робота №7: Алгоритми STL та вектори ===\n\n";

    // 2. Два вектори цілих чисел
    std::vector<int> oddNumbers(10);    // 10 непарних непослідовних
    std::vector<int> evenNumbers(10);   // 10 парних непослідовних

    // Генератор випадкових чисел
    std::mt19937 gen(static_cast<unsigned>(time(0)));
    std::uniform_int_distribution<> dis(1, 200);

    // Заповнення першого вектора непарними числами (за допомогою індексу)
    std::cout << "Заповнення вектора непарними числами (за індексом):\n";
    for (int i = 0; i < 10; ++i) {
        int num;
        do {
            num = dis(gen);
        } while (num % 2 == 0);  // тільки непарні
        oddNumbers[i] = num;
        std::cout << "oddNumbers[" << i << "] = " << num << "\n";
    }

    // Заповнення другого вектора парними числами (за допомогою ітератора)
    std::cout << "\nЗаповнення вектора парними числами (за ітератором):\n";
    auto it = evenNumbers.begin();
    int count = 0;
    while (count < 10) {
        int num = dis(gen);
        if (num % 2 == 0) {  // тільки парні
            *it = num;
            std::cout << "evenNumbers[" << count << "] = " << num << "\n";
            ++it;
            ++count;
        }
    }

    // 3. Сортування та об'єднання
    std::sort(oddNumbers.begin(), oddNumbers.end());
    std::sort(evenNumbers.begin(), evenNumbers.end());

    std::vector<int> merged(20);
    std::merge(oddNumbers.begin(), oddNumbers.end(),
               evenNumbers.begin(), evenNumbers.end(),
               merged.begin());

    std::cout << "\nПісля сортування та об'єднання:\n";
    std::cout << "Непарні (відсортовані): ";
    for (int x : oddNumbers) std::cout << x << " ";
    std::cout << "\nПарні (відсортовані): ";
    for (int x : evenNumbers) std::cout << x << " ";
    std::cout << "\nОб'єднаний вектор: ";
    for (int x : merged) std::cout << x << " ";
    std::cout << "\n\n";

    // 4. Вектор вказівників на базовий клас (інтерактивне заповнення)
    std::vector<Person*> people;

    std::cout << "=== Заповнення вектора об'єктами похідних класів ===\n";
    while (true) {
        int choice = showMenu();
        if (choice == 0) break;

        if (choice == 1) {
            Customer* c = new Customer();
            std::cin >> *c;  // використовуємо перевантажений >>
            people.push_back(c);
        }
        else if (choice == 2) {
            Seller* s = new Seller();

            // Заповнення базових полів (ПІБ, адреса)
            Customer temp;  // тимчасовий, щоб скористатися спільним введенням
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
                std::cout << "Товар " << i + 1 << ": ";
                std::getline(std::cin, good);
                s->addGood(good);
            }

            people.push_back(s);
        }
        else {
            std::cout << "Невірний вибір!\n";
        }
    }

    // Вивід початкового вектора
    std::cout << "\n=== Початковий вектор people ===\n";
    for (size_t i = 0; i < people.size(); ++i) {
        std::cout << "Об'єкт " << i + 1 << ":\n" << *people[i] << "\n";
    }

    // 5. Створення копії та видалення елементів
    std::vector<Person*> peopleCopy = people;  // поверхнева копія вказівників

    // Видаляємо всіх Customer з першого вектора
    people.erase(
        std::remove_if(people.begin(), people.end(),
            [](Person* p) { return dynamic_cast<Customer*>(p) != nullptr; }),
        people.end()
    );

    // Видаляємо всіх Seller з другого вектора
    peopleCopy.erase(
        std::remove_if(peopleCopy.begin(), peopleCopy.end(),
            [](Person* p) { return dynamic_cast<Seller*>(p) != nullptr; }),
        peopleCopy.end()
    );

    // Вивід після видалення
    std::cout << "\n=== Після видалення ===\n";
    std::cout << "Перший вектор (залишились тільки Seller):\n";
    for (size_t i = 0; i < people.size(); ++i) {
        std::cout << "Об'єкт " << i + 1 << ":\n" << *people[i] << "\n";
    }

    std::cout << "\nДругий вектор (залишились тільки Customer):\n";
    for (size_t i = 0; i < peopleCopy.size(); ++i) {
        std::cout << "Об'єкт " << i + 1 << ":\n" << *peopleCopy[i] << "\n";
    }

    // Очищення пам'яті
    for (Person* p : people) delete p;
    for (Person* p : peopleCopy) {
        // Не видаляємо вдруге ті, що вже видалені з першого вектора
        if (std::find(people.begin(), people.end(), p) == people.end()) {
            delete p;
        }
    }

    std::cout << "\nПрограма завершена успішно!\n";
    return 0;
}