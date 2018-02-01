#include "pch.h"
#include "../UnitTestLearningPart1/Checkout.h"

//class MyAbstract {
//	virtual ~MyAbstract() {};
//	virtual void aMethod() = 0;
//};
//
//class MyMock : public MyAbstract {
//public:
//	MOCK_METHOD0(aMethod, void());
//};

class CheckoutTests : public ::testing::Test {
public:

protected:
	Checkout checkOut;
};

TEST_F(CheckoutTests, CanCalculateTotal) {
	checkOut.addItemPrice("banana", 1.0);
	checkOut.addItems("banana", 2);
	ASSERT_EQ(2, checkOut.calculateTotal());
}

TEST_F(CheckoutTests, GetTotalForMultiple) {
	checkOut.addItemPrice("banana", 1.0);
	checkOut.addItems("banana");
	checkOut.addItemPrice("apple", 2.0);
	checkOut.addItems("apple", 2);
	ASSERT_EQ(5, checkOut.calculateTotal());
}

TEST_F(CheckoutTests, ItemWithNoPriceThrowsException) {
	ASSERT_THROW(checkOut.addItems("orange"), std::invalid_argument);
}