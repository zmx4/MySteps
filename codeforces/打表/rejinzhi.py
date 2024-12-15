for i in range(1, 1000):
	#print(i, bin(i))
	a = bin(i)
	cnt = 0
	for j in a:
		cnt+=1
	if(cnt%2==1):
		print(i, bin(i))