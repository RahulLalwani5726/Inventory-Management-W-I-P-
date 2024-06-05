# Inventory Management System

This is a simple inventory management system implemented in C++. It allows users to manage products in an inventory, including adding new products, updating existing ones, purchasing more of a product, selling products, and viewing product details.

## Features

1. **Add New Product**: Add a new product to the inventory with its details.
2. **Show Product Detail**: View detailed information about a specific product.
3. **Sell Available Product**: Record the sale of a product and update the inventory accordingly.
4. **Purchase Available Product**: Record the purchase of additional stock for an existing product.
5. **Update Product**: Update the details of an existing product.
6. **Show All Stock Detail**: View details of all products in the inventory.

## Class and Functions

### Class `inventory`

The `inventory` class stores the details of a product and provides methods to display and manage these details.

**Private Members:**
- `string product`: Name of the product.
- `string product_type`: Type of the product.
- `long long int Quantity`: Quantity available in inventory.
- `long double Purchase_price`: Price at which the product was purchased.
- `long long int Purchase_itme`: Quantity of the product purchased.
- `long long int sell_itme`: Quantity of the product sold.
- `long double Sell_price`: Price at which the product is sold.
- `int product_key`: Unique key for the product.
- `long double p_l`: Profit or loss for the product.

**Friend Functions:**
- `void update(inventory &o)`: Update details of a single product.
- `void update(inventory o[], string name, string type, int len)`: Update details of a product by name and type.
- `void Purchase(inventory o[], string name, string type, int len)`: Purchase additional stock for an existing product.
- `void sell(inventory o[], string name, string type, int len)`: Record the sale of a product.
- `void al_show(inventory o[], int len)`: Display details of all products in the inventory.
- `void sh(inventory o[], string t, string n, int l)`:

Display details of a product by name and type.

**Public Methods:**
- `void store_product()`: Store details of a new product.
- `void Show_item()`: Display details of the product.

### Friend Functions

**`void update(inventory &o)`**
- Update details of a single product.

**`void update(inventory o[], string name, string type, int len)`**
- Update details of a product by name and type.

**`void Purchase(inventory o[], string name, string type, int len)`**
- Purchase additional stock for an existing product.

**`void sell(inventory o[], string name, string type, int len)`**
- Record the sale of a product.

**`void al_show(inventory o[], int len)`**
- Display details of all products in the inventory.

**`void sh(inventory o[], string t, string n, int l)`**
- Display details of a product by name and type.

## Usage

### Adding a New Product
To add a new product, select the option to purchase a new product and provide the necessary details such as product type, name, purchase price, purchase quantity, and sell price.

### Viewing Product Details
You can view product details by either providing the product key or the product name and type.

### Updating a Product
You can update the details of a product either by its key or by its name and type.

### Purchasing More of a Product
To purchase more of an existing product, provide the product name and type, and then enter the purchase quantity and price.

### Selling a Product
To sell a product, provide the product name and type, and then enter the quantity to be sold and the selling price.

### Viewing All Stock Details
You can view the details of all products in the inventory, including total stock, purchase price, sell price, and profit/loss.

## Compilation and Execution

To compile and run the program, use the following commands:

```sh
g++ -o inventory_management inventory_management.cpp
./inventory_management
```

## Example

Below is an example of how to interact with the inventory management system:

1. Run the program.
2. Select the option to purchase a new product.
3. Enter the product details as prompted.
4. View the product details using the product key or name and type.
5. Update product details if necessary.
6. Purchase more of the product or sell the product as required.
7. View the details of all products to see the current inventory status.

## Notes

- Ensure that product keys are unique for each product.
- When updating or selling a product, ensure the correct product key or name and type are provided.
- The system will prompt for necessary actions and display messages if the product is not found.

Enjoy managing your inventory with this simple and efficient system!
