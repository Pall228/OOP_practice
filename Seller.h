#pragma once
#include <string>
#include <vector>
#include <iostream>
class Seller {
private:
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;
    std::string accountNumber;
    std::vector<std::string> goods;
public:
    Seller();
    Seller(int id, const std::string& surname, const std::string& name,
           const std::string& patronymic, const std::string& address,
           const std::string& accountNumber, const std::vector<std::string>& goods);
    void setId(int id);
    int getId() const;
    void setSurname(const std::string& surname);
    std::string getSurname() const;
    void addGood(const std::string& good);
    const std::vector<std::string>& getGoods() const;
    void display() const;
    friend std::ostream& operator<<(std::ostream& os, const Seller& s);
};