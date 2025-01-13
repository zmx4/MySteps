import sys

def isLeapYear(year):
	if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
		return True
	else:
		return False
ans = int(0)
for line in sys.stdin:
	try:
		y, m, x = map(int, line.split())
		# 每月天数
		month_days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
		if isLeapYear(y):
			month_days[1] = 29
		days = month_days[m-1]
		digit = str(x)
		count_res = 0
		for d in range(1, days+1):
			# 构造 "YYYY-MM-DD"
			date_str = f"{y:04d}-{m:02d}-{d:02d}"
			count_res += date_str.count(digit)
		print(count_res)


	except ValueError:
		pass