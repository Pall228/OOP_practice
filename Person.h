#pragma once
#include <string>
#include <iostream>

class Person {
protected:
    std::string surname;
    std::string name;
    std::string patronymic;
    std::string address;

public:
    Person();
    Person(const std::string& surname, const std::string& name,
           const std::string& patronymic, const std::string& address);

    void setSurname(const std::string& s) { surname = s; }
    void setName(const std::string& n) { name = n; }
    void setPatronymic(const std::string& p) { patronymic = p; }
    void setAddress(const std::string& a) { address = a; }

    std::string getSurname() const { return surname; }
    std::string getName() const { return name; }
    std::string getPatronymic() const { return patronymic; }
    std::string getAddress() const { return address; }

    virtual void display() const;
    virtual ~Person() = default;
};

std::ostream& operator<<(std::ostream& os, const Person& p);