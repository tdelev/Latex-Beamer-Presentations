#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Sale {
private:
	double price;
public:
	Sale();
	Sale(double thePrice);
	double getPrice() const;
	void setPrice(double newPrice);
	virtual double bill() const;
	double savings(const Sale& other) const;
	friend bool operator <(const Sale& first, const Sale& second);
};
Sale::Sale() :
	price(0) {
}
Sale::Sale(double thePrice) {
	if (thePrice >= 0)
		price = thePrice;
	else {
		cout << "Error: Cannot have a negative price!\n";
		exit(1);
	}
}
double Sale::bill() const {
	return price;
}
double Sale::getPrice() const {
	return price;
}
void Sale::setPrice(double newPrice) {
	if (newPrice >= 0)
		price = newPrice;
	else {
		cout << "Error: Cannot have a negative price!\n";
		exit(1);
	}
}
double Sale::savings(const Sale& other) const {
	return (bill() - other.bill());
}
bool operator <(const Sale& first, const Sale& second) {
	return (first.bill() < second.bill());
}
class DiscountSale: public Sale {
private:
	double discount;
public:
	DiscountSale();
	DiscountSale(double thePrice, double theDiscount);
	//Discount is expressed as a percent of the price.
	//A negative discount is a price increase.
	double getDiscount() const {
		return discount;
	}
	void setDiscount(double newDiscount) {
		discount = newDiscount;
	}
	double bill() const {
		double fraction = discount / 100;
		return (1 - fraction) * getPrice();
	}
};
DiscountSale::DiscountSale() :
	Sale(), discount(0) {
}
DiscountSale::DiscountSale(double thePrice, double theDiscount) :
	Sale(thePrice), discount(theDiscount) {
}
void compare(const Sale &s1, const Sale &s2) {
	if (s1 < s2) {
		cout << "Prviot e poeftin.\n";
	} else
		cout << "Vtoriot e poeftin.\n";
	cout << "Zastedata e " << fabs(s2.savings(s1)) << " den.\n";
}

int main() {
	//One item at 10.00.
	Sale simple(10.00);
	//One item at 11.00 with a 10% discount.
	DiscountSale discount(11.00, 10);
	compare(simple, discount);
	return 0;
}
