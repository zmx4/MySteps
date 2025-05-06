import random
import sys
from collections import deque

def main():
    data = sys.stdin.read().split()
    m, n, k = map(int, data[:3])
    idx = 3
    safe = [False] * m
    for _ in range(n):
        x = int(data[idx]); idx += 1
        if 0 <= x < m:
            safe[x] = True

    G = [[] for _ in range(m)]
    for _ in range(k):
        u = int(data[idx]); v = int(data[idx+1])
        idx += 2
        if 0 <= u < m and 0 <= v < m:
            G[u].append(v)
            G[v].append(u)

    s = int(data[idx]); d = int(data[idx+1])

    if not (0 <= d < m and safe[d]):
        print(f"The city {d} is not safe!")
        return

    visited = [False] * m
    dq = deque()
    if 0 <= s < m and safe[s]:
        visited[s] = True
        dq.append(s)

    while dq:
        u = dq.popleft()
    main()