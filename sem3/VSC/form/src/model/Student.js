import mongoose from "mongoose";
import bcrypt from "bcrypt";
import passportLocalMongoose from "passport-local-mongoose";

const { Schema } = mongoose;

function calculateAge(dob) {
  const ageDifMS = Date.now() - dob.getTime();
  const ageDate = new Date(ageDifMS);
  return Math.abs(ageDate.getUTCFullYear() - 1970);
}

const StudentSchema = new Schema({
  firstName: {
    type: String,
    required: true,
  },
  lastName: {
    type: String,
    required: true,
  },
  dob: {
    type: Date,
    required: true,
  },
  age: {
    type: Number,
  },
  email: {
    type: String,
    required: true,
    unique: true,
  },
  password: {
    type: String,
    required: true,
  },
});

StudentSchema.plugin(passportLocalMongoose, { usernameField: "email" });

StudentSchema.pre("save", function (next) {
  const student = this;

  if (student.isNew || student.isModified("dob")) {
    student.age = calculateAge(student.dob);
  }

  // if (!student.isModified("password")) {
  //   bcrypt.hash(student.password, 10, function (err, hash) {
  //     if (err) return next(err);
  //     student.password = hash;
  //     next();
  //   });
  // }

  next();
});

export default mongoose.model("Student", StudentSchema);
