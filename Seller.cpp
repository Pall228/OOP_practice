#include "Seller.h"
#include <iostream>

Seller::Seller() : id(0) {}

Seller::Seller(int i, const std::string& s, const std::string& n,
               const std::string& p, const std::string& a,
               const std::string& acc, const std::vector<std::string>& g)
    : Person(s, n, p, a), id(i), accountNumber(acc), goods(g) {}

void Seller::display() const {
    Person::display();
    std::cout << "ID: " << id << "\n"
              << "Номер рахунку: " << accountNumber << "\n"
              << "Товари: ";
    if (goods.empty()) {
        std::cout << "немає";
    } else {
        for (size_t i = 0; i < goods.size(); ++i) {
            std::cout << goods[i];
            if (i < goods.size() - 1) std::cout << ", ";
        }
    }
    std::cout << "\n";
}

std::ostream& operator<<(std::ostream& os, const Seller& s) {
    s.display();
    return os;
}