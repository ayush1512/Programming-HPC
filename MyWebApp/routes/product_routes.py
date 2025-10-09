from flask import Blueprint, render_template, request, redirect, url_for
from models.product_model import get_all_products, add_product

product_bp = Blueprint("product_bp", __name__)

@product_bp.route("/")
def index():
    products = get_all_products()
    return render_template("index.html", products=products)

@product_bp.route("/add", methods=("GET", "POST"))
def add():
    if request.method == "POST":
        name = request.form["name"]
        price = request.form["price"]
        quantity = request.form["quantity"]
        add_product(name, price, quantity)
        return redirect(url_for("product_bp.index"))
    return render_template("add.html")

# Add edit and delete routes
@product_bp.route("/edit/<int:product_id>", methods=("GET", "POST"))
def edit(product_id):
    from models.product_model import get_product, update_product
    product = get_product(product_id)
    if request.method == "POST":
        name = request.form["name"]
        price = request.form["price"]
        quantity = request.form["quantity"]
        update_product(product_id, name, price, quantity)
        return redirect(url_for("product_bp.index"))
    return render_template("edit.html", product=product)

@product_bp.route("/delete/<int:product_id>", methods=("POST",))
def delete(product_id):
    from models.product_model import delete_product
    delete_product(product_id)
    return redirect(url_for("product_bp.index"))
