#include "stdafx.h"
#include "Checkout.h"


Checkout::Checkout():
	prices(), items()
{
}


Checkout::~Checkout()
{
}

void Checkout::addItemPrice(const string& itemName, const double& price)
{
	prices[itemName] = price;
	items[itemName] = 0;
}

void Checkout::addItems(string itemName, int number)
{
	if (prices.find(itemName) == prices.end()) {
		throw std::invalid_argument("Not added in price sheet");
	}

	items[itemName] += number;
}

double Checkout::calculateTotal()
{
	double total = 0;
	for (auto itemPrice : prices) {
		total += itemPrice.second * items[itemPrice.first];
	}
	return total;
}
