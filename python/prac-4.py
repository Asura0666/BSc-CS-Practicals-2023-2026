# 4.1)find largest number...
a = int(input("\nEnter a number: "))
b = int(input("\nEnter a number: "))
if a > b:
  print(f"\n{a} is greater than {b}")
elif a < b:
  print(f"\n{b} is greater than {a}")
else :
  print(f"\n{a} is equal to {b}")

# 4.2)check number is even or odd
n = int(input("Enter a number: "))
if n % 2 == 0:
  print(f"\n{n} is even")
else:
  print(f"\n{n} is odd")

# 4.3)check number is positive or negative
m = int(input("Enter a number: "))
if m > 0:
  print("its positive number")
elif m == 0:
  print("its zero")
else:
  print("its negative number")

# 4.4)check person is eligible for voting or not...
age = int(input("Enter a age: "))
if age < 18:
  print("You are not eligible for voting")
else:
  print("You are eligible for voting")

# 4.5)check number is divisible by 7 or not...
n = int(input("Enter a number: "))
if n % 7 == 0:
  print(f"\n{n} is divisible by 7")
else:
  print(f"\n{n} is not divisible by 7")

# 4.6) check number is multiple of 5 if yes then say hello otherwise bye
n = int(input("Enter a number: "))
if n % 5 == 0:
  print("Hello")
else:
  print("Bye")

# 4.7)taking number from 1 to 7 and printing day like 1 for monday...
n = int(input("Enter a number: "))
if n == 1:
  print("Monday")
elif n == 2:
  print("Tuesday")
elif n == 3:
  print("Wednesday")
elif n == 4:
  print("Thursday")
elif n == 5:
  print("Friday")
elif n == 6:
  print("Saturday")
else:
  print("Sunday")

# 4.8)take number from 1 to 12 and print month like 1 for january...
n = int(input("Enter a number: "))
if n == 1:
  print("January")
elif n == 2:
  print("February")
elif n == 3:
  print("March")
elif n == 4:
  print("April")
elif n == 5:
  print("May")
elif n == 6:
  print("June")
elif n == 7:
  print("July")
elif n == 8:
  print("August")
elif n == 9:
  print("September")
elif n == 10:
  print("October")
elif n == 11:
  print("November")
elif n == 12:
  print("December")

# 4.9) take 3 inputs and find largest among them using if else and logical operators
a = int(input("Enter a number: "))
b = int(input("Enter a number: "))
c = int(input("Enter a number: "))

if a > b and a > c:
  print(f"\n{a} is the largest number")
elif b > a and b > c:
  print(f"\n{b} is the largest number")
elif c > a and c > b:
  print(f"\n{c} is the largest number")
else:
  print("numbers are equal")

if a > b:
  if a > c:
    print(f"\n{a} is the largest number")
  else: 
    print(f"\n{c} is the largest number")
elif b > a:
  if b > c:
    print(f"\n{b} is the largest number")
  else:
    print(f"\n{c} is the largest number")

# 4.10) check triangle is possible or not...
a = int(input("Enter a number: "))
b = int(input("Enter b number: "))
c = int(input("Enter c number: "))
if a+b > c and b+c > a and a+c > b:
  print("Triangle is possible")
else: 
  print("Triangle is not possible")

# 4.11) check pythagoras triplet is possible or not...
a = int(input("Enter a number: "))
b = int(input("Enter b number: "))
c = int(input("Enter a number: "))
if a+b > c or b+c > a or a+c > b:
  print("Pythagoras triplet is possible")
else:
  print("Pythagoras triplet is not possible")

# 4.12) persentage problem %
n = int(input("Enter a persentage: "))
if n > 90 and n <= 100:
  print("A")
elif n > 80 and n <= 90:
  print("B")
elif n > 70 and n <= 80:
  print("C")
elif n <= 70:
  print("D")

# 4.13) gross salary problem...
a = int(input("Enter a base salary: "))
if a < 1500:
  HRA = 0.1 * a
  DA = 0.25 * a
  print(f"base salary is: {a}")
  print(f"HRA is: {HRA}")
  print(f"DA is: {DA}")
  print(f"Gross salary is: {a + HRA + DA}")
else:
  HRA = 500
  DA = .5 * a
  print(f"base salary is: {a}")
  print(f"HRA is: {HRA}")
  print(f"DA is: {DA}")
  print(f"Gross salary is: {a + HRA + DA}")

# 4.14)find division of student based on persentage...
a = int(input("Enter a percentage: "))
if a >= 60:
  print("First Division...")
elif a >= 50 and a <= 59:
  print("Second Division")
elif a >= 40 and a <= 49:
  print("Third Division")


