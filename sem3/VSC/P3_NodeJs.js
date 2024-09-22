
/**
 * run using node file.js command
 */

//Write a program to perform addition subtraction multiplication division

var x = 50, y = 10; 
exports.add = function (x, y) { 
    return x + y; 
}; 
  exports.sub = function (x, y) { 
    return x - y; 
}; 
    exports.mult = function (x, y) { 
    return x * y; 
}; 
exports.div = function (x, y) { 
    return x / y; 
};

    
console.log("Addition of 50 and 10 is "+ this.add(x, y)); 
console.log("Subtraction of 50 and 10 is "+ this.sub(x, y));     
console.log("Multiplication of 50 and 10 is "+ this.mult(x, y));     
console.log("Division of 50 and 10 is " + this.div(x, y)); 



//write a program using different string function

let x = "Welcome to GeeksforGeeks ";   
let y = 'Node.js Tutorials';   
let z = ['Geeks', 'for', 'Geeks'];

console.log(x);  
console.log(y);  
console.log("Concat Using (+) :", (x + y));  
console.log("Concat Using Function :", x.concat(y));  
console.log("Split string: ", x.split(' '));  
console.log("Join string: ", z.join(', '));  
console.log("Char At Index 5: ", x.charAt(5));



//Write a program using typeOf function to handle the data

let a = 35;
console.log(typeof a);
a = "GeeksforGeeks";
console.log(typeof a);
a = true;
console.log(typeof a);
a = undefined;
console.log(typeof a);



//Write a program to create a class company and display it's object value

let company = {
  Name: "GeeksforGeeks",
  Address: "Noida",
  Contact: "+919876543210",
  Email: "abc@geeksforgeeks.org"
};
console.log("Information of variable company:", company);
console.log("Type of variable in company:", typeof company);



//Write a program to create server and display name

let http = require("http");
http.createServer(function (req, res) {
    res.writeHead(200, { 'Content-Type': 'text/plain' });
    res.end('Hello Bro \n');    
}).listen(5000,
    () => console.log('Server running at http://127.0.0.1:5000/'));
