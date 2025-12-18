#include "Seller.h"
Seller::Seller() : id(0) {}
Seller::Seller(int i, const std::string& s, const std::string& n,
               const std::string& p, const std::string& a,
               const std::string& acc, const std::vector<std::string>& g)
    : id(i), surname(s), name(n), patronymic(p), address(a), accountNumber(acc), goods(g) {}
void Seller::setId(int i) { id = i; }
int Seller::getId() const { return id; }
void Seller::addGood(const std::string& good) { goods.push_back(good); }
const std::vector<std::string>& Seller::getGoods() const { return goods; }
void Seller::display() const {
    std::cout << "ID: " << id << "\nПрізвище: " << surname << "\nІм'я: " << name
              << "\nПо батькові: " << patronymic << "\nАдреса: " << address
              << "\nНомер рахунку: " << accountNumber << "\nТовари: ";
    for (const auto& g : goods) std::cout << g << ", ";
    std::cout << std::endl;
}
std::ostream& operator<<(std::ostream& os, const Seller& s) {
    s.display();
    return os;
}