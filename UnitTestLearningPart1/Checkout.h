#pragma once

#include <string>
#include <map>

using namespace std;
class Checkout
{
public:
	Checkout();
	virtual ~Checkout();

	void addItemPrice(const string& itemName, const double& price);
	void addItems(string itemName, int number = 1);
	double calculateTotal();

private:
	map<string, double> prices;
	map<string, int> items;
};

