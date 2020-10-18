#include <iostream>
#include <memory>
#include <vector>

class ICar {
public:
    virtual void body() = 0;
protected:
    virtual void chassis() = 0;
};

class Citroen : public ICar {
public:
    void body() override {
        std::cout << "You've made one Citroen car\n";
    }
protected:
    void chassis() override {}
};

class Opel : public ICar {
public:
    void body() override {
        std::cout << "You've made one Opel car\n";
    }
protected:
    void chassis() override {}
};

class Peugeot : public ICar {
public:
    void body() override {
        std::cout << "You've made one Peugeot car\n";
    }
protected:
    void chassis() override {}
};

int main() {
    std::vector<std::unique_ptr<ICar>> cars{};
    int choice;

    while (true) {
        std::cout << "Citroen(1) Opel(2) Peugeot(3) Results(0): ";
        std::cin >> choice;
        if (choice == 0) {
            break;
        } else if (choice == 1) {
            cars.emplace_back(std::make_unique<Citroen>());
        } else if (choice == 2) {
            cars.emplace_back(std::make_unique<Opel>());
        } else {
            cars.emplace_back(std::make_unique<Peugeot>());
        }
    }

    for (int i = 0; i < cars.size(); i++) {
        cars[i]->body();
    }

    return 0;
}
