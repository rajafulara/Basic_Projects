-- Create a table for departments
CREATE TABLE departments (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(100) NOT NULL
);

-- Insert sample departments
INSERT INTO departments (dept_id, dept_name)
VALUES
    (1, 'HR'),
    (2, 'Finance'),
    (3, 'IT');

-- Create a table for employees
CREATE TABLE employees (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(100) NOT NULL,
    emp_dept_id INT,
    emp_salary DECIMAL(10, 2),
    FOREIGN KEY (emp_dept_id) REFERENCES departments(dept_id)
);

-- Insert sample employees
INSERT INTO employees (emp_id, emp_name, emp_dept_id, emp_salary)
VALUES
    (1001, 'John Doe', 1, 50000.00),
    (1002, 'Jane Smith', 2, 60000.00),
    (1003, 'Michael Brown', 3, 55000.00);

-- Query to retrieve all employees with department names
SELECT e.emp_id, e.emp_name, d.dept_name, e.emp_salary
FROM employees e
JOIN departments d ON e.emp_dept_id = d.dept_id;

-- Query to update an employee's salary
UPDATE employees
SET emp_salary = 65000.00
WHERE emp_id = 1002;

-- Query to delete an employee
DELETE FROM employees
WHERE emp_id = 1001;

-- Query to retrieve all employees after updates and deletions
SELECT e.emp_id, e.emp_name, d.dept_name, e.emp_salary
FROM employees e
JOIN departments d ON e.emp_dept_id = d.dept_id;
