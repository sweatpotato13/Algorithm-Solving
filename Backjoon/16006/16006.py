# https://www.acmicpc.net/problem/16006

n = int(input())
p = 0
q = 1
for i in range(1, n+1):
    q = q * i
for i in range(1, n+1):
    p = p + (q // i)
for i in range(2, n+1):
    while p % i == 0 and q % i == 0:
        p = p // i
        q = q // i

print(p)
print(q)