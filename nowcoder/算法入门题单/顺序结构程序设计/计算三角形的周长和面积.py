a,b,c=map(int,input().split())
if a+b>c and a+c>b and b+c>a:
	print('circumference=%.2f area=%.2f'%(a+b+c,((a+b+c)/2*((a+b+c)/2-a)*((a+b+c)/2-b)*((a+b+c)/2-c))**0.5))