n = int(input())

islogined = False
error = int(0)
while n > 0:
	n -= 1
	a = input()
	if a == "login":
		islogined = True
	elif a == "logout":
		islogined = False
	elif a == "public":
		continue
	elif a == "private":
		if islogined:
			continue
		else:
			error += 1

print(error)