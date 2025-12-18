#pragma once
#include "Person.h"
#include <string>

class Customer : public Person {
private:
    std::string cardNumber;
    double balance;

public:
    Customer();
    Customer(const std::string& surname, const std::string& name,
             const std::string& patronymic, const std::string& address,
             const std::string& card = "", double bal = 0.0);

    void setCardNumber(const std::string& cn) { cardNumber = cn; }
    void setBalance(double b) { balance = b; }

    std::string getCardNumber() const { return cardNumber; }
    double getBalance() const { return balance; }

    void display() const override;
    bool operator==(const Customer& other) const;

    friend std::istream& operator>>(std::istream& in, Customer& c);
};

std::ostream& operator<<(std::ostream& os, const Customer& c);