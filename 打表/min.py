def calc(n:int):
    unique = set()
    minN = 2
    maxN = int(n)
    
    for a in range(minN, maxN):
        for b in range(minN, maxN):
            unique.add(a ** b)
    
    return len(unique)

if __name__ == "__main__":
	for i in range(3, 102):
		print(i-2, calc(i))
	print(calc(10000))
