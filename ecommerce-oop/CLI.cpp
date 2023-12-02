#include <iostream>

#include "CLI.h"

using namespace std;

void CLI::run(Inventory& inventory, vector<Order>& orders, Order& currentOrder) {
	while (true) {
		int choice;
		cout << "\n\nChoose the command\n";
		cout << "\t0. Exit\n";
		cout << "\t1. View all products\n";
		cout << "\t2. Add product to inventory\n";
		cout << "\t3. Update product in inventory\n";
		cout << "\t4. Remove product from inventory\n";
		cout << "\t5. Change product quantity in inventory\n";
		cout << "\t6. View list of products that need restocking\n";
		cout << "\t7. Add product to cart\n";
		cout << "\t8. Calculate order total cost\n";
		cout << "\t9. View cart\n";
		cout << "\t10. Make order\n";
		cout << "\t11. View all orders\n>> ";
		cin >> choice;

		if (choice == 0) break;

		switch (choice)
		{
		case 1: {
			viewAllProducts(inventory);
			break;
		}
		case 2: {
			addProductToInventory(inventory);
			break;
		}
		case 3: {
			int productId;
			cout << "Enter product id: ";
			cin >> productId;
			inventory.updateProductDetails(productId);
			break;
		}
		case 4: {
			int productId;
			cout << "Enter product id: ";
			cin >> productId;
			inventory.removeProduct(productId);
			break;
		}
		case 5: {
			int productId;
			int newQuantity;
			cout << "Enter product id: ";
			cin >> productId;
			cout << "Enter new quantity: ";
			cin >> newQuantity;
			inventory.changeProductQuantity(productId, newQuantity);
			break;
		}
		case 6: {
			inventory.showRestockList();
			break;
		}
		case 7: {
			int productId;
			cout << "Enter product id you want to add to cart: ";
			cin >> productId;

			if (productId < 0 || productId >= inventory.getProducts().size()) {
				cout << "Product with such id not found.";
				break;
			}

			currentOrder.addProduct(inventory.getProducts()[productId]);
			break;
		}
		case 8: {
			cout << "Order total cost is: " << currentOrder.calculateTotalCost();
			break;
		}
		case 9: {
			currentOrder.displayOrder();
			break;
		}
		case 10: {
			string customer;
			cout << "Enter your name: ";
			cin >> customer;
			currentOrder.setCustomer(move(customer));
			currentOrder.setTotalCost(currentOrder.calculateTotalCost());
			orders.push_back(move(currentOrder));
			currentOrder = Order();
			break;
		}
		case 11: {
			for (const Order& order : orders) {
				cout << "\nThis is order #" << order.getOrderId() << " for " << order.getCustomer() << endl;
				order.displayOrder();
			}
			break;
		}
		default:
			break;
		}
	}
}

void CLI::addProductToInventory(Inventory& inventory) const {
	string name;
	double price;
	int quantityInStock;

	cout << "Enter name: ";
	cin >> name;
	cout << "Enter price: ";
	cin >> price;
	cout << "Enter quantity in stock: ";
	cin >> quantityInStock;

	string category;
	cout << "Enter category for new product: ";
	cin >> category;

	if (category == "Electronics") {
		string brand;
		string model;
		string powerConsumption;

		cout << "Enter brand: ";
		cin >> brand;
		cout << "Enter model: ";
		cin >> model;
		cout << "Enter power consumption: ";
		cin >> powerConsumption;

		Product* newProduct = new Electronics(move(name), move(price), move(quantityInStock), move(brand), move(model), move(powerConsumption));
		inventory.addProduct(move(newProduct));
	}
	else if (category == "Book") {
		string author;
		string genre;
		string ISBN;

		cout << "Enter author: ";
		cin >> author;
		cout << "Enter genre: ";
		cin >> genre;
		cout << "Enter ISBN: ";
		cin >> ISBN;

		Product* newProduct = new Book(move(name), move(price), move(quantityInStock), move(author), move(genre), move(ISBN));
		inventory.addProduct(move(newProduct));
	}
	else if (category == "Clothing") {
		string size;
		string color;
		string material;

		cout << "Enter size: ";
		cin >> size;
		cout << "Enter color: ";
		cin >> color;
		cout << "Enter material: ";
		cin >> material;

		Product* newProduct = new Clothing(move(name), move(price), move(quantityInStock), move(size), move(color), move(material));
		inventory.addProduct(move(newProduct));
	}
	else {
		cout << "Such category is not implemented yet.";
	}
}

void CLI::viewAllProducts(const Inventory& inventory) const {
	int choice;
	cout << "Do you want to apply filter ?\n\t1. Yes\n\t2. No\n>> ";
	cin >> choice;

	if (choice == 2) { inventory.displayProducts(); return; }

	cout << "Choose category:\n\t1. Electronics\n\t2. Clothing\n\t3. Books\n>> ";
	cin >> choice;

	inventory.filterByCategory(choice);
}
