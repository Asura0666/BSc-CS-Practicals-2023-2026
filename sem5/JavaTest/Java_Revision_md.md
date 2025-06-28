## Program 1
```
class Prog01 {
    public static void main(String args[]) {
        System.out.println("Kirti College");
    }
}
```

## Program 2
```
class Prog02 {
    public static void main(String args[]) {
        int n, s, c;
        n = Integer.parseInt(args[0]);
        s = n * n;
        c = n * n * n;
        System.out.println("Square of " + n + " is = " + s);
        System.out.println("Cube of " + n + " is = " + c);
    }
}
```

## Program 3
```
class Prog03 {
    public static void main(String args[]) {
        double n, a;
        n = Double.parseDouble(args[0]);
        a = 3.14 * n;
        System.out.println("Area of circle with radius " + n + " is " + a);
    }
}
```

## Program 4
```
class Prog04 {
    public static void main(String args[]) {
        double a, b, c, average;
        a = Double.parseDouble(args[0]);
        b = Double.parseDouble(args[1]);
        c = Double.parseDouble(args[2]);
        average = (a + b + c) / 3;
        System.out.println("Average = " + average);
    }
}
```

## Program 5
```
class Prog05 {
    public static void main(String args[]) {
        double n, h, m;
        n = Double.parseDouble(args[0]);
        h = n / 60;
        m = n % 60;
        System.out.println(h + " hours " + m + " minutes");
    }
}
```

# Program 6
```
class Prog06 {
    public static void main(String args[]) {
        double a, b, add, sub, multi, div;
        a = Double.parseDouble(args[0]);
        b = Double.parseDouble(args[1]);
        add = a + b;
        sub = a - b;
        multi = a * b;
        div = a / b;
        System.out.println("Addition = " + add);
        System.out.println("Subtraction = " + sub);
        System.out.println("Multiplication = " + multi);
        System.out.println("Division = " + div);
    }
}
```

# Program 7
```
class Prog07 {
    public static void main(String args[]) {
        double n;
        n = Double.parseDouble(args[0]);
        if (n % 2 == 0) {
            System.out.println("The number is even");
        } else {
            System.out.println("The number is odd");
        }
    }
}
```

## Program 8
```
class Prog08 {
    public static void main(String args[]) {
        double n;
        n = Double.parseDouble(args[0]);
        if (n % 5 == 0) {
            System.out.println("The number " + n + " is a multiple of 5");
        } else {
            System.out.println("The number " + n + " is not a multiple of 5");
        }
    }
}
```

## Program 9
```
class Prog09 {
    public static void main(String args[]) {
        double a, b;
        a = Double.parseDouble(args[0]);
        b = Double.parseDouble(args[1]);
        if (a > b) {
            System.out.println("The " + a + " is greater than " + b);
        } else {
            System.out.println("The " + b + " is greater than " + a);
        }
    }
}
```

## Program 10
```
class Prog10 {
    public static void main(String args[]) {
        double m;
        m = Double.parseDouble(args[0]);
        if (m >= 75) {
            System.out.println("You got O grade");
        } else if (m <= 74 && m >= 60) {
            System.out.println("You got A grade");
        } else if (m <= 59 && m >= 50) {
            System.out.println("You got B grade");
        } else if (m <= 49 && m >= 40) {
            System.out.println("You got C grade");
        } else {
            System.out.println("You failed");
        }
    }
}
```

## Program 11
```
class Prog11 {
    public static void main(String args[]) {
        double a, b, c;
        a = Double.parseDouble(args[0]);
        b = Double.parseDouble(args[1]);
        c = Double.parseDouble(args[2]);

        if (a > b && a > c) {
            System.out.print("a is greater");
        } else if (b > a && b > c) {
            System.out.print("b is greater");
        } else if (c > a && c > b) {
            System.out.print("c is greater");
        }
    }
}
```

## Program 12
```
class Prog12 {
    public static void main(String args[]) {
        int a = Integer.parseInt(args[0]);

        if (a == 1)
            System.out.println("Monday");
        else if (a == 2)
            System.out.println("Tuesday");
        else if (a == 3)
            System.out.println("Wednesday");
        else if (a == 4)
            System.out.println("Thursday");
        else if (a == 5)
            System.out.println("Friday");
        else if (a == 6)
            System.out.println("Saturday");
        else if (a == 7)
            System.out.println("Sunday");
    }
}
```

## Program 13
```
class Prog13 {
    public static void main(String args[]) {
        double n, i, sum = 0;
        n = Double.parseDouble(args[0]);
        i = 1;

        while (i <= n) {
            sum = sum + i;
            i = i + 1;
        }

        System.out.println("Summation is " + sum);
    }
}
```

## Program 14
```
class Prog14 {
    public static void main(String args[]) {
        double n, i, div, add = 1;
        n = Double.parseDouble(args[0]);
        i = 1;

        while (i <= n) {
            div = 1 / i;
            add = add + div;
            i++;
        }

        System.out.println("Add is " + add);
    }
}
```

## Program 15
```
class Prog15 {
    public static void main(String args[]) {
        double i, fact, n;
        n = Double.parseDouble(args[0]);
        i = 1;
        fact = 1;

        do {
            fact = fact * i;
            i++;
        } while (i <= n);

        System.out.println("Factorial of " + n + " is " + fact);
    }
}
```

## Program 16
```
class Prog16 {
    public static void main(String args[]) {
        double m, n, i;
        m = Double.parseDouble(args[0]);
        n = Double.parseDouble(args[1]);
        i = m;

        do {
            if (i % 7 == 0) {
                System.out.println(i);
            }
            i++;
        } while (i <= n);
    }
}
```

## Program 17
```
class Prog17 {
    public static void main(String args[]) {
        int n, i, m;
        n = Integer.parseInt(args[0]);

        for (i = 1; i <= 10; i++) {
            m = i * n;
            System.out.println(n + " x " + i + " = " + m);
        }
    }
}
```

## Program 18
```
class Prog18 {
    public static void main(String args[]) {
        int n, i, sum = 0, rem = 0;
        n = Integer.parseInt(args[0]);

        for (i = 1; i <= 5; i++) {
            rem = n % 10;
            sum = sum + rem;
            n = n / 10;
        }

        System.out.println("Sum of 5 digit number is " + sum);
    }
}
```

## Program 19
```
class Prog19 {
    public static void main(String args[]) {
        int i, j;

        for (i = 11; i <= 20; i++) {
            for (j = 1; j <= 10; j++) {
                System.out.println(i + " x " + j + " = " + (i * j));
            }
        }
    }
}
```

## Program 20
```
class Prog20 {
    public static void main(String args[]) {
        double n, i, j, div, add = 0, fact;
        n = Double.parseDouble(args[0]);

        for (i = 1; i < n; i++) {
            fact = 1;

            for (j = 1; j <= i; j++) {
                fact = fact * j;
            }

            div = 1 / fact;
            add = add + div;
        }

        System.out.println("Series is " + add);
    }
}
```

## Program 21
```
class prog21 {
    public static void main(String args[]) {
        int n = Integer.parseInt(args[0]);
        switch(n) {
            case 1: System.out.println("mon"); break;
            case 2: System.out.println("theusday"); break;
            case 3: System.out.println("wednesday"); break;
            case 4: System.out.println("thusday"); break;
            case 5: System.out.println("friday"); break;
            case 6: System.out.println("saturday"); break;
            case 7: System.out.println("sunday"); break;
            default: System.out.println("error message"); break;
        }
    }
}
```

## Program 22
```
class prog22 {
    public static void main(String args[]) {
        System.out.println("enter character");
        char c = System.console().readLine().charAt(0);
        switch(c) {
            case 'V': System.out.println("voilet"); break;
            case 'I': System.out.println("indigo"); break;
            case 'B': System.out.println("blue"); break;
            case 'G': System.out.println("green"); break;
            case 'Y': System.out.println("yellow"); break;
            case 'O': System.out.println("orange"); break;
            case 'R': System.out.println("red"); break;
            default: System.out.println("no valid color"); break;
        }
    }
}
```

## Program 23
```
class rect35 {
    double length, width;
    double area() {
        return length * width;
    }
}

class prog23 {
    public static void main(String args[]) {
        rect35 r = new rect35();
        r.length = Double.parseDouble(args[0]);
        r.width = Double.parseDouble(args[1]);
        double ans = r.area();
        System.out.println("area of rect = " + ans);
    }
}
```

## Program 24
```
class box35 {
    double l, w, b;

    box35() {
        this.l = 0;
        this.w = 0;
        this.b = 0;
    }

    box35(double ll, double ww, double bb) {
        this.l = ll;
        this.w = ww;
        this.b = bb;
    }

    double vol() {
        return l * w * b;
    }
}

class prog24 {
    public static void main(String args[]) {
        box35 b1 = new box35();
        box35 b2 = new box35(10, 15, 20);
        double ans1 = b1.vol();
        double ans2 = b2.vol();
        System.out.println("vol1 = " + ans1);
        System.out.println("vol2 = " + ans2);
    }
}
```

## Program 25
```
class stud35 {
    String cy;
    int r;

    stud35(String a, int b) {
        this.cy = a;
        this.r = b;
    }

    void display() {
        System.out.println("current year " + cy + " rollnumber " + r);
    }
}

class prog25 {
    public static void main(String args[]) {
        stud35 b1 = new stud35("sy", 35);
        stud35 b2 = new stud35("ty", 23);
        b1.display();
        b2.display();
    }
}
```

## Program 26
```
class Mathoperation {
    public static float mul(float x, float y) {
        return x * y;
    }

    public static float div(float x, float y) {
        return x / y;
    }
}

class Prog26 {
    public static void main(String args[]) {
        float a = Mathoperation.mul(4.3f, 5.7f);
        float b = Mathoperation.div(a, 2);
        System.out.println("a = " + a);
        System.out.println("b = " + b);
    }
}
```

## Program 27
```
class nesting {
    int m, n;

    nesting(int x, int y) {
        m = x;
        n = y;
    }

    int largest() {
        if (m > n)
            return m;
        else
            return n;
    }

    void display() {
        int large = largest();
        System.out.println("Largest Number Is " + large);
    }
}

class Prog27 {
    public static void main(String args[]) {
        nesting n = new nesting(70, 30);
        n.display();
    }
}
```

## Program 28
```
class TestPerimeter {
    double length, width;

    TestPerimeter() {
        this.length = 0;
        this.width = 0;
    }

    TestPerimeter(double l, double w) {
        this.length = l;
        this.width = w;
    }

    double cal() {
        return (2 * (length + width));
    }
}

class Prog28 {
    public static void main(String args[]) {
        TestPerimeter p1 = new TestPerimeter();
        TestPerimeter p2 = new TestPerimeter(10.5, 7.8);
        double ans1 = p1.cal();
        double ans2 = p2.cal();
        System.out.println(ans1);
        System.out.println(ans2);
    }
}
```

## Program 29
```
class TestOverload {
    public static void add(int a, int b) {
        System.out.println("Sum is " + (a + b));
    }

    public static void add(int a, int b, int c) {
        System.out.println("Sum is " + (a + b + c));
    }

    public static void add(float x, float y) {
        System.out.println("Sum is " + (x + y));
    }

    public static void add(float x, float y, float z) {
        System.out.println("Sum is " + (x + y + z));
    }
}

class Prog29 {
    public static void main(String args[]) {
        TestOverload.add(4, 5);
        TestOverload.add(4, 5, 6);
        TestOverload.add(7.1f, 8.1f);
        TestOverload.add(7.1f, 8.1f, 9.1f);
    }
}
```

## Program 30
```
abstract class Shape {
    double len, breadth, radius;
    abstract double area();
}

class Rect extends Shape {
    double area() {
        return len * breadth;
    }
}

class Circle extends Shape {
    double area() {
        return 3.142 * (radius * radius);
    }
}

class Prog30 {
    public static void main(String args[]) {
        Rect r1 = new Rect();
        r1.len = 79;
        r1.breadth = 24;
        double ar = r1.area();

        Circle c1 = new Circle();
        c1.radius = 63;
        double ac = c1.area();

        System.out.println("Area of Rectangle = " + ar);
        System.out.println("Area of Circle = " + ac);
    }
}
```
