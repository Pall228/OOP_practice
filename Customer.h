#pragma once
#include <string>
class Customer {
private:
    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;
    std::string creditCardNumber;
    double balance;
public:
    Customer();
    Customer(int id, const std::string& surname, const std::string& name,
             const std::string& patronymic, const std::string& address,
             const std::string& creditCardNumber, double balance);
    Customer(const Customer& other);
    ~Customer();
    int getId() const;
    std::string getSurname() const;
    std::string getName() const;
    std::string getPatronymic() const;
    std::string getAddress() const;
    std::string getCreditCardNumber() const;
    double getBalance() const;
    void setId(int id);
    void setSurname(const std::string& surname);
    void setName(const std::string& name);
    void setPatronymic(const std::string& patronymic);
    void setAddress(const std::string& address);
    void setCreditCardNumber(const std::string& creditCardNumber);
    void setBalance(double balance);
    void display() const;
};