#pragma once
#include "Person.h"
#include <vector>
#include <string>

class Seller : public Person {
private:
    int id;
    std::string accountNumber;
    std::vector<std::string> goods;

public:
    Seller();
    Seller(int id, const std::string& surname, const std::string& name,
           const std::string& patronymic, const std::string& address,
           const std::string& account, const std::vector<std::string>& g = {});

    void setId(int i) { id = i; }
    int getId() const { return id; }
    void setAccountNumber(const std::string& acc) { accountNumber = acc; }
    std::string getAccountNumber() const { return accountNumber; }
    void addGood(const std::string& good) { goods.push_back(good); }
    const std::vector<std::string>& getGoods() const { return goods; }

    void display() const override;
};

std::ostream& operator<<(std::ostream& os, const Seller& s);