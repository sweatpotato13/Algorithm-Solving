def binary_search(s, e):
    target = e
    while True:
        mid = (s + e) // 2
        if (mid ** 2) == target:
            return mid
        if mid ** 2 > target:
            e = mid
        elif mid ** 2 < target:
            s = mid

N = int(input())
print(binary_search(1, N))