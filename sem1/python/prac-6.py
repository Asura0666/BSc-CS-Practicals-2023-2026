#6.1)write a program to find the sum of first number...

# n = int(input("Enter the number: "))
# sum = 0
# for i in range(1,n+1):
#   sum = sum + i
# print(f"Sum of first number: {sum}")

#6.2)write a program to generate fibonacci series from 1 to 15...

# a = 0
# b = 1
# print(a)
# print(b)
# for i in range(1,15):
#   c = a + b
#   print(c)
#   a = b
#   b = c

#6.3)write a program to print the multiplication table from 2 to 10...

for i in range(2,11):
  print("Table of ",i)
  for j in range(1,11):
    print(i,"x",j,"=",i*j)
