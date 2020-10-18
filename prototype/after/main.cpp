#include <iostream>
#include <memory>
#include <vector>

class ICar {
public:
    virtual std::unique_ptr<ICar> clone() = 0;
    virtual void body() = 0;
protected:
    virtual void chassis() = 0;
};

class PrototypeFactory {
public:
    static std::unique_ptr<ICar> makeCar(int choice);
protected:
    static std::unique_ptr<ICar> s_prototypes[4];
};

class Citroen : public ICar {
public:
    std::unique_ptr<ICar> clone() override { 
        return std::make_unique<Citroen>(*this); }
    void body() override {
        std::cout << "You've made one Citroen car\n";
    }
protected:
    void chassis() override {}
};

class Opel : public ICar {
public:
    std::unique_ptr<ICar> clone() override { 
        return std::make_unique<Opel>(*this); }
    void body() override {
        std::cout << "You've made one Opel car\n";
    }
protected:
    void chassis() override {}
};

class Peugeot : public ICar {
public:
    std::unique_ptr<ICar> clone() override { 
        return std::make_unique<Peugeot>(*this); }
    void body() override {
        std::cout << "You've made one Peugeot car\n";
    }
protected:
    void chassis() override {}
};

std::unique_ptr<ICar> PrototypeFactory::s_prototypes[] = {
    0, std::make_unique<Citroen>(), std::make_unique<Opel>(), std::make_unique<Peugeot>()};

std::unique_ptr<ICar> PrototypeFactory::makeCar(int choice) {
    return s_prototypes[choice]->clone();
}

int main() {
    std::vector<std::unique_ptr<ICar>> cars;
    int choice;

    while (true) {
        std::cout << "Citroen(1) Opel(2) Peugeot(3) Results(0): ";
        std::cin >> choice;
        if (choice == 0)
            break;
        cars.emplace_back(
            PrototypeFactory::makeCar(choice));
    }

    for (int i = 0; i < cars.size(); ++i) {
        cars[i]->body();
    }
    
    return 0;
}
