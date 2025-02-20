def cal(n : int) -> int:
	if n == 1:
		return 1
	return cal(n - 1) * n % 1000000007

if __name__ == '__main__':
	a = int(input())
	print(cal(a))