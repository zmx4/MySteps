a,b,c,d=map(int,input().split())
maxNum=max(a,b,c,d)
minNum=min(a,b,c,d)
print(abs(a+b+c+d-maxNum-minNum-maxNum-minNum))