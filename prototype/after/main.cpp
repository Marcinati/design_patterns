#include <iostream>
#include <memory>
#include <vector>

class ICar {
public:
    virtual std::unique_ptr<ICar> clone() = 0;
    virtual void make() = 0;
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
    void make() override {
        std::cout << "You've made one Citroen car\n";
    }
};

class Opel : public ICar {
public:
    std::unique_ptr<ICar> clone() override { 
        return std::make_unique<Opel>(*this); }
    void make() override {
        std::cout << "You've made one Opel car\n";
    }
};

class Peugeot : public ICar {
public:
    std::unique_ptr<ICar> clone() override { 
        return std::make_unique<Peugeot>(*this); }
    void make() override {
        std::cout << "You've made one Peugeot car\n";
    }
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
        if (choice == 0) {
            break;
        }
        cars.emplace_back(PrototypeFactory::makeCar(choice));
    }

    for (int i = 0; i < cars.size(); ++i) {
        cars[i]->make();
    }
    
    return 0;
}
