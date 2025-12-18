#include "Person.h"

Person::Person() = default;

Person::Person(const std::string& s, const std::string& n,
               const std::string& p, const std::string& a)
    : surname(s), name(n), patronymic(p), address(a) {}

void Person::display() const {
    std::cout << "Прізвище: " << surname << "\n"
              << "Ім'я: " << name << "\n"
              << "По батькові: " << patronymic << "\n"
              << "Адреса: " << address << "\n";
}

std::ostream& operator<<(std::ostream& os, const Person& p) {
    p.display();
    return os;
}