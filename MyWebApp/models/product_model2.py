import mysql.connector as ms
db = ms.connect(user='root',host='localhost',database='mydb',password='MySql@123',autocommit=True)
cursor = db.cursor()

def get_all_products():
    cursor.execute("SELECT * FROM product")
    columns = [desc[0] for desc in cursor.description]
    products = [dict(zip(columns, row)) for row in cursor.fetchall()]
    return products

def add_product(name, price, quantity):
    cursor.execute("INSERT INTO product (name, price, quantity) VALUES (%s, %s, %s)", (name, float(price), quantity))

def get_product(product_id):
    cursor.execute("SELECT * FROM product WHERE id = %s", (product_id,))
    row = cursor.fetchone()
    if row:
        columns = [desc[0] for desc in cursor.description]
        return dict(zip(columns, row))
    return None
    

def update_product(product_id, name, price, quantity):
    cursor.execute("UPDATE product SET name=%s, price=%s, quantity=%s WHERE id=%s", (name, price, quantity, product_id))

def delete_product(product_id):
    cursor.execute("DELETE FROM product WHERE id = %s", (product_id,))


