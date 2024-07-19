-- Table for Products
CREATE TABLE products (
    product_id INT PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    unit_price DECIMAL(10, 2) NOT NULL,
    description TEXT
);

-- Table for Customers
CREATE TABLE customers (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(100) NOT NULL,
    email VARCHAR(100) NOT NULL,
    address VARCHAR(255)
);

-- Table for Orders
CREATE TABLE orders (
    order_id INT PRIMARY KEY,
    order_date DATE NOT NULL,
    customer_id INT,
    total_amount DECIMAL(10, 2) NOT NULL,
    status VARCHAR(50) DEFAULT 'Pending',
    FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
);

-- Table for Order Details (Line Items)
CREATE TABLE order_details (
    order_detail_id INT PRIMARY KEY,
    order_id INT,
    product_id INT,
    quantity INT NOT NULL,
    unit_price DECIMAL(10, 2) NOT NULL,
    total_price DECIMAL(10, 2) NOT NULL,
    FOREIGN KEY (order_id) REFERENCES orders(order_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

-- Table for Payments
CREATE TABLE payments (
    payment_id INT PRIMARY KEY,
    order_id INT,
    payment_date DATE NOT NULL,
    amount DECIMAL(10, 2) NOT NULL,
    payment_method VARCHAR(50),
    FOREIGN KEY (order_id) REFERENCES orders(order_id)
);

-- Sample data insertion (optional)
INSERT INTO products (product_id, product_name, unit_price, description)
VALUES
    (1, 'Product A', 25.00, 'Description of Product A'),
    (2, 'Product B', 35.00, 'Description of Product B');

INSERT INTO customers (customer_id, customer_name, email, address)
VALUES
    (1, 'John Doe', 'john.doe@example.com', '123 Main St, Anytown, USA'),
    (2, 'Jane Smith', 'jane.smith@example.com', '456 Elm St, Othertown, USA');

INSERT INTO orders (order_id, order_date, customer_id, total_amount, status)
VALUES
    (1, '2024-07-19', 1, 60.00, 'Pending'),
    (2, '2024-07-19', 2, 70.00, 'Pending');

INSERT INTO order_details (order_detail_id, order_id, product_id, quantity, unit_price, total_price)
VALUES
    (1, 1, 1, 2, 25.00, 50.00),
    (2, 1, 2, 1, 35.00, 35.00),
    (3, 2, 2, 2, 35.00, 70.00);

INSERT INTO payments (payment_id, order_id, payment_date, amount, payment_method)
VALUES
    (1, 1, '2024-07-20', 60.00, 'Credit Card'),
    (2, 2, '2024-07-20', 70.00, 'PayPal');
