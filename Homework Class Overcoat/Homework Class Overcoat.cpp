#include <iostream>
#include <string>

class Overcoat {
private:
    std::string type;  
    double price;   

public:
    Overcoat(const std::string& type, double price) : type(type), price(price) {}

    bool operator==(const Overcoat& other) const {
        return this->type == other.type;
    }

    Overcoat& operator=(const Overcoat& other) {
        if (this == &other) {
            return *this; 
        }
        this->type = other.type;
        this->price = other.price;
        return *this;
    }

    bool operator>(const Overcoat& other) const {
        if (this->type == other.type) {
            return this->price > other.price;
        }
        else {
            std::cerr << "Одежда разных типов, невозможно сравнить по цене." << std::endl;
            return false;
        }
    }

    void display() const {
        std::cout << "Тип: " << type << ", Цена: " << price << std::endl;
    }
};

int main() {
    Overcoat coat1("Пальто", 300.0);
    Overcoat coat2("Пальто", 450.0);
    Overcoat coat3("Куртка", 200.0);

    if (coat1 == coat2) 
    {
        std::cout << "Одежда одинакового типа." << std::endl;
    }
    else 
    {
        std::cout << "Одежда разных типов." << std::endl;
    }

    coat3 = coat1;
    coat3.display();

    if (coat2 > coat1) 
    {
        std::cout << "coat2 дороже coat1." << std::endl;
    }
    else 
    {
        std::cout << "coat1 дороже или равен по цене coat2." << std::endl;
    }
}
