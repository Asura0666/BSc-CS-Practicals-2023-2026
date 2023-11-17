#7.1) Find factorial of a number by function...

def FindFactorial(n) :
  fact = 1
  for i in range(1,n+1):
    fact *= i
  print(f"factorial of {n} is: {fact}")

n = int(input("Enter a number: "))
FindFactorial(n)

#7.2) print fibonacci series upto 21 by function...

def PrintFibSeries():
  a = 0
  b = 1
  print(a)
  print(b)
  for i in range (1,20):
    c = a + b
    a = b
    b = c
    print(c)
PrintFibSeries()

#7.3) swap two numbers by function...

def Swap(a,b):
  print(f"Before swaping numbers a = {a} and b = {b}")
  t = a
  a = b
  b = t
  print(f"After swaping numbers a = {a} and b = {b}")
n1 = int(input("Enter 1st number: "))
n2 = int(input("Enter 2nd number: "))
Swap(n1,n2)

#7.4) To Convert min into sec by function...

def CovertMinToSec(min):
  sec = 60 * min
  print(f"{min} Minutes to {sec} seconds")

min = int(input("Enter minutes: "))
CovertMinToSec(min)

#7.5) To reverse the digit of the numbers by function...

def Reverse(n):
  rev = 0
  while n > 0:
    rem = n % 10
    rev = rev * 10 + rem
    n = int(n / 10)
  print(f"Reverse of numbers: {rev} ")

n = int(input("Enter a number: "))
Reverse(n)