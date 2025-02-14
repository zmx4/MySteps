def is_prime(n):
    if n <= 1:
        return False
    if n == 2:
        return True
    if n % 2 == 0:
        return False
    for i in range(3, int(n**0.5) + 1, 2):
        if n % i == 0:
            return False
    return True

def find():
    primes = [i for i in range(2, 100000) if is_prime(i)]
    for i in range(len(primes)):
        for j in range(i + 1, len(primes)):
            p, q = primes[i], primes[j]
            k = q - p - 1
            if k > 0 and (p * q) == k * (p + q):
                return p, q, k
    return None

result = find()
if result:
    p, q, k = result
    print(f" p = {p}, q = {q}  k = {k}")
else:
    print("None.")