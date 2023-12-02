#pragma once

#include <vector>

#include "Order.h"
#include "Inventory.h"

class ICLI {
	virtual void run(Inventory& inventory, vector<Order>& orders, Order& currentOrder) = 0;
};

class CLI : public ICLI {
	void addProductToInventory(Inventory& inventory) const;
public:
	void run(Inventory& inventory, vector<Order>& orders, Order& currentOrder) override;
};
