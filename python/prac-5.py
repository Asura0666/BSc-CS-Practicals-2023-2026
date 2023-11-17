#5.1)write a program to find the average of first N numbers...

n = int(input("Enter the value of the n: "))
i=1
sum = 0
while i<=n:
  sum += i
  i += 1
avg = sum / n
print(f"Average of first {n} numbers: {avg}")

#5.2)write a program to print the multiplication of table of any numbers...

n = int(input("Enter the number: "))
i=1
while i < 11:
  print(n,"x",i,"=",n*i)
  i += 1

#5.3)write a program to find factorial of given numbers...

n = int(input("Enter number: "))
fact = 1
i = 1
while i <= n:
  fact = fact * i
  i += 1
print(f"factorial of a {n} is: {fact}")

#5.4)write a program to print the reverse of a number...

n = int(input("Enter a number: "))
rev = 0
while n > 0:
  rev = rev * 10 + n % 10
  n = int(n / 10)
print(f"Reversed of {n} is: {rev}")

#5.5)write a program to find the sum of 5 digits numbers...

n = int(input("Enter a number: "))
sum = 0
while n > 0:
  sum = sum + n % 10
  n = int(n / 10)
print(f"Sum of 5 digits numbers: {sum}")