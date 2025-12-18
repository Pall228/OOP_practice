#include "Customer.h"
#include <iostream>
#include <limits>

Customer::Customer() : balance(0.0) {}

Customer::Customer(const std::string& s, const std::string& n,
                   const std::string& p, const std::string& a,
                   const std::string& card, double bal)
    : Person(s, n, p, a), cardNumber(card), balance(bal) {}

void Customer::display() const {
    Person::display();
    std::cout << "Номер картки: " << cardNumber << "\n"
              << "Баланс: " << balance << "\n";
}

void Customer::showRole() const {
    std::cout << "Роль: Клієнт (Customer)\n";
}

std::ostream& operator<<(std::ostream& os, const Customer& c) {
    c.display();
    return os;
}

std::istream& operator>>(std::istream& in, Customer& c) {
    std::cout << "Введіть прізвище: ";
    std::getline(in >> std::ws, c.surname);
    std::cout << "Введіть ім'я: ";
    std::getline(in >> std::ws, c.name);
    std::cout << "Введіть по батькові: ";
    std::getline(in >> std::ws, c.patronymic);
    std::cout << "Введіть адресу: ";
    std::getline(in >> std::ws, c.address);
    std::cout << "Введіть номер картки: ";
    std::getline(in >> std::ws, c.cardNumber);
    std::cout << "Введіть баланс: ";
    in >> c.balance;
    in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return in;
}