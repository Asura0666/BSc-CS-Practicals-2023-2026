/**
 * 1. create folder and open it in VS code
 * 2. open terminal then type ( npm init -y )
 * 3. install express using ( npm i express )
 * 4. inside VS code terminal you can run your file using follwing command ( node file.js )
 */

//write a program to print hello world

var express = require("express");
var app = express();
app.get('/', function(req, res) {
    res.send("Hello World");
});
app.listen(3000, function() {
    console.log("Server is running on http://localhost:3000");
});



//write a program to display current time
//use nodemon for run

var express = require("express");
var app = express();
app.get('/',function(req,res,next){
console.log("a new request recieved at:"+Date.now());
next();
});
app.get('/', function(req, res) {
res.send("Hello! The request was logged in the console.");
});
app.listen(5000,function(){
    console.log("server is running on http://localhost:5000");
});   


//Write a program to create a route and display hello world

var express = require("express");
var app = express();
app.get('/hello', function(req, res) {
    res.send("Hello World");
});
app.listen(3000, function() {
    console.log("Server is running on http://localhost:3000/hello");
});



//Write a program to create function and route

var express = require('express');
var app = express();
app.route('/things')
    .get(function(req, res) {
        res.send('GET route on things.');
    })
    .post(function(req, res) {
        res.send('POST route on things.');
    });
app.listen(3000, function() {
    console.log('Server is running on http://localhost:3000/things');
});



//Write a program to create route and send parameters

var express = require("express");
var app = express();
app.get('/user/:id/:name', function(req, res) {
    var id = req.params.id;
    var name = req.params.name;
    res.send(`User ID: ${id}, Name: ${name}`);
});
app.listen(3000, function() {
    console.log("Server is running on http://localhost:3000/user");
});

//after user add your id/name


//Write a program to create rout and match the parameter pattern

var express = require("express");
var app = express();
app.get('/user/:id(\\d+)/:name([A-Za-z]+)', function(req, res) {

    var id = req.params.id;
    var name = req.params.name;
    res.send(`User ID: ${id}, Name: ${name}`);
});
app.use('*', function(req, res) {
    res.status(404).send("Sorry, this is an invalid URL.");
});
app.listen(3000, function() {
    console.log("Server is running on http://localhost:3000/user");
});


//after user add your id/name
// id we enter wrong patten then invalid URL