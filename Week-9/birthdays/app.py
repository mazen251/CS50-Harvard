from cs50 import SQL
from flask import Flask, request, redirect, render_template

app = Flask(__name__)
app.config["TEMPLATES_AUTO_RELOAD"] = True

database = SQL("sqlite:///birthdays.db") # /// not a typo that's how it is written

@app.after_request
def no_cache(response):
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = "0"
    response.headers["Pragma"] = "no-cache"
    return response

@app.route("/", methods=["GET", "POST"])
def home():
    if request.method == "POST":
        fname = request.form.get("first_name")
        lname = request.form.get("last_name")
        day = request.form.get("day")
        month = request.form.get("month")
        year = request.form.get("year")

        database.execute("INSERT INTO birthdays (first_name, last_name, day, month, year) VALUES (?, ?, ?, ?, ?)", fname, lname, day, month, year)
        # ? to prevent injection attacks from the client side
        return redirect("/")

    else:
        entries = database.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=entries)




