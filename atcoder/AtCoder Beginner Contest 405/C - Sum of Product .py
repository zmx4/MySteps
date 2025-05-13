n = int(input())

a = list(map(int, input().split()))

presum = 0
ans = 0

for x in a:
	ans += x * presum
	presum += x

print(ans)