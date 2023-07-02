#include <iostream>
#include <map>
#include <string>
using namespace std;

namespace ariel {

class Money {
public:
  static std::map<std::string, double> rate_map;

private:
  double _amount;
  string _currency;

public:
  Money(double amount, const string &currency);
  static void set_rate(const string &currency, double rate);
  friend Money operator+(const Money &m1, const Money &m2);
  friend ostream &operator<<(ostream &output, const Money &m);
  Money &operator+=(const Money &_other);
  double getAmount() const;
  string getCurrency();
};

Money::Money(double amount, const string &currency) {
  if (ariel::Money::rate_map.count(currency) == 0) {
    throw std::runtime_error("RUNTIME ERROR: Currency \"" + currency +
                             "\" is not set!\n");
  }
  this->_amount = amount;
  this->_currency = currency;
}

void Money::set_rate(const string &currency, double rate) {
  rate_map[currency] = rate;
}

Money operator+(const Money &m1, const Money &m2) {
  return {(m1._amount + (m2._amount * Money::rate_map[m2._currency]) /
                            Money::rate_map[m1._currency]),
          m1._currency};
}

ostream &operator<<(ostream &output, const Money &m) {
  return output << m._amount << " " << m._currency << endl;
}

Money &Money::operator+=(const Money &_other) {
  this->_amount = (*this + _other).getAmount();
  return *this;
}

map<string, double> Money::rate_map{};

double Money::getAmount() const { return this->_amount; }

string Money::getCurrency() { return this->_currency; }

} // namespace ariel
using ariel::Money;

int main() {
  // Set the exchange rates in shekels:
  Money::set_rate("ILS", 1);
  Money::set_rate("USD", 4);
  Money::set_rate("EUR", 6);

  // Define amounts and do calculations:
  Money shekel1(1, "ILS");
  Money dollar3(3, "USD");
  Money sum = shekel1 + dollar3;
  cout << sum << endl;                         // 13 ILS
  cout << (dollar3 + Money(1, "EUR")) << endl; // 4.5 USD
  (sum += Money(2, "EUR")) += Money(0.5, "ILS");
  cout << sum << endl; // 25.5 ILS
  // Money(1."XXX") // throws an exception

  return 0;
}
