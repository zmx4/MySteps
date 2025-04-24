n,k = map(int, input().split())

mod = 10**9

cnt = k

a = [1 for i in range(n+1)]
for i in range(k, n+1):
	a[i]=cnt
	cnt -= a[i-k]
	cnt += a[i]
	cnt%=mod

print(a[n])