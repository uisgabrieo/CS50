from cs50 import SQL
from flask import Flask, render_template, redirect, request

app = Flask(__name__)
db = SQL("sqlite:///froshims.db")

SPORTS = ["Basketball", "Soccer", "Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports=SPORTS)

@app.route("/register", methods=["POST"])
def regsiter():
    name = request.form.get("name")
    sport = request.form.get("sport")

    if (not name or sport not in SPORTS):
        return render_template("failuer.html")

    db.execute("INSERT INTO registrants (name, sport) VALUES (?, ?)", name , sport)

    return redirect("/registrants")
    # if (not request.form.get("name") or request.form.get("sport") not in SPORTS):
    # if (not request.form.get("name")):
    #     return render_template("failuer.html")
    # for sport in request.form.getlist("sport"):
    #     if (sport not in SPORTS):
    #         return render_template("failuer.html")
    # return render_template("success.html")

@app.route("/deregister", methods=["POST"])
def deregister():

    id = request.form.get("id")
    if (id):
        db.execute("DELETE FROM registrants WHERE id = ?", id)
    return redirect("/registrants")

@app.route("/registrants")
def regsitrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)
