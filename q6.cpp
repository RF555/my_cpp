#include <iostream>
#include <map>
using namespace std;
// using namespace ariel;
namespace ariel {

class Money {
public:
  static map<string, double> rate_map;

private:
  double _amount;
  string _currency;

public:
  Money(double amount, string currency);
  static void set_rate(string currency, double rate);
  friend Money operator+(const Money &m1, const Money &m2);
  friend ostream &operator<<(ostream &output, const Money &m);
  Money &operator+=(const Money _other);
};

Money::Money(double amount, string currency) {}

void Money::set_rate(string currency, double rate) {}

Money operator+(const Money &m1, const Money &m2) {}

Money &Money::operator+=(const Money _other) {}

ostream &operator<<(ostream &output, const Money &m) {}

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