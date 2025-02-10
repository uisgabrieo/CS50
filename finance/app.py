import os

from _sqlite3 import OperationalError
from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    cash = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
    rows = db.execute("SELECT * FROM purchases WHERE user_id = ?", session["user_id"])

    cash = cash[0]["cash"]
    sum_total = cash

    for row in rows:
        row["total"] = row["price"] * row["shares"]

        sum_total += row["total"]

    return render_template("index.html", rows=rows, cash=cash, sum_total=sum_total)

@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    symbol = request.form.get("symbol")
    shares = request.form.get("shares")

    if (request.method == "POST"):
        if (not shares):
            return apology("must provide number of shares", 403)

        try:
            shares = int(shares)

        except ValueError:
            return apology("must provide number of shares", 403)

        quote = lookup(symbol)

        if (not quote):
            return apology("symbol not found", 403)

        total_price = quote["price"] * shares

        user = db.execute("SELECT cash FROM users WHERE id = ?", session["user_id"])
        cash = user[0]["cash"]
        current_balance = cash - total_price

        if (current_balance < 0):
            return apology("insufficient balance", 403)

        db.execute("UPDATE users SET cash = ? WHERE id = ?", current_balance, session["user_id"])

        db.execute(
            "INSERT INTO purchases (user_id, stock_symbol, shares, price) VALUES (?, ?, ?, ?)",
            session["user_id"], quote["symbol"], shares, quote["price"]
        )

        return redirect("/")
    return render_template("buy.html")


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    return apology("TODO")


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""

    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":
        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 403)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 403)

        # Query database for username
        rows = db.execute(
            "SELECT * FROM users WHERE username = ?", request.form.get(
                "username")
        )

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(
            rows[0]["hash"], request.form.get("password")
        ):
            return apology("invalid username and/or password", 403)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    symbol = request.form.get("symbol")

    if (request.method == "POST"):
        quote = lookup(symbol)

        if (not quote):
            return apology("symbol not found", 403)

        quote["price"] = usd(quote["price"])

        return render_template("quote.html", quote=quote)
    return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    session.clear()

    username = request.form.get("username")
    password = request.form.get("password")
    confirm_pass = request.form.get("confirmation_pass")

    if (request.method == "POST"):
        if (not username):
            return apology("must provide username", 403)

        elif (not password):
            return apology("must provide password", 403)

        elif (not confirm_pass):
            return apology("must provide confirmation password", 403)

        elif (password != confirm_pass):
            return apology("The passwords must match", 403)

        try:
            rows = db.execute(
                "SELECT * FROM users WHERE username = ?", username
            )

            if (len(rows) != 0):
                return apology("username is already taken", 403)

            db.execute(
                "INSERT INTO users (username, hash) VALUES (?, ?)",
                username, generate_password_hash(password)
            )

            return redirect("/")

        except OperationalError:
            return apology("error insert", 409)

    return render_template("register.html")


@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    return apology("TODO")
