n, m, x = map(int, input().split())
a = list(map(int, input().split()))
a.append(x)
a.sort()
idx = a.index(x)
print(min(len(a[:idx]), len(a[idx+1:])))