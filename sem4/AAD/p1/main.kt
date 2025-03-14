A.A.D. Practical 1

Q1. If Else Condition as Expression.

Code:
fun main(args: Array<String>) {
    var n1=10
    var n2=20

    var r=if(n1>n2){
        "$n1 is greater than $n2"
    }
    else{
        "$n2 is greater than $n1"
    }

    print(r)
}

 
Q2. Nested If as Expression.

Code:
fun main(args: Array<String>) {
    var n1 = 25
    var n2 = 20
    var n3 = 30

    var r = if (n1 > n2) {
        var max = if (n1 > n3) {
            n1
        } else {
            n3
        }
        "body of if " + max
    } else if (n2 > n3) {
        "body of if else " + n2
    } else {
        "body of else " + n3
    }
    print(r)
}

Q3. Types of Loops.

a. For Loop.
Code:
fun main(args: Array<String>) {
    val marks = arrayOf(10, 20, 30, 40, 50)
    for (i in marks) {
        println(i)
    }
}

 
b. While Loop.

Code:
fun main(args: Array<String>) {
    var i:Int=1
    while(i<=5){
        println(i)
        i++
    }
}

 
c. Do While Loop.

Code:
fun main(args: Array<String>) {
    var i: Int = 1
    do {
        println(i)
        i++
    } while (i <= 5)
}

 
Q4. Primary Constructor.

Code:
class myClass(val name: String, var id: Int) {
}

fun main(args: Array<String>) {
    val obj = myClass("Ashu", 101)
    println("Name= ${obj.name}")
    println("Id= ${obj.id}")
}


 
Q5. Secondary Constructor.

Code:
class myClass {
    constructor(name:String, id:Int):this(name,id,"mypassword"){
        println("this executes next")
        println("Name= ${name}")
        println("Id= ${id}")
    }
    constructor(name:String, id:Int,pass:String){
        println("this executes first")
        println("Name= ${name}")
        println("Id= ${id}")
        println("Password= ${pass}\n")
    }
}
fun main(args: Array<String>) {
    var obj=myClass("Ashu",101)
}
 
 
Q6. Inheritance.

Code:
open class Employee(name: String, age: Int, salary: Float) {
    init {
        println("Name is ${name}.")
        println("Age is ${age}.")
        println("Salary is ${salary}.")
    }
}

class Programmer(name: String, age: Int, salary: Float) : Employee(name, age, salary) {
    fun doProgram() {
        println("Programming is my passion.\n")
    }
}

class Salesman(name: String, age: Int, salary: Float) : Employee(name, age, salary) {
    fun fieldwork() {
        println("Travelling is my hobby.")
    }
}

fun main(args: Array<String>) {
    var obj1=Programmer("Ashu",25,40000f)
    obj1.doProgram()
    var obj2=Salesman("Ajay",24,30000f)
    obj2.fieldwork()
}
 