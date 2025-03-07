n = int(input())
ans = int(1)
ans2 = int(1)
for i in range(2, n + 1):
	ans *= i
	ans2+=ans
print(ans2)