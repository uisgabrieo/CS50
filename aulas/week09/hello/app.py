from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def hello_word():
    if (request.method == "POST"):
        name = request.form.get("name")
        return render_template("greet.html", name=name)
    return render_template("index.html")
#    name = request.args.get("name", None)
#    return render_template("index.html", name=name)
# def hello_word():
#     if "name" in request.args:
#         name = request.args["name"]
#     else:
#         name = "None"
#     return render_template("index.html", placeholder=name)


# @app.route("/greet", methods=["POST"])
# def greet():
#     name = request.form.get("name", "Word")
#     return render_template("greet.html", name=name)
