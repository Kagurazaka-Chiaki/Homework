


#include <string_view>

#include <iostream>
#include <string>

class Base {
  protected:
    int m_value = 0;

  public:
    Base(int value)
        : m_value{value} {
    }

    virtual ~Base() = default;
};

class Derived : public Base {
  protected:
    std::string m_name = "Derived";

  public:
    Derived(int value, std::string_view name)
        : Base{value}, m_name{name} {
    }

    std::string const &getName() const { return m_name; }
};

Base *getObject(bool returnDerived) {
    if (returnDerived) {
        return new Derived{1, "Apple"};

    } else {
        return new Base{2};
    }
}

int main() {
    Base *b1{getObject(true)};

    // how do we print the Derived object's name here, having only a Base pointer?

    Derived *d1{dynamic_cast<Derived *>(b1)}; // use dynamic cast to convert Base pointer into Derived pointer

    std::cout << "The name of the Derived is: " << d1->getName() << '\n';

    delete b1;

    Base *b2{getObject(false)};

    Derived *d2{dynamic_cast<Derived *>(b2)}; // use dynamic cast to convert Base pointer into Derived pointer
    if (d2) {
        std::cout << "The name of the Derived is: " << d2->getName() << '\n';
    } else {
        std::cout << "b2 is not actually a Derived object\n";
    }

    delete b2;

    return 0;
}