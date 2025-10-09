import sqlite3

def get_db_connection():
    conn = sqlite3.connect("products.db")
    conn.row_factory = sqlite3.Row
    return conn

def get_all_products():
    conn = get_db_connection()
    products = conn.execute("SELECT * FROM product").fetchall()
    conn.close()
    return products

def add_product(name, price, quantity):
    conn = get_db_connection()
    conn.execute("INSERT INTO product (name, price, quantity) VALUES (?, ?, ?)",
                 (name, price, quantity))
    conn.commit()
    conn.close()

def get_product(product_id):
    conn = get_db_connection()
    product = conn.execute("SELECT * FROM product WHERE id = ?", (product_id,)).fetchone()
    conn.close()
    return product

def update_product(product_id, name, price, quantity):
    conn = get_db_connection()
    conn.execute("UPDATE product SET name = ?, price = ?, quantity = ? WHERE id = ?",
                 (name, price, quantity, product_id))
    conn.commit()
    conn.close()

def delete_product(product_id):
    conn = get_db_connection()
    conn.execute("DELETE FROM product WHERE id = ?", (product_id,))
    conn.commit()
    conn.close()

