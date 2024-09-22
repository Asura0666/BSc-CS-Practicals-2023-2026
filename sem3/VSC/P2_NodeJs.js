
/**
 * 1. create .js file and open it on notepad then paste code
 * 2. Open node cmd
 * 3. then using node file.js command run your file
 */


// write a program to create a server and display hello world

var http = require('http');
http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.end('Hello World!');
}).listen(8080,function(){
    console.log('Server running at http://127.0.0.1:8080');
});


// write a program to create httpservlet request

var http = require('http');
http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write("<p>This is a GET request.</p>");
    res.end();
}).listen(5000,function(){
    console.log('Server running at http://127.0.0.1:5000');
});


// write a program to create httpservlet request and display date and time

var http = require('http');
function myDateTime() {
    return Date(); 
}
http.createServer(function (req, res) {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write("The Date and Time are Currently: " + myDateTime()); 
    res.end();
}).listen(3000,function(){
console.log("Server is running on http://localhost:3000");
});