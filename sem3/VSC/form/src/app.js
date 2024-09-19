import express from "express";
import mongoose from "mongoose";
import passport from "passport";
import bodyParser from "body-parser";
import LocalStrategy from "passport-local";
import Student from "./model/Student.js";
import session from "express-session";
import path from "path";
import { fileURLToPath } from "url";
import flash from "connect-flash";

const app = express();
const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

mongoose
  .connect(
    "mongodb+srv://admin:lande777@cluster0.r2vj5qc.mongodb.net/college",
    {
      useNewUrlParser: true,
      useUnifiedTopology: true,
    }
  )
  .then(() => {
    console.log("DB Connected");
  })
  .catch(() => {
    console.log("DB NOt Connected");
  });

app.set("view engine", "ejs");
app.set("views", path.join(__dirname, "views"));
app.use(bodyParser.urlencoded({ extended: true }));
app.use(
  session({
    secret: "Rusty is a dog",
    resave: false,
    saveUninitialized: false,
  })
);

app.use(flash());

app.use(passport.initialize());
app.use(passport.session());

app.use((req, res, next) => {
  res.locals.messages = req.flash();
  res.locals.user = req.user;
  console.log("user", req.locals.user);
  next();
});

app.use(express.static(path.join(__dirname, "styles")));


passport.use(new LocalStrategy(Student.authenticate()));
passport.serializeUser(Student.serializeUser());
passport.deserializeUser(Student.deserializeUser());

/**
 * Routes
 */

app.get("/", function (req, res) {
  res.render("home");
});

app.get("/secret", isLoggedIn, function (req, res) {
  res.render("secret");
});

app.get("/register", function (req, res) {
  res.render("register");
});

app.post("/register", async (req, res) => {
  try {
    const { email, firstName, lastName, dob, password } = req.body;

    const student = await Student.findOne({ email });

    if (student)
      return res.status(400).json({ message: "Student already exists" });

    const createStudent = new Student({
      firstName,
      lastName,
      email,
      dob: new Date(dob),
      password,
    });

    await Student.register(createStudent, password);

    res.status(200).json({
      message: "Student registered successfully",
      data: createStudent,
    });
  } catch (error) {
    res.status(400).json({ error: error.message });
  }
});

app.get("/login", function (req, res) {
  res.render("login");
});

app.post("/login", async (req, res) => {
  try {
    const { email, password } = req.body;

    const student = await Student.findOne({ email });

    if (!student) {
      req.flash("error", "Student does not exist");
      return res.redirect("/login");
    }

    // Use passport to authenticate
    req.login(student, (err) => {
      if (err) {
        req.flash("error", "Something went wrong");
        return res.redirect("/login");
      }

      student.authenticate(password, (err, user) => {
        if (err || !user) {
          req.flash("error", "Invalid password");
          return res.redirect("/login");
        }
        console.log("req.user after login:", req.user); // Debugging line
        res.locals.user = req.user;

        req.flash("success", "Logged in successfully");
        res.redirect("/secret");
      });
    });
  } catch (error) {
    req.flash("error", error.message);
    res.redirect("/login");
  }
});

app.get("/logout", function (req, res) {
  req.logout(function (err) {
    if (err) {
      return next(err);
    }
    res.redirect("/");
  });
});

function isLoggedIn(req, res, next) {
  if (req.isAuthenticated()) return next();
  res.redirect("/login");
}

const port = process.env.PORT || 3000;
app.listen(port, function () {
  console.log("Server Has Started!");
});
