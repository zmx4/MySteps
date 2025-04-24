n,k = map(int, input().split())

l = []
for i in range(k):
	l.append(1)

for i in range(k,n+1):
	l.append(l[i-1] + l[i- 2])

print(l[n])