a = int(input())

x = 0
for i in range(1, a + 1):
	x ^= i
	print(x,i)