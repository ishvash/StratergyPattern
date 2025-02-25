#include <iostream>
#include <memory>

// Step 1: Define the Strategy Interface
class PaymentStrategy {
public:
    virtual void pay(int amount) = 0;
    //virtual ~PaymentStrategy() {}
};

// Step 2: Implement Concrete Strategies
class CreditCardPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using Credit Card.\n";
    }
};

class PayPalPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using PayPal.\n";
    }
};

class UPIPayment : public PaymentStrategy {
public:
    void pay(int amount) override {
        std::cout << "Paid $" << amount << " using UPI.\n";
    }
};

// Step 3: Create a Context Class
class PaymentContext {
private:
    std::unique_ptr<PaymentStrategy> strategy;
public:
    void setStrategy(std::unique_ptr<PaymentStrategy> s) {
        strategy = std::move(s);
    }
    
    void executePayment(int amount) {
        if (strategy) {
            strategy->pay(amount);
        } else {
            std::cout << "No payment strategy set!\n";
        }
    }
};

// Step 4: Client Code
int main() {
    PaymentContext context;
    
    // Using Credit Card Payment
    context.setStrategy(std::make_unique<CreditCardPayment>());
    context.executePayment(500);

    // Using PayPal Payment
    context.setStrategy(std::make_unique<PayPalPayment>());
    context.executePayment(1000);

    // Using UPI Payment
    context.setStrategy(std::make_unique<UPIPayment>());
    context.executePayment(750);

    return 0;
}
