a = [1,2,3,4]
b = ["a", "b", "c", "d", "e", "f"]

#Access the elements

print(a[0])
print(a[2])
print(b[-1])
print(b[1:4])
print(b[2:])

#Adding elements
a.append(30)
print(a)
a.extend(b)
print(a)
a.insert(0,777)
print(a)

#Removing elements

del a[0]
print(a)
a.remove(3)
print(a)

#iterating through elements

for i in a:
  print(i)
for i in b:
  print(i)

print(len(a))
print(len(b))