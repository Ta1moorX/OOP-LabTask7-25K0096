#include <iostream>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;
public:
    Currency(double a, string code, string symbol, double rate)
        : amount(a), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() { return amount * exchangeRate; }

    void convertTo(Currency& target) {
        double inBase = convertToBase();
        double result = inBase / target.exchangeRate;
        cout << currencySymbol << amount << " " << currencyCode
             << " = " << target.currencySymbol << result
             << " " << target.currencyCode << endl;
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode
             << " | Amount: " << currencySymbol << amount
             << " | Rate to USD: " << exchangeRate << endl;
    }
};

class Dollar : public Currency {
public:
    Dollar(double a) : Currency(a, "USD", "$", 1.0) {}
    double convertToBase() override { return amount; }
    void displayCurrency() override {
        cout << "[USD] Amount: $" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double a) : Currency(a, "EUR", "€", 1.08) {}
    double convertToBase() override { return amount * 1.08; }
    void displayCurrency() override {
        cout << "[EUR] Amount: €" << amount << " | 1 EUR = $1.08" << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double a) : Currency(a, "PKR", "Rs.", 0.0036) {}
    double convertToBase() override { return amount * 0.0036; }
    void displayCurrency() override {
        cout << "[PKR] Amount: Rs." << amount << " | 1 PKR = $0.0036" << endl;
    }
};

int main() {
    Dollar d(100);
    Euro   e(50);
    Rupee  r(10000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    cout << endl;
    e.convertTo(d);
    r.convertTo(e);
    d.convertTo(r);

    return 0;
}