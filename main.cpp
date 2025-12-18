#include <iostream>
#include <vector>
#include "Customer.h"
#include "Seller.h"

int main() {
    std::cout << "=== Перевірка роботи похідних класів (Customer та Seller) ===\n\n";

    // Два об'єкти Customer
    Customer cust1("Петров", "Петро", "Петрович", "м. Львів, вул. Франка 10", "1111-2222-3333-4444", 8500.75);
    Customer cust2("Коваль", "Анна", "Василівна", "м. Київ, вул. Шевченка 5", "9999-8888-7777-6666", 12300.00);

    // Два об'єкти Seller
    std::vector<std::string> goods1 = {"Смартфон Samsung Galaxy", "Навушники Sony", "Чохол"};
    Seller seller1(201, "Іванов", "Іван", "Іванович", "м. Одеса, вул. Дерибасівська 12", "UA12345678901234567890", goods1);

    std::vector<std::string> goods2 = {"Ноутбук ASUS", "Мишка Razer", "Клавіатура"};
    Seller seller2(202, "Сидоренко", "Олег", "Миколайович", "м. Харків, вул. Сумська 25", "UA09876543210987654321", goods2);

    std::cout << "Клієнт 1:\n" << cust1 << "\n\n";
    std::cout << "Клієнт 2:\n" << cust2 << "\n\n";
    std::cout << "Продавець 1:\n" << seller1 << "\n\n";
    std::cout << "Продавець 2:\n" << seller2 << "\n\n";

    std::cout << "Програма завершена успішно!\n";
    return 0;
}