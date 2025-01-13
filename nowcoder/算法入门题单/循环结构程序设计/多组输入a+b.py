import sys
for line in sys.stdin:
    try:
        a, b = map(int, line.split())
        print(a + b)
    except ValueError:
        pass