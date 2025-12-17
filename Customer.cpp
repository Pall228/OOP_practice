#include "Customer.h"
#include <iostream>

Customer::Customer() {
    id = 0;
    surname = "";
    name = "";
    patronymic = "";
    address = "";
    creditCardNumber = "";
    balance = 0.0;
    std::cout << "Конструктор за замовчуванням викликано" << std::endl;
}

Customer::Customer(int id, const std::string& surname, const std::string& name,
                   const std::string& patronymic, const std::string& address,
                   const std::string& creditCardNumber, double balance) {
    this->id = id;
    this->surname = surname;
    this->name = name;
    this->patronymic = patronymic;
    this->address = address;
    this->creditCardNumber = creditCardNumber;
    this->balance = balance;
    std::cout << "Параметризований конструктор викликано" << std::endl;
}

Customer::Customer(const Customer& other) {
    id = other.id;
    surname = other.surname;
    name = other.name;
    patronymic = other.patronymic;
    address = other.address;
    creditCardNumber = other.creditCardNumber;
    balance = other.balance;
    std::cout << "Конструктор копіювання викликано" << std::endl;
}

Customer::~Customer() {
    std::cout << "Деструктор викликано для клієнта ID=" << id << std::endl;
}

// Геттери
int Customer::getId() const { return id; }
std::string Customer::getSurname() const { return surname; }
std::string Customer::getName() const { return name; }
std::string Customer::getPatronymic() const { return patronymic; }
std::string Customer::getAddress() const { return address; }
std::string Customer::getCreditCardNumber() const { return creditCardNumber; }
double Customer::getBalance() const { return balance; }

// Сеттери (реалізуйте за потребою)
void Customer::setId(int id) { this->id = id; }
void Customer::setSurname(const std::string& surname) { this->surname = surname; }
void Customer::setName(const std::string& name) { this->name = name; }
void Customer::setPatronymic(const std::string& patronymic) { this->patronymic = patronymic; }
void Customer::setAddress(const std::string& address) { this->address = address; }
void Customer::setCreditCardNumber(const std::string& creditCardNumber) { this->creditCardNumber = creditCardNumber; }
void Customer::setBalance(double balance) { this->balance = balance; }

void Customer::display() const {
    std::cout << "ID: " << id << "\n"
              << "ПІБ: " << surname << " " << name << " " << patronymic << "\n"
              << "Адреса: " << address << "\n"
              << "Номер кредитної картки: " << creditCardNumber << "\n"
              << "Баланс: " << balance << " грн\n\n";
}