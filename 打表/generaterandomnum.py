import random
a,b = map(int, input().split())
l1 = []
l2 = []
for i in range(a):
	l1.append(random.randint(1, 10000000))
l1 = sorted(l1)

for i in range(b):
	l2.append(random.randint(1, 10000000))
l2 = sorted(l2)

print(a, b)
for i in range(a):
	print(l1[i], end=' ')
print()
for i in range(b):
	print(l2[i], end=' ')
print()