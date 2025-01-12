n=int(input())
sum=int(0)
for i in range(1,n+1):
	if(i%2==1):
		sum+=i
	else:
		sum-=i
print(sum)